/*
 * This file is part of RaceFlight.
 *
 * RaceFlight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RaceFlight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RaceFlight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>

#include "platform.h"

#include "common/axis.h"

#include "drivers/sensor.h"
#include "drivers/compass.h"
#include "drivers/compass_hmc5883l.h"
#include "drivers/gpio.h"
#include "drivers/light_led.h"

#include "sensors/boardalignment.h"
#include "config/runtime_config.h"
#include "config/config.h"

#include "sensors/sensors.h"
#include "sensors/compass.h"

#ifdef NAZE
#include "hardware_revision.h"
#endif

mag_t mag;                   

extern uint32_t currentTime; 

int16_t magADC[XYZ_AXIS_COUNT];
sensor_align_e magAlign = 0;
#ifdef MAG
static uint8_t magInit = 0;

void compassInit(void)
{
    
    LED1_ON;
    mag.init();
    LED1_OFF;
    magInit = 1;
}

#define COMPASS_UPDATE_FREQUENCY_10HZ (1000 * 100)

void updateCompass(flightDynamicsTrims_t *magZero)
{
    static uint32_t nextUpdateAt, tCal = 0;
    static flightDynamicsTrims_t magZeroTempMin;
    static flightDynamicsTrims_t magZeroTempMax;
    uint32_t axis;

    if ((int32_t)(currentTime - nextUpdateAt) < 0)
        return;

    nextUpdateAt = currentTime + COMPASS_UPDATE_FREQUENCY_10HZ;

    mag.read(magADC);
    alignSensors(magADC, magADC, magAlign);

    if (STATE(CALIBRATE_MAG)) {
        tCal = nextUpdateAt;
        for (axis = 0; axis < 3; axis++) {
            magZero->raw[axis] = 0;
            magZeroTempMin.raw[axis] = magADC[axis];
            magZeroTempMax.raw[axis] = magADC[axis];
        }
        DISABLE_STATE(CALIBRATE_MAG);
    }

    if (magInit) {              
        magADC[X] -= magZero->raw[X];
        magADC[Y] -= magZero->raw[Y];
        magADC[Z] -= magZero->raw[Z];
    }

    if (tCal != 0) {
        if ((nextUpdateAt - tCal) < 30000000) {    
            LED0_TOGGLE;
            for (axis = 0; axis < 3; axis++) {
                if (magADC[axis] < magZeroTempMin.raw[axis])
                    magZeroTempMin.raw[axis] = magADC[axis];
                if (magADC[axis] > magZeroTempMax.raw[axis])
                    magZeroTempMax.raw[axis] = magADC[axis];
            }
        } else {
            tCal = 0;
            for (axis = 0; axis < 3; axis++) {
                magZero->raw[axis] = (magZeroTempMin.raw[axis] + magZeroTempMax.raw[axis]) / 2; 
            }

            saveConfigAndNotify();
        }
    }
}
#endif

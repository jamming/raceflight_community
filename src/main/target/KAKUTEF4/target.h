/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#define TARGET_BOARD_IDENTIFIER "KTF4"

#define CONFIG_START_FLASH_ADDRESS (0x08060000)
#define CONFIG_START_BACK_ADDRESS (0x08060000)
#define CONFIG_BLACKBOX_DEVICE 1
#define CONFIG_SERIALRX_PROVIDER SERIALRX_SBUS
#define CONFIG_FEATURE_RX_SERIAL
#define CONFIG_FEATURE_ONESHOT125
#define CONFIG_MSP_PORT 2
#define CONFIG_RX_SERIAL_PORT 3

#define USBD_PRODUCT_STRING "KakuteF4"
#define USBD_SERIALNUMBER_STRING "0x8020000"

#define ESC_HEX

#define LED0 PB5
#define LED1 PB4

#define BEEPER PC9
#define BEEPER_INVERTED

#define INVERTER PC6
#define INVERTER_USART USART6

#define MPU9250_CS_PIN        PC4
#define MPU9250_SPI_INSTANCE  SPI1

#define ACC
#define USE_ACC_MPU9250
#define USE_ACC_SPI_MPU9250
#define ACC_MPU9250_ALIGN CW270_DEG

#define GYRO
#define SLOW_SPI_DOWN
#define USE_GYRO_MPU9250
#define USE_GYRO_SPI_MPU9250
#define GYRO_MPU9250_ALIGN CW270_DEG


//#define BARO
//#define USE_BARO_MS5611

#define M25P16_CS_PIN         PB3
#define M25P16_SPI_INSTANCE   SPI3

#define USE_FLASH_TOOLS
#define USE_FLASHFS
#define USE_FLASH_M25P16

#define USABLE_TIMER_CHANNEL_COUNT 7

// MPU9250 interrupt
//#define DEBUG_MPU_DATA_READY_INTERRUPT
#define USE_MPU_DATA_READY_SIGNAL
#define ENSURE_MPU_DATA_READY_IS_LOW
#define EXTI_CALLBACK_HANDLER_COUNT 1 // MPU data ready
#define MPU_INT_EXTI PC5
#define USE_EXTI

#define USE_VCP
#define VBUS_SENSING_PIN PA8

#define USE_USART1
#define USART1_RX_PIN PA10
#define USART1_TX_PIN PA9
#define USART1_AHB1_PERIPHERALS RCC_AHB1Periph_DMA2

#define USE_USART3
#define USART3_RX_PIN PB11
#define USART3_TX_PIN PB10
#define USART3_AHB1_PERIPHERALS RCC_AHB1Periph_DMA1

#define USE_USART6
#define USART6_RX_PIN PC7
#define USART6_TX_PIN PC6 //inverter
#define USART6_AHB1_PERIPHERALS RCC_AHB1Periph_DMA2

#define SERIAL_PORT_COUNT 4

#define SERIALRX_DMA			

#ifdef SERIALRX_DMA
	#define USE_USART1_RX_DMA		
	#define USE_USART3_RX_DMA		
	#define USE_USART6_RX_DMA		
#endif

#define ESC_1WIRE

#define USE_SPI

#define USE_SPI_DEVICE_1 //MPU9250
#define SPI1_NSS_PIN            PC4
#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PA7

#define USE_SPI_DEVICE_3 //dataflash
#define SPI3_NSS_PIN            PB3
#define SPI3_SCK_PIN            PC10
#define SPI3_MISO_PIN           PC11
#define SPI3_MOSI_PIN           PC12

#define USE_I2C
#define I2C_DEVICE (I2CDEV_1)

#define BOARD_HAS_VOLTAGE_DIVIDER
#define USE_ADC
#define VBAT_ADC_PIN           PC3
#define VBAT_ADC_CHANNEL       ADC_Channel_13

#define CURRENT_METER_ADC_PIN  PC2
#define CURRENT_METER_ADC_CHANNEL   ADC_Channel_12

#define RSSI_ADC_PIN                PC1
#define RSSI_ADC_CHANNEL            ADC_Channel_11

#define WS2812_LED
#define WS2812_LED_TIMER_CH2
#define WS2812_LED_GPIO             GPIOA
#define WS2812_LED_PIN              GPIO_Pin_1
#define WS2812_LED_PINSOURCE        GPIO_PinSource1
#define WS2812_LED_PERIPH           RCC_AHB1Periph_GPIOA
#define WS2812_LED_TIM              TIM5
#define WS2812_LED_TIM_AF           GPIO_AF_TIM5
#define WS2812_LED_TIM_PERIPH       RCC_APB1Periph_TIM5
#define WS2812_LED_DMA_CH           DMA_Channel_6
#define WS2812_LED_DMA_ST           DMA1_Stream4
#define WS2812_LED_DMA_IRQ          DMA1_Stream4_IRQn
#define WS2812_LED_DMA_FLAG         DMA_FLAG_TCIF4
#define WS2812_LED_DMA_IRQ_HANDLER  DMA1_Stream4_IRQHandler
#define WS2812_LED_DMA_PERIPH       RCC_AHB1Periph_DMA1


#define BLACKBOX
#define TELEMETRY
#define SERIAL_RX

#define USE_SERVOS
#define USE_CLI

#define USE_QUATERNION

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff

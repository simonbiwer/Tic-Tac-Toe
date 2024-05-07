//*******************************************************************
/*!
\file   PinConfig.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_PIN_CONFIG_H
#define _HW_PIN_CONFIG_H

//*******************************************************************
/*!
\class cHwPinConfig

\brief Port pin configuration

This class provides methods to
- configure GPIO mode, type, pull-up/-down, speed and alternate 
  function
- connect a GPIO to an alternate function


*/
class cHwPinConfig
{
  public:
    //---------------------------------------------------------------
    /*! Pin mode configuration
    */
    typedef enum
    {
      // MODER
      INPUT          = 0x0000, //!< Input mode
      OUTPUT         = 0x0001, //!< Output mode
      ALTERNATE_FUNC = 0x0002, //!< Alternate function
      ANALOG         = 0x0003, //!< Analog I/O
      
      // OTYPER
      PUSH_PULL      = 0x0000, //!< Enable push-pull
      OPEN_DRAIN     = 0x0010, //!< Disable push-pull
      
      //PUPDR
      NO_PUPD        = 0x0000, //!< No pull-up or pull down 
      PULL_UP        = 0x0100, //!< Enable pull-up
      PULL_DOWN      = 0x0200, //!< Enable pull-down

      //OSPEEDR
      LOW_SPEED      = 0x0000, //!< Low speed mode
      MEDIUM_SPEED   = 0x1000, //!< Medium speed mode
      FAST_SPEED     = 0x2000, //!< Fast speed mode
      HIGH_SPEED     = 0x3000  //!< High speed mode
      
    } MODE;

    //---------------------------------------------------------------
    typedef enum
    {
          ADC12_IN0 = 1,
          ADC12_IN1,
          ADC12_IN10,
          ADC12_IN11,
          ADC12_IN12,
          ADC12_IN13,
          ADC12_IN14,
          ADC12_IN15,
          ADC12_IN2,
          ADC12_IN3,
          ADC12_IN4,
          ADC12_IN5,
          ADC12_IN6,
          ADC12_IN7,
          ADC12_IN8,
          ADC12_IN9,
          DAC_OUT1,
          DAC_OUT2,
          I2C1_SCL,
          I2C1_SDA,
          I2C1_SMBAl,
          I2C2_SCL,
          I2C2_SDA,
          I2C2_SMBAl,
          I2S2_CK,
          I2S2_MCK,
          I2S2_SD,
          I2S2_WS,
          I2S3_CK,
          I2S3_MCK,
          I2S3_SD,
          I2S3_WS,
          SPI_MOSI,
          SPI1_MISO,
          SPI1_MOSI,
          SPI1_NSS,
          SPI1_SCK,
          SPI2_MISO,
          SPI2_MOSI,
          SPI2_NSS,
          SPI2_SCK,
          SPI3_MISO,
          SPI3_MOSI,
          SPI3_NSS,
          SPI3_SCK,
          TIM10_CH1,
          TIM11_CH1,
          TIM2_CH1_ETR,
          TIM2_CH2,
          TIM2_CH3,
          TIM2_CH4,
          TIM3_CH1,
          TIM3_CH2,
          TIM3_CH3,
          TIM3_CH4,
          TIM3_ETR,
          TIM4_CH1,
          TIM4_CH2,
          TIM4_CH3,
          TIM4_CH4,
          TIM9_CH1,
          TIM9_CH2,
          USART1_CK,
          USART1_CTS,
          USART1_RTS,
          USART1_RX,
          USART1_TX,
          USART2_CK,
          USART2_CTS,
          USART2_RTS,
          USART2_RX,
          USART2_TX,
          USART3_CK,
          USART3_CTS,
          USART3_RTS,
          USART3_RX,
          USART3_TX,
          USBDM,
          USBDP,
    } Function;

    //---------------------------------------------------------------
    /*! Pin function mapping
        
        Maps an alternate function to a port pin and alternate function ID.
       'ADC12_IN0_PA_0' means: The function 'ADC12_IN0' is mapped to pin PA0
    */
    typedef enum
    {
          ADC12_IN0_PA_0     = (ADC12_IN0   <<16)|(0<<12)|( 0<<4)|( 0<<0),  //!< .
          ADC12_IN1_PA_1     = (ADC12_IN1   <<16)|(0<<12)|( 1<<4)|( 0<<0),  //!< .
          ADC12_IN10_PC_0    = (ADC12_IN10  <<16)|(2<<12)|( 0<<4)|( 0<<0),  //!< .
          ADC12_IN11_PC_1    = (ADC12_IN11  <<16)|(2<<12)|( 1<<4)|( 0<<0),  //!< .
          ADC12_IN12_PC_2    = (ADC12_IN12  <<16)|(2<<12)|( 2<<4)|( 0<<0),  //!< .
          ADC12_IN13_PC_3    = (ADC12_IN13  <<16)|(2<<12)|( 3<<4)|( 0<<0),  //!< .
          ADC12_IN14_PC_4    = (ADC12_IN14  <<16)|(2<<12)|( 4<<4)|( 0<<0),  //!< .
          ADC12_IN15_PC_5    = (ADC12_IN15  <<16)|(2<<12)|( 5<<4)|( 0<<0),  //!< .
          ADC12_IN2_PA_2     = (ADC12_IN2   <<16)|(0<<12)|( 2<<4)|( 0<<0),  //!< .
          ADC12_IN3_PA_3     = (ADC12_IN3   <<16)|(0<<12)|( 3<<4)|( 0<<0),  //!< .
          ADC12_IN4_PA_4     = (ADC12_IN4   <<16)|(0<<12)|( 4<<4)|( 0<<0),  //!< .
          ADC12_IN5_PA_5     = (ADC12_IN5   <<16)|(0<<12)|( 5<<4)|( 0<<0),  //!< .
          ADC12_IN6_PA_6     = (ADC12_IN6   <<16)|(0<<12)|( 6<<4)|( 0<<0),  //!< .
          ADC12_IN7_PA_7     = (ADC12_IN7   <<16)|(0<<12)|( 7<<4)|( 0<<0),  //!< .
          ADC12_IN8_PB_0     = (ADC12_IN8   <<16)|(1<<12)|( 0<<4)|( 0<<0),  //!< .
          ADC12_IN9_PB_1     = (ADC12_IN9   <<16)|(1<<12)|( 1<<4)|( 0<<0),  //!< .
          DAC_OUT1_PA_4      = (DAC_OUT1    <<16)|(0<<12)|( 4<<4)|( 0<<0),  //!< .
          DAC_OUT2_PA_5      = (DAC_OUT2    <<16)|(0<<12)|( 5<<4)|( 0<<0),  //!< .
          I2C1_SCL_PB_6      = (I2C1_SCL    <<16)|(1<<12)|( 6<<4)|( 4<<0),  //!< .
          I2C1_SCL_PB_8      = (I2C1_SCL    <<16)|(1<<12)|( 8<<4)|( 4<<0),  //!< .
          I2C1_SDA_PB_7      = (I2C1_SDA    <<16)|(1<<12)|( 7<<4)|( 4<<0),  //!< .
          I2C1_SDA_PB_9      = (I2C1_SDA    <<16)|(1<<12)|( 9<<4)|( 4<<0),  //!< .
          I2C1_SMBAl_PB_5    = (I2C1_SMBAl  <<16)|(1<<12)|( 5<<4)|( 4<<0),  //!< .
          I2C2_SCL_PB_10     = (I2C2_SCL    <<16)|(1<<12)|(10<<4)|( 4<<0),  //!< .
          I2C2_SDA_PB_11     = (I2C2_SDA    <<16)|(1<<12)|(11<<4)|( 4<<0),  //!< .
          I2C2_SMBAl_PB_12   = (I2C2_SMBAl  <<16)|(1<<12)|(12<<4)|( 4<<0),  //!< .
          I2S2_CK_PB_13      = (I2S2_CK     <<16)|(1<<12)|(13<<4)|( 5<<0),  //!< .
          I2S2_MCK_PC_6      = (I2S2_MCK    <<16)|(2<<12)|( 6<<4)|( 5<<0),  //!< .
          I2S2_SD_PB_15      = (I2S2_SD     <<16)|(1<<12)|(15<<4)|( 5<<0),  //!< .
          I2S2_WS_PB_12      = (I2S2_WS     <<16)|(1<<12)|(12<<4)|( 5<<0),  //!< .
          I2S3_CK_PB_3       = (I2S3_CK     <<16)|(1<<12)|( 3<<4)|( 6<<0),  //!< .
          I2S3_CK_PC_10      = (I2S3_CK     <<16)|(2<<12)|(10<<4)|( 6<<0),  //!< .
          I2S3_MCK_PC_7      = (I2S3_MCK    <<16)|(2<<12)|( 7<<4)|( 6<<0),  //!< .
          I2S3_SD_PB_5       = (I2S3_SD     <<16)|(1<<12)|( 5<<4)|( 6<<0),  //!< .
          I2S3_SD_PC_12      = (I2S3_SD     <<16)|(2<<12)|(12<<4)|( 6<<0),  //!< .
          I2S3_WS_PA_4       = (I2S3_WS     <<16)|(0<<12)|( 4<<4)|( 6<<0),  //!< .
          I2S3_WS_PA_15      = (I2S3_WS     <<16)|(0<<12)|(15<<4)|( 6<<0),  //!< .
          SPI_MOSI_PA_12     = (SPI_MOSI    <<16)|(0<<12)|(12<<4)|( 5<<0),  //!< .
          SPI1_MISO_PA_6     = (SPI1_MISO   <<16)|(0<<12)|( 6<<4)|( 5<<0),  //!< .
          SPI1_MISO_PA_11    = (SPI1_MISO   <<16)|(0<<12)|(11<<4)|( 5<<0),  //!< .
          SPI1_MISO_PB_4     = (SPI1_MISO   <<16)|(1<<12)|( 4<<4)|( 5<<0),  //!< .
          SPI1_MOSI_PA_7     = (SPI1_MOSI   <<16)|(0<<12)|( 7<<4)|( 5<<0),  //!< .
          SPI1_MOSI_PB_5     = (SPI1_MOSI   <<16)|(1<<12)|( 5<<4)|( 5<<0),  //!< .
          SPI1_NSS_PA_4      = (SPI1_NSS    <<16)|(0<<12)|( 4<<4)|( 5<<0),  //!< .
          SPI1_NSS_PA_15     = (SPI1_NSS    <<16)|(0<<12)|(15<<4)|( 5<<0),  //!< .
          SPI1_SCK_PA_5      = (SPI1_SCK    <<16)|(0<<12)|( 5<<4)|( 5<<0),  //!< .
          SPI1_SCK_PB_3      = (SPI1_SCK    <<16)|(1<<12)|( 3<<4)|( 5<<0),  //!< .
          SPI2_MISO_PB_14    = (SPI2_MISO   <<16)|(1<<12)|(14<<4)|( 5<<0),  //!< .
          SPI2_MOSI_PB_15    = (SPI2_MOSI   <<16)|(1<<12)|(15<<4)|( 5<<0),  //!< .
          SPI2_NSS_PB_12     = (SPI2_NSS    <<16)|(1<<12)|(12<<4)|( 5<<0),  //!< .
          SPI2_SCK_PB_13     = (SPI2_SCK    <<16)|(1<<12)|(13<<4)|( 5<<0),  //!< .
          SPI3_MISO_PB_4     = (SPI3_MISO   <<16)|(1<<12)|( 4<<4)|( 6<<0),  //!< .
          SPI3_MISO_PC_11    = (SPI3_MISO   <<16)|(2<<12)|(11<<4)|( 6<<0),  //!< .
          SPI3_MOSI_PB_5     = (SPI3_MOSI   <<16)|(1<<12)|( 5<<4)|( 6<<0),  //!< .
          SPI3_MOSI_PC_12    = (SPI3_MOSI   <<16)|(2<<12)|(12<<4)|( 6<<0),  //!< .
          SPI3_NSS_PA_4      = (SPI3_NSS    <<16)|(0<<12)|( 4<<4)|( 6<<0),  //!< .
          SPI3_NSS_PA_15     = (SPI3_NSS    <<16)|(0<<12)|(15<<4)|( 6<<0),  //!< .
          SPI3_SCK_PB_3      = (SPI3_SCK    <<16)|(1<<12)|( 3<<4)|( 6<<0),  //!< .
          SPI3_SCK_PC_10     = (SPI3_SCK    <<16)|(2<<12)|(10<<4)|( 6<<0),  //!< .
          TIM10_CH1_PA_6     = (TIM10_CH1   <<16)|(0<<12)|( 6<<4)|( 3<<0),  //!< .
          TIM10_CH1_PB_8     = (TIM10_CH1   <<16)|(1<<12)|( 8<<4)|( 3<<0),  //!< .
          TIM10_CH1_PB_12    = (TIM10_CH1   <<16)|(1<<12)|(12<<4)|( 3<<0),  //!< .
          TIM11_CH1_PA_7     = (TIM11_CH1   <<16)|(0<<12)|( 7<<4)|( 3<<0),  //!< .
          TIM11_CH1_PB_9     = (TIM11_CH1   <<16)|(1<<12)|( 9<<4)|( 3<<0),  //!< .
          TIM11_CH1_PB_15    = (TIM11_CH1   <<16)|(1<<12)|(15<<4)|( 3<<0),  //!< .
          TIM2_CH1_ETR_PA_0  = (TIM2_CH1_ETR<<16)|(0<<12)|( 0<<4)|( 1<<0),  //!< .
          TIM2_CH1_ETR_PA_5  = (TIM2_CH1_ETR<<16)|(0<<12)|( 5<<4)|( 1<<0),  //!< .
          TIM2_CH1_ETR_PA_15 = (TIM2_CH1_ETR<<16)|(0<<12)|(15<<4)|( 1<<0),  //!< .
          TIM2_CH2_PA_1      = (TIM2_CH2    <<16)|(0<<12)|( 1<<4)|( 1<<0),  //!< .
          TIM2_CH2_PB_3      = (TIM2_CH2    <<16)|(1<<12)|( 3<<4)|( 1<<0),  //!< .
          TIM2_CH3_PA_2      = (TIM2_CH3    <<16)|(0<<12)|( 2<<4)|( 1<<0),  //!< .
          TIM2_CH3_PB_10     = (TIM2_CH3    <<16)|(1<<12)|(10<<4)|( 1<<0),  //!< .
          TIM2_CH4_PA_3      = (TIM2_CH4    <<16)|(0<<12)|( 3<<4)|( 1<<0),  //!< .
          TIM2_CH4_PB_11     = (TIM2_CH4    <<16)|(1<<12)|(11<<4)|( 1<<0),  //!< .
          TIM3_CH1_PA_6      = (TIM3_CH1    <<16)|(0<<12)|( 6<<4)|( 2<<0),  //!< .
          TIM3_CH1_PB_4      = (TIM3_CH1    <<16)|(1<<12)|( 4<<4)|( 2<<0),  //!< .
          TIM3_CH1_PC_6      = (TIM3_CH1    <<16)|(2<<12)|( 6<<4)|( 2<<0),  //!< .
          TIM3_CH2_PA_7      = (TIM3_CH2    <<16)|(0<<12)|( 7<<4)|( 2<<0),  //!< .
          TIM3_CH2_PB_5      = (TIM3_CH2    <<16)|(1<<12)|( 5<<4)|( 2<<0),  //!< .
          TIM3_CH2_PC_7      = (TIM3_CH2    <<16)|(2<<12)|( 7<<4)|( 2<<0),  //!< .
          TIM3_CH3_PB_0      = (TIM3_CH3    <<16)|(1<<12)|( 0<<4)|( 2<<0),  //!< .
          TIM3_CH3_PC_8      = (TIM3_CH3    <<16)|(2<<12)|( 8<<4)|( 2<<0),  //!< .
          TIM3_CH4_PB_1      = (TIM3_CH4    <<16)|(1<<12)|( 1<<4)|( 2<<0),  //!< .
          TIM3_CH4_PC_9      = (TIM3_CH4    <<16)|(2<<12)|( 9<<4)|( 2<<0),  //!< .
          TIM3_ETR_PD_2      = (TIM3_ETR    <<16)|(3<<12)|( 2<<4)|( 2<<0),  //!< .
          TIM4_CH1_PB_6      = (TIM4_CH1    <<16)|(1<<12)|( 6<<4)|( 2<<0),  //!< .
          TIM4_CH2_PB_7      = (TIM4_CH2    <<16)|(1<<12)|( 7<<4)|( 2<<0),  //!< .
          TIM4_CH3_PB_8      = (TIM4_CH3    <<16)|(1<<12)|( 8<<4)|( 2<<0),  //!< .
          TIM4_CH4_PB_9      = (TIM4_CH4    <<16)|(1<<12)|( 9<<4)|( 2<<0),  //!< .
          TIM9_CH1_PA_2      = (TIM9_CH1    <<16)|(0<<12)|( 2<<4)|( 3<<0),  //!< .
          TIM9_CH1_PB_13     = (TIM9_CH1    <<16)|(1<<12)|(13<<4)|( 3<<0),  //!< .
          TIM9_CH2_PA_3      = (TIM9_CH2    <<16)|(0<<12)|( 3<<4)|( 3<<0),  //!< .
          TIM9_CH2_PB_14     = (TIM9_CH2    <<16)|(1<<12)|(14<<4)|( 3<<0),  //!< .
          USART1_CK_PA_8     = (USART1_CK   <<16)|(0<<12)|( 8<<4)|( 7<<0),  //!< .
          USART1_CTS_PA_11   = (USART1_CTS  <<16)|(0<<12)|(11<<4)|( 7<<0),  //!< .
          USART1_RTS_PA_12   = (USART1_RTS  <<16)|(0<<12)|(12<<4)|( 7<<0),  //!< .
          USART1_RX_PA_10    = (USART1_RX   <<16)|(0<<12)|(10<<4)|( 7<<0),  //!< .
          USART1_RX_PB_7     = (USART1_RX   <<16)|(1<<12)|( 7<<4)|( 7<<0),  //!< .
          USART1_TX_PA_9     = (USART1_TX   <<16)|(0<<12)|( 9<<4)|( 7<<0),  //!< .
          USART1_TX_PB_6     = (USART1_TX   <<16)|(1<<12)|( 6<<4)|( 7<<0),  //!< .
          USART2_CK_PA_4     = (USART2_CK   <<16)|(0<<12)|( 4<<4)|( 7<<0),  //!< .
          USART2_CTS_PA_0    = (USART2_CTS  <<16)|(0<<12)|( 0<<4)|( 7<<0),  //!< .
          USART2_RTS_PA_1    = (USART2_RTS  <<16)|(0<<12)|( 1<<4)|( 7<<0),  //!< .
          USART2_RX_PA_3     = (USART2_RX   <<16)|(0<<12)|( 3<<4)|( 7<<0),  //!< .
          USART2_TX_PA_2     = (USART2_TX   <<16)|(0<<12)|( 2<<4)|( 7<<0),  //!< .
          USART3_CK_PB_12    = (USART3_CK   <<16)|(1<<12)|(12<<4)|( 7<<0),  //!< .
          USART3_CK_PC_12    = (USART3_CK   <<16)|(2<<12)|(12<<4)|( 7<<0),  //!< .
          USART3_CTS_PB_13   = (USART3_CTS  <<16)|(1<<12)|(13<<4)|( 7<<0),  //!< .
          USART3_RTS_PB_14   = (USART3_RTS  <<16)|(1<<12)|(14<<4)|( 7<<0),  //!< .
          USART3_RX_PB_11    = (USART3_RX   <<16)|(1<<12)|(11<<4)|( 7<<0),  //!< .
          USART3_RX_PC_11    = (USART3_RX   <<16)|(2<<12)|(11<<4)|( 7<<0),  //!< .
          USART3_TX_PB_10    = (USART3_TX   <<16)|(1<<12)|(10<<4)|( 7<<0),  //!< .
          USART3_TX_PC_10    = (USART3_TX   <<16)|(2<<12)|(10<<4)|( 7<<0),  //!< .
          USBDM_PA_11        = (USBDM       <<16)|(0<<12)|(11<<4)|(10<<0),  //!< .
          USBDP_PA_12        = (USBDP       <<16)|(0<<12)|(12<<4)|(10<<0),  //!< .
      END_OF_TABLE = 0
    } MAP;

  public:
    //---------------------------------------------------------------
    /*! Set configuration of a GPIO
        \param gpio  Pointer to function register. 
                     Use predefined constant \a 'GPIOx'
        \param pinId GPIO pin number (0,...15)
        \param mode  Selected pin mode. 
                     Use constants defined in \b MODE, the constants
                     can be combined using bit-or operations. 
        \param af    Number of selected alternate function. This 
                     parameter is used only, when \b ALTERNATE_FUNC 
                     is selected.
    */
    static void set( GPIO_TypeDef *gpio, 
                     BYTE          pinId, 
                     DWORD mode, 
                     BYTE          af = 0 );

    //---------------------------------------------------------------
    /*! Set GPIO to alternate function
    
        A GPIO can be connected to a onchip peripheral module. The 
        enum \b 'Function' lists all peripheral signals which can be 
        connected to a GPIO. This method uses a application specific 
        mapping \b 'table'. The application has to define 
        this \b 'table' on global scope. The entries of this table 
        define on which port pin a peripheral signal is mapped. 
        \param func  Selected peripheral signal as alternate function
        \param mode  Selected pin mode. 
                     Use constants defined in \b MODE, the constants
                     can be combined using bit-or operations. 
        \return 
                - true, if \b func is included in \b table
                - false otherwise    
    */
    static bool set( Function func,
                     DWORD    mode = 0 );

  public:
    //---------------------------------------------------------------
    /*! This table defines how an alternate function is mapped to the 
        port pins. It must be defined by application software. The 
        last entry of this table has to be \b 'END_OF_TABLE'.
    */
    static MAP table[];

}; //cHwPinConfig

#endif

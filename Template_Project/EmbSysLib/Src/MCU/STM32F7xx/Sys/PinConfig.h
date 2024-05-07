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
    /*! Alternate functions of the MCU
    */
		
		// TODO
		// PB7 bis PB15 fehlen!!!
		// ----------------------
    typedef enum
    {
					ADC3_IN8,
					ADC3_IN12,
          CAN1_RX,
          CAN1_TX,
          CAN2_RX,
          CAN2_TX,
          CAN3_RX,
          CAN3_TX,
          DAC_OUT1,
          DAC_OUT2,
          DCMDIOS_MDC,
          DCMI_D0,
          DCMI_D1,
          DCMI_D10,
          DCMI_D11,
          DCMI_D12,
          DCMI_D13,
          DCMI_D2,
          DCMI_D3,
          DCMI_D4,
          DCMI_D5,
          DCMI_D6,
          DCMI_D7,
          DCMI_D8,
          DCMI_D9,
          DCMI_HSYNC,
          DCMI_PIXCLK,
          DCMI_VSYNC,
          DFSDM1_CKIN0,
          DFSDM1_CKIN1,
          DFSDM1_CKIN2,
          DFSDM1_CKIN3,
          DFSDM1_CKIN4,
          DFSDM1_CKIN5,
          DFSDM1_CKIN6,
          DFSDM1_CKIN7,
          DFSDM1_CKOUT,
          DFSDM1_DATAIN0,
          DFSDM1_DATAIN1,
          DFSDM1_DATAIN2,
          DFSDM1_DATAIN3,
          DFSDM1_DATAIN4,
          DFSDM1_DATAIN5,
          DFSDM1_DATAIN6,
          DFSDM1_DATAIN7,
          DFSDM1_DATIN1,
          DFSDM1_DATIN4,
          DFSDM1_DATIN5,
          DSI_TE,
          ETH_M,
          ETH_MDIO,
          ETH_MII_COL,
          ETH_MII_CRS,
          ETH_MII_RX_CLK,
          ETH_MII_RX_DV,
          ETH_MII_RX_ER,
          ETH_MII_RXD0,
          ETH_MII_RXD1,
          ETH_MII_RXD2,
          ETH_MII_RXD3,
          ETH_MII_TX_CLK,
          ETH_MII_TX_EN,
          ETH_MII_TXD0,
          ETH_MII_TXD1,
          ETH_MII_TXD2,
          ETH_MII_TXD3,
          ETH_PPS_OUT,
          ETH_RMII_CRS_DV,
          ETH_RMII_REF_CLK,
          ETH_RMII_RXD0,
          ETH_RMII_RXD1,
          ETH_RMII_TX_EN,
          ETH_RMII_TXD0,
          ETH_RMII_TXD1,
          FMC_A0,
          FMC_A1,
          FMC_A10,
          FMC_A11,
          FMC_A12,
          FMC_A13,
          FMC_A14,
          FMC_A15,
          FMC_A16,
          FMC_A17,
          FMC_A18,
          FMC_A19,
          FMC_A2,
          FMC_A20,
          FMC_A21,
          FMC_A22,
          FMC_A23,
          FMC_A24,
          FMC_A25,
          FMC_A3,
          FMC_A4,
          FMC_A5,
          FMC_A6,
          FMC_A7,
          FMC_A8,
          FMC_A9,
          FMC_ALE,
          FMC_BA0,
          FMC_BA1,
          FMC_CLE,
          FMC_CLK,
          FMC_D0,
          FMC_D1,
          FMC_D10,
          FMC_D11,
          FMC_D12,
          FMC_D13,
          FMC_D14,
          FMC_D15,
          FMC_D16,
          FMC_D17,
          FMC_D18,
          FMC_D19,
          FMC_D2,
          FMC_D20,
          FMC_D21,
          FMC_D22,
          FMC_D23,
          FMC_D24,
          FMC_D25,
          FMC_D26,
          FMC_D27,
          FMC_D28,
          FMC_D29,
          FMC_D3,
          FMC_D30,
          FMC_D31,
          FMC_D4,
          FMC_D5,
          FMC_D6,
          FMC_D7,
          FMC_D8,
          FMC_D9,
          FMC_INT,
          FMC_NBL0,
          FMC_NBL1,
          FMC_NBL2,
          FMC_NBL3,
          FMC_NCE,
          FMC_NE1,
          FMC_NE2,
          FMC_NE3,
          FMC_NE4,
          FMC_NOE,
          FMC_NWAIT,
          FMC_NWE,
          FMC_SDCKE0,
          FMC_SDCKE1,
          FMC_SDCLK,
          FMC_SDNCAS,
          FMC_SDNE0,
          FMC_SDNE1,
          FMC_SDNRAS,
          FMC_SDNWE,
          HDMICEC,
          I2C1_SCL,
					I2C1_SDA,
          I2C1_SMBA,
          I2C2_SCL,
          I2C2_SDA,
          I2C2_SMBA,
          I2C3_SCL,
          I2C3_SDA,
          I2C3_SMBA,
          I2C4_SCL,
          I2C4_SDA,
          I2C4_SMBA,
          I2S_CKIN,
          I2S1_CK,
          I2S1_MCK,
          I2S1_SD,
          I2S1_WS,
          I2S2_CK,
          I2S2_MCK,
          I2S2_SD,
          I2S2_WS,
          I2S3_CK,
          I2S3_MCK,
          I2S3_SD,
          I2S3_WS,
          JTCKSWCLK,
          JTDI,
          JTDO,
          JTMSSWDIO,
          LCD_B0,
          LCD_B1,
          LCD_B2,
          LCD_B3,
          LCD_B4,
          LCD_B5,
          LCD_B6,
          LCD_B7,
          LCD_CLK,
          LCD_DE,
          LCD_G0,
          LCD_G1,
          LCD_G2,
          LCD_G3,
          LCD_G4,
          LCD_G5,
          LCD_G6,
          LCD_G7,
          LCD_HSYNC,
          LCD_R0,
          LCD_R1,
          LCD_R2,
          LCD_R3,
          LCD_R4,
          LCD_R5,
          LCD_R6,
          LCD_R7,
          LCD_VSYNC,
          LPTIM1_ETR,
          LPTIM1_IN1,
          LPTIM1_IN2,
          LPTIM1_OUT,
          MCO1,
          MCO2,
          MDIOS_MDC,
          MDIOS_MDIO,
          NJTRST,
          OTG_FS_DM,
          OTG_FS_DP,
          OTG_FS_ID,
          OTG_FS_SOF,
          OTG_HS_SOF,
          OTG_HS_ULPI_CK,
          OTG_HS_ULPI_D0,
          OTG_HS_ULPI_D1,
          OTG_HS_ULPI_D2,
          OTG_HS_ULPI_D7,
          OTG_HS_ULPI_DIR,
          OTG_HS_ULPI_NXT,
          OTG_HS_ULPI_STP,
          QUADSPI_BK1_IO0,
          QUADSPI_BK1_IO1,
          QUADSPI_BK1_IO2,
          QUADSPI_BK1_IO3,
          QUADSPI_BK1_NCS,
          QUADSPI_BK2_IO0,
          QUADSPI_BK2_IO1,
          QUADSPI_BK2_IO2,
          QUADSPI_BK2_IO3,
          QUADSPI_BK2_NCS,
          QUADSPI_CLK,
          SAI1_FS_A,
          SAI1_FS_B,
          SAI1_MCLK_A,
          SAI1_MCLK_B,
          SAI1_SCK_A,
          SAI1_SCK_B,
          SAI1_SD_A,
          SAI1_SD_B,
          SAI2_FS_A,
          SAI2_FS_B,
          SAI2_MCK_A,
          SAI2_MCK_B,
          SAI2_SCK_A,
          SAI2_SCK_B,
          SAI2_SD_A,
          SAI2_SD_B,
          SDMMC_CK,
          SDMMC_CMD,
          SDMMC_D0,
          SDMMC_D1,
          SDMMC_D2,
          SDMMC_D3,
          SDMMC_D6,
          SDMMC_D7,
          SDMMC2_CK,
          SDMMC2_CMD,
          SDMMC2_D0,
          SDMMC2_D1,
          SDMMC2_D2,
          SDMMC2_D3,
          SDMMC2_D6,
          SDMMC2_D7,
          SPDIF_RX0,
          SPDIF_RX1,
          SPDIF_RX2,
          SPDIF_RX3,
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
          SPI4_MISO,
          SPI4_MOSI,
          SPI4_NSS,
          SPI4_SCK,
          SPI5_MISO,
          SPI5_MOSI,
          SPI5_NSS,
          SPI5_SCK,
          SPI6_MISO,
          SPI6_MOSI,
          SPI6_NSS,
          SPI6_SCK,
          TIM1_BKIN,
          TIM1_BKIN2,
          TIM1_CH1,
          TIM1_CH1N,
          TIM1_CH2,
          TIM1_CH2N,
          TIM1_CH3,
          TIM1_CH3N,
          TIM1_CH4,
          TIM1_ETR,
          TIM1_IN1,
          TIM10_CH1,
          TIM11_CH1,
          TIM12_CH1,
          TIM12_CH2,
          TIM13_CH1,
          TIM14_CH1,
          TIM2_CH1,
          TIM2_CH2,
          TIM2_CH3,
          TIM2_CH4,
          TIM2_ETR,
          TIM3_CH1,
          TIM3_CH2,
          TIM3_CH3,
          TIM3_CH4,
          TIM3_ETR,
          TIM4_CH1,
          TIM4_CH1LP,
          TIM4_CH2,
          TIM4_CH3,
          TIM4_CH4,
          TIM4_ETR,
          TIM5_CH1,
          TIM5_CH2,
          TIM5_CH3,
          TIM5_CH4,
          TIM8_BKIN,
          TIM8_BKIN2,
          TIM8_CH1,
          TIM8_CH1N,
          TIM8_CH2,
          TIM8_CH2N,
          TIM8_CH3,
          TIM8_CH3N,
          TIM8_CH4,
          TIM8_ETR,
          TIM9_CH1,
          TIM9_CH2,
          TRACECLK,
          TRACED0,
          TRACED1,
          TRACED2,
          TRACED3,
          TRACESWO,
          UART4_CTS,
          UART4_RTS,
          UART4_RX,
          UART4_TX,
          UART5_CTS,
          UART5_RTS,
          UART5_RX,
          UART5_TX,
          UART7_CTS,
          UART7_RTS,
          UART7_RX,
          UART7_TX,
          UART8_CTS,
          UART8_RTS,
          UART8_Rx,
          UART8_Tx,
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
          USART6_CK,
          USART6_CTS,
          USART6_RTS,
          USART6_RX,
          USART6_TX,
          
    } Function;

    //---------------------------------------------------------------
    /*! Pin function mapping
        
        Maps an alternate function to a port pin and alternate function ID.
       'ADC12_IN4_PA_4' means: The function 'ADC12_IN4' is mapped to pin PA4
    */
		// TODO
		// PB7 bis PB15 fehlen!!!
		// ----------------------
    typedef enum
    {
      // Key                  Function              Port     Pin     AF      
			ADC3_IN8_PF_10 = (ADC3_IN8<<16)|(5<<12)|( 10<<4)|( 0<<0),  //!< .
      ADC3_IN12_PC_2 = (ADC3_IN12<<16)|(2<<12)|( 2<<4)|( 0<<0),  //!< .
      CAN1_RX_PA_11 = (CAN1_RX<<16)|(0<<12)|(11<<4)|(9<<0),  //!< .
      CAN1_RX_PD_0 = (CAN1_RX<<16)|(3<<12)|(0<<4)|(9<<0),  //!< .
      CAN1_RX_PH_14 = (CAN1_RX<<16)|(7<<12)|(14<<4)|(9<<0),  //!< .
      CAN1_RX_PI_9 = (CAN1_RX<<16)|(8<<12)|(9<<4)|(9<<0),  //!< .
      CAN1_TX_PA_12 = (CAN1_TX<<16)|(0<<12)|(12<<4)|(9<<0),  //!< .
      CAN1_TX_PD_1 = (CAN1_TX<<16)|(3<<12)|(1<<4)|(9<<0),  //!< .
      CAN1_TX_PH_13 = (CAN1_TX<<16)|(7<<12)|(13<<4)|(9<<0),  //!< .
      CAN2_RX_PB_5 = (CAN2_RX<<16)|(1<<12)|(5<<4)|(9<<0),  //!< .
      CAN2_TX_PB_6 = (CAN2_TX<<16)|(1<<12)|(6<<4)|(9<<0),  //!< .
      CAN3_RX_PA_8 = (CAN3_RX<<16)|(0<<12)|(8<<4)|(11<<0),  //!< .
      CAN3_RX_PB_3 = (CAN3_RX<<16)|(1<<12)|(3<<4)|(11<<0),  //!< .
      CAN3_TX_PA_15 = (CAN3_TX<<16)|(0<<12)|(15<<4)|(11<<0),  //!< .
      CAN3_TX_PB_4 = (CAN3_TX<<16)|(1<<12)|(4<<4)|(11<<0),  //!< .
      DAC_OUT1_PA_4 = (DAC_OUT1<<16)|(0<<12)|(4<<4)|(0<<0),  //!< .
      DAC_OUT2_PA_5 = (DAC_OUT2<<16)|(0<<12)|(5<<4)|(0<<0),  //!< .
      DCMDIOS_MDC_PC_1 = (DCMDIOS_MDC<<16)|(2<<12)|(1<<4)|(12<<0),  //!< .
      DCMI_D0_PA_9 = (DCMI_D0<<16)|(0<<12)|(9<<4)|(13<<0),  //!< .
      DCMI_D0_PC_6 = (DCMI_D0<<16)|(2<<12)|(6<<4)|(13<<0),  //!< .
      DCMI_D0_PH_9 = (DCMI_D0<<16)|(7<<12)|(9<<4)|(13<<0),  //!< .
      DCMI_D1_PA_10 = (DCMI_D1<<16)|(0<<12)|(10<<4)|(13<<0),  //!< .
      DCMI_D1_PC_7 = (DCMI_D1<<16)|(2<<12)|(7<<4)|(13<<0),  //!< .
      DCMI_D1_PH_10 = (DCMI_D1<<16)|(7<<12)|(10<<4)|(13<<0),  //!< .
      DCMI_D10_PB_5 = (DCMI_D10<<16)|(1<<12)|(5<<4)|(13<<0),  //!< .
      DCMI_D10_PD_6 = (DCMI_D10<<16)|(3<<12)|(6<<4)|(13<<0),  //!< .
      DCMI_D10_PI_3 = (DCMI_D10<<16)|(8<<12)|(3<<4)|(13<<0),  //!< .
      DCMI_D11_PD_2 = (DCMI_D11<<16)|(3<<12)|(2<<4)|(13<<0),  //!< .
      DCMI_D11_PF_10 = (DCMI_D11<<16)|(5<<12)|(10<<4)|(13<<0),  //!< .
      DCMI_D11_PH_15 = (DCMI_D11<<16)|(7<<12)|(15<<4)|(13<<0),  //!< .
      DCMI_D12_PF_11 = (DCMI_D12<<16)|(5<<12)|(11<<4)|(13<<0),  //!< .
      DCMI_D12_PG_6 = (DCMI_D12<<16)|(6<<12)|(6<<4)|(13<<0),  //!< .
      DCMI_D13_PG_7 = (DCMI_D13<<16)|(6<<12)|(7<<4)|(13<<0),  //!< .
      DCMI_D13_PG_15 = (DCMI_D13<<16)|(6<<12)|(15<<4)|(13<<0),  //!< .
      DCMI_D13_PI_0 = (DCMI_D13<<16)|(8<<12)|(0<<4)|(13<<0),  //!< .
      DCMI_D2_PC_8 = (DCMI_D2<<16)|(2<<12)|(8<<4)|(13<<0),  //!< .
      DCMI_D2_PE_0 = (DCMI_D2<<16)|(4<<12)|(0<<4)|(13<<0),  //!< .
      DCMI_D2_PG_10 = (DCMI_D2<<16)|(6<<12)|(10<<4)|(13<<0),  //!< .
      DCMI_D2_PH_11 = (DCMI_D2<<16)|(7<<12)|(11<<4)|(13<<0),  //!< .
      DCMI_D3_PC_9 = (DCMI_D3<<16)|(2<<12)|(9<<4)|(13<<0),  //!< .
      DCMI_D3_PE_1 = (DCMI_D3<<16)|(4<<12)|(1<<4)|(13<<0),  //!< .
      DCMI_D3_PG_11 = (DCMI_D3<<16)|(6<<12)|(11<<4)|(13<<0),  //!< .
      DCMI_D3_PH_12 = (DCMI_D3<<16)|(7<<12)|(12<<4)|(13<<0),  //!< .
      DCMI_D4_PC_11 = (DCMI_D4<<16)|(2<<12)|(11<<4)|(13<<0),  //!< .
      DCMI_D4_PE_4 = (DCMI_D4<<16)|(4<<12)|(4<<4)|(13<<0),  //!< .
      DCMI_D4_PH_14 = (DCMI_D4<<16)|(7<<12)|(14<<4)|(13<<0),  //!< .
      DCMI_D5_PB_6 = (DCMI_D5<<16)|(1<<12)|(6<<4)|(13<<0),  //!< .
      DCMI_D5_PD_3 = (DCMI_D5<<16)|(3<<12)|(3<<4)|(13<<0),  //!< .
      DCMI_D5_PI_4 = (DCMI_D5<<16)|(8<<12)|(4<<4)|(13<<0),  //!< .
      DCMI_D6_PE_5 = (DCMI_D6<<16)|(4<<12)|(5<<4)|(13<<0),  //!< .
      DCMI_D6_PI_6 = (DCMI_D6<<16)|(8<<12)|(6<<4)|(13<<0),  //!< .
      DCMI_D7_PE_6 = (DCMI_D7<<16)|(4<<12)|(6<<4)|(13<<0),  //!< .
      DCMI_D7_PI_7 = (DCMI_D7<<16)|(8<<12)|(7<<4)|(13<<0),  //!< .
      DCMI_D8_PC_10 = (DCMI_D8<<16)|(2<<12)|(10<<4)|(13<<0),  //!< .
      DCMI_D8_PH_6 = (DCMI_D8<<16)|(7<<12)|(6<<4)|(13<<0),  //!< .
      DCMI_D8_PI_1 = (DCMI_D8<<16)|(8<<12)|(1<<4)|(13<<0),  //!< .
      DCMI_D9_PC_12 = (DCMI_D9<<16)|(2<<12)|(12<<4)|(13<<0),  //!< .
      DCMI_D9_PH_7 = (DCMI_D9<<16)|(7<<12)|(7<<4)|(13<<0),  //!< .
      DCMI_D9_PI_2 = (DCMI_D9<<16)|(8<<12)|(2<<4)|(13<<0),  //!< .
      DCMI_HSYNC_PA_4 = (DCMI_HSYNC<<16)|(0<<12)|(4<<4)|(13<<0),  //!< .
      DCMI_HSYNC_PH_8 = (DCMI_HSYNC<<16)|(7<<12)|(8<<4)|(13<<0),  //!< .
      DCMI_PIXCLK_PA_6 = (DCMI_PIXCLK<<16)|(0<<12)|(6<<4)|(13<<0),  //!< .
      DCMI_VSYNC_PG_9 = (DCMI_VSYNC<<16)|(6<<12)|(9<<4)|(13<<0),  //!< .
      DCMI_VSYNC_PI_5 = (DCMI_VSYNC<<16)|(8<<12)|(5<<4)|(13<<0),  //!< .
      DFSDM1_CKIN0_PC_0 = (DFSDM1_CKIN0<<16)|(2<<12)|(0<<4)|(3<<0),  //!< .
      DFSDM1_CKIN0_PD_4 = (DFSDM1_CKIN0<<16)|(3<<12)|(4<<4)|(6<<0),  //!< .
      DFSDM1_CKIN1_PB_2 = (DFSDM1_CKIN1<<16)|(1<<12)|(2<<4)|(10<<0),  //!< .
      DFSDM1_CKIN1_PC_2 = (DFSDM1_CKIN1<<16)|(2<<12)|(2<<4)|(3<<0),  //!< .
      DFSDM1_CKIN1_PD_7 = (DFSDM1_CKIN1<<16)|(3<<12)|(7<<4)|(6<<0),  //!< .
      DFSDM1_CKIN2_PC_4 = (DFSDM1_CKIN2<<16)|(2<<12)|(4<<4)|(3<<0),  //!< .
      DFSDM1_CKIN2_PE_8 = (DFSDM1_CKIN2<<16)|(4<<12)|(8<<4)|(6<<0),  //!< .
      DFSDM1_CKIN3_PC_6 = (DFSDM1_CKIN3<<16)|(2<<12)|(6<<4)|(7<<0),  //!< .
      DFSDM1_CKIN3_PD_8 = (DFSDM1_CKIN3<<16)|(3<<12)|(8<<4)|(3<<0),  //!< .
      DFSDM1_CKIN3_PE_5 = (DFSDM1_CKIN3<<16)|(4<<12)|(5<<4)|(10<<0),  //!< .
      DFSDM1_CKIN4_PC_1 = (DFSDM1_CKIN4<<16)|(2<<12)|(1<<4)|(10<<0),  //!< .
      DFSDM1_CKIN4_PD_6 = (DFSDM1_CKIN4<<16)|(3<<12)|(6<<4)|(3<<0),  //!< .
      DFSDM1_CKIN4_PE_11 = (DFSDM1_CKIN4<<16)|(4<<12)|(11<<4)|(6<<0),  //!< .
      DFSDM1_CKIN5_PC_10 = (DFSDM1_CKIN5<<16)|(2<<12)|(10<<4)|(3<<0),  //!< .
      DFSDM1_CKIN5_PE_13 = (DFSDM1_CKIN5<<16)|(4<<12)|(13<<4)|(6<<0),  //!< .
      DFSDM1_CKIN6_PD_0 = (DFSDM1_CKIN6<<16)|(3<<12)|(0<<4)|(3<<0),  //!< .
      DFSDM1_CKIN6_PF_14 = (DFSDM1_CKIN6<<16)|(5<<12)|(14<<4)|(6<<0),  //!< .
      DFSDM1_CKIN7_PD_1 = (DFSDM1_CKIN7<<16)|(3<<12)|(1<<4)|(6<<0),  //!< .
      DFSDM1_CKOUT_PB_0 = (DFSDM1_CKOUT<<16)|(1<<12)|(0<<4)|(6<<0),  //!< .
      DFSDM1_CKOUT_PC_2 = (DFSDM1_CKOUT<<16)|(2<<12)|(2<<4)|(6<<0),  //!< .
      DFSDM1_CKOUT_PD_3 = (DFSDM1_CKOUT<<16)|(3<<12)|(3<<4)|(3<<0),  //!< .
      DFSDM1_CKOUT_PD_10 = (DFSDM1_CKOUT<<16)|(3<<12)|(10<<4)|(3<<0),  //!< .
      DFSDM1_CKOUT_PE_9 = (DFSDM1_CKOUT<<16)|(4<<12)|(9<<4)|(6<<0),  //!< .
      DFSDM1_DATAIN0_PC_1 = (DFSDM1_DATAIN0<<16)|(2<<12)|(1<<4)|(3<<0),  //!< .
      DFSDM1_DATAIN0_PD_3 = (DFSDM1_DATAIN0<<16)|(3<<12)|(3<<4)|(6<<0),  //!< .
      DFSDM1_DATAIN1_PC_3 = (DFSDM1_DATAIN1<<16)|(2<<12)|(3<<4)|(3<<0),  //!< .
      DFSDM1_DATAIN1_PD_6 = (DFSDM1_DATAIN1<<16)|(3<<12)|(6<<4)|(10<<0),  //!< .
      DFSDM1_DATAIN2_PC_5 = (DFSDM1_DATAIN2<<16)|(2<<12)|(5<<4)|(3<<0),  //!< .
      DFSDM1_DATAIN2_PE_7 = (DFSDM1_DATAIN2<<16)|(4<<12)|(7<<4)|(6<<0),  //!< .
      DFSDM1_DATAIN3_PC_7 = (DFSDM1_DATAIN3<<16)|(2<<12)|(7<<4)|(7<<0),  //!< .
      DFSDM1_DATAIN3_PD_9 = (DFSDM1_DATAIN3<<16)|(3<<12)|(9<<4)|(3<<0),  //!< .
      DFSDM1_DATAIN3_PE_4 = (DFSDM1_DATAIN3<<16)|(4<<12)|(4<<4)|(10<<0),  //!< .
      DFSDM1_DATAIN4_PD_7 = (DFSDM1_DATAIN4<<16)|(3<<12)|(7<<4)|(3<<0),  //!< .
      DFSDM1_DATAIN4_PE_10 = (DFSDM1_DATAIN4<<16)|(4<<12)|(10<<4)|(6<<0),  //!< .
      DFSDM1_DATAIN5_PC_11 = (DFSDM1_DATAIN5<<16)|(2<<12)|(11<<4)|(3<<0),  //!< .
      DFSDM1_DATAIN5_PE_12 = (DFSDM1_DATAIN5<<16)|(4<<12)|(12<<4)|(6<<0),  //!< .
      DFSDM1_DATAIN6_PD_1 = (DFSDM1_DATAIN6<<16)|(3<<12)|(1<<4)|(3<<0),  //!< .
      DFSDM1_DATAIN6_PF_13 = (DFSDM1_DATAIN6<<16)|(5<<12)|(13<<4)|(6<<0),  //!< .
      DFSDM1_DATAIN7_PD_0 = (DFSDM1_DATAIN7<<16)|(3<<12)|(0<<4)|(6<<0),  //!< .
      DFSDM1_DATIN1_PB_1 = (DFSDM1_DATIN1<<16)|(1<<12)|(1<<4)|(6<<0),  //!< .
      DFSDM1_DATIN4_PC_0 = (DFSDM1_DATIN4<<16)|(2<<12)|(0<<4)|(6<<0),  //!< .
      DFSDM1_DATIN5_PB_6 = (DFSDM1_DATIN5<<16)|(1<<12)|(6<<4)|(6<<0),  //!< .
      DSI_TE_PJ_2 = (DSI_TE<<16)|(9<<12)|(2<<4)|(13<<0),  //!< .
      ETH_M_PC_1 = (ETH_M<<16)|(2<<12)|(1<<4)|(11<<0),  //!< .
      ETH_MDIO_PA_2 = (ETH_MDIO<<16)|(0<<12)|(2<<4)|(11<<0),  //!< .
      ETH_MII_COL_PA_3 = (ETH_MII_COL<<16)|(0<<12)|(3<<4)|(11<<0),  //!< .
      ETH_MII_COL_PH_3 = (ETH_MII_COL<<16)|(7<<12)|(3<<4)|(11<<0),  //!< .
      ETH_MII_CRS_PA_0 = (ETH_MII_CRS<<16)|(0<<12)|(0<<4)|(11<<0),  //!< .
      ETH_MII_CRS_PH_2 = (ETH_MII_CRS<<16)|(7<<12)|(2<<4)|(11<<0),  //!< .
      ETH_MII_RX_CLK_PA_1 = (ETH_MII_RX_CLK<<16)|(0<<12)|(1<<4)|(11<<0),  //!< .
      ETH_MII_RX_DV_PA_7 = (ETH_MII_RX_DV<<16)|(0<<12)|(7<<4)|(11<<0),  //!< .
      ETH_MII_RX_ER_PI_10 = (ETH_MII_RX_ER<<16)|(8<<12)|(10<<4)|(11<<0),  //!< .
      ETH_MII_RXD0_PC_4 = (ETH_MII_RXD0<<16)|(2<<12)|(4<<4)|(11<<0),  //!< .
      ETH_MII_RXD1_PC_5 = (ETH_MII_RXD1<<16)|(2<<12)|(5<<4)|(11<<0),  //!< .
      ETH_MII_RXD2_PB_0 = (ETH_MII_RXD2<<16)|(1<<12)|(0<<4)|(11<<0),  //!< .
      ETH_MII_RXD2_PH_6 = (ETH_MII_RXD2<<16)|(7<<12)|(6<<4)|(11<<0),  //!< .
      ETH_MII_RXD3_PB_1 = (ETH_MII_RXD3<<16)|(1<<12)|(1<<4)|(11<<0),  //!< .
      ETH_MII_RXD3_PH_7 = (ETH_MII_RXD3<<16)|(7<<12)|(7<<4)|(11<<0),  //!< .
      ETH_MII_TX_CLK_PC_3 = (ETH_MII_TX_CLK<<16)|(2<<12)|(3<<4)|(11<<0),  //!< .
      ETH_MII_TX_EN_PG_11 = (ETH_MII_TX_EN<<16)|(6<<12)|(11<<4)|(11<<0),  //!< .
      ETH_MII_TXD0_PG_13 = (ETH_MII_TXD0<<16)|(6<<12)|(13<<4)|(11<<0),  //!< .
      ETH_MII_TXD1_PG_14 = (ETH_MII_TXD1<<16)|(6<<12)|(14<<4)|(11<<0),  //!< .
      ETH_MII_TXD2_PC_2 = (ETH_MII_TXD2<<16)|(2<<12)|(2<<4)|(11<<0),  //!< .
      ETH_MII_TXD3_PE_2 = (ETH_MII_TXD3<<16)|(4<<12)|(2<<4)|(11<<0),  //!< .
      ETH_PPS_OUT_PB_5 = (ETH_PPS_OUT<<16)|(1<<12)|(5<<4)|(11<<0),  //!< .
      ETH_PPS_OUT_PG_8 = (ETH_PPS_OUT<<16)|(6<<12)|(8<<4)|(11<<0),  //!< .
      ETH_RMII_CRS_DV_PA_7 = (ETH_RMII_CRS_DV<<16)|(0<<12)|(7<<4)|(11<<0),  //!< .
      ETH_RMII_REF_CLK_PA_1 = (ETH_RMII_REF_CLK<<16)|(0<<12)|(1<<4)|(11<<0),  //!< .
      ETH_RMII_RXD0_PC_4 = (ETH_RMII_RXD0<<16)|(2<<12)|(4<<4)|(11<<0),  //!< .
      ETH_RMII_RXD1_PC_5 = (ETH_RMII_RXD1<<16)|(2<<12)|(5<<4)|(11<<0),  //!< .
      ETH_RMII_TX_EN_PG_11 = (ETH_RMII_TX_EN<<16)|(6<<12)|(11<<4)|(11<<0),  //!< .
      ETH_RMII_TXD0_PG_13 = (ETH_RMII_TXD0<<16)|(6<<12)|(13<<4)|(11<<0),  //!< .
      ETH_RMII_TXD1_PG_14 = (ETH_RMII_TXD1<<16)|(6<<12)|(14<<4)|(11<<0),  //!< .
      FMC_A0_PF_0 = (FMC_A0<<16)|(5<<12)|(0<<4)|(12<<0),  //!< .
      FMC_A1_PF_1 = (FMC_A1<<16)|(5<<12)|(1<<4)|(12<<0),  //!< .
      FMC_A10_PG_0 = (FMC_A10<<16)|(6<<12)|(0<<4)|(12<<0),  //!< .
      FMC_A11_PG_1 = (FMC_A11<<16)|(6<<12)|(1<<4)|(12<<0),  //!< .
      FMC_A12_PG_2 = (FMC_A12<<16)|(6<<12)|(2<<4)|(12<<0),  //!< .
      FMC_A13_PG_3 = (FMC_A13<<16)|(6<<12)|(3<<4)|(12<<0),  //!< .
      FMC_A14_PG_4 = (FMC_A14<<16)|(6<<12)|(4<<4)|(12<<0),  //!< .
      FMC_A15_PG_5 = (FMC_A15<<16)|(6<<12)|(5<<4)|(12<<0),  //!< .
      FMC_A16_PD_11 = (FMC_A16<<16)|(3<<12)|(11<<4)|(12<<0),  //!< .
      FMC_A17_PD_12 = (FMC_A17<<16)|(3<<12)|(12<<4)|(12<<0),  //!< .
      FMC_A18_PD_13 = (FMC_A18<<16)|(3<<12)|(13<<4)|(12<<0),  //!< .
      FMC_A19_PE_3 = (FMC_A19<<16)|(4<<12)|(3<<4)|(12<<0),  //!< .
      FMC_A2_PF_2 = (FMC_A2<<16)|(5<<12)|(2<<4)|(12<<0),  //!< .
      FMC_A20_PE_4 = (FMC_A20<<16)|(4<<12)|(4<<4)|(12<<0),  //!< .
      FMC_A21_PE_5 = (FMC_A21<<16)|(4<<12)|(5<<4)|(12<<0),  //!< .
      FMC_A22_PE_6 = (FMC_A22<<16)|(4<<12)|(6<<4)|(12<<0),  //!< .
      FMC_A23_PE_2 = (FMC_A23<<16)|(4<<12)|(2<<4)|(12<<0),  //!< .
      FMC_A24_PG_13 = (FMC_A24<<16)|(6<<12)|(13<<4)|(12<<0),  //!< .
      FMC_A25_PG_14 = (FMC_A25<<16)|(6<<12)|(14<<4)|(12<<0),  //!< .
      FMC_A3_PF_3 = (FMC_A3<<16)|(5<<12)|(3<<4)|(12<<0),  //!< .
      FMC_A4_PF_4 = (FMC_A4<<16)|(5<<12)|(4<<4)|(12<<0),  //!< .
      FMC_A5_PF_5 = (FMC_A5<<16)|(5<<12)|(5<<4)|(12<<0),  //!< .
      FMC_A6_PF_12 = (FMC_A6<<16)|(5<<12)|(12<<4)|(12<<0),  //!< .
      FMC_A7_PF_13 = (FMC_A7<<16)|(5<<12)|(13<<4)|(12<<0),  //!< .
      FMC_A8_PF_14 = (FMC_A8<<16)|(5<<12)|(14<<4)|(12<<0),  //!< .
      FMC_A9_PF_15 = (FMC_A9<<16)|(5<<12)|(15<<4)|(12<<0),  //!< .
      FMC_ALE_PD_12 = (FMC_ALE<<16)|(3<<12)|(12<<4)|(12<<0),  //!< .
      FMC_BA0_PG_4 = (FMC_BA0<<16)|(6<<12)|(4<<4)|(12<<0),  //!< .
      FMC_BA1_PG_5 = (FMC_BA1<<16)|(6<<12)|(5<<4)|(12<<0),  //!< .
      FMC_CLE_PD_11 = (FMC_CLE<<16)|(3<<12)|(11<<4)|(12<<0),  //!< .
      FMC_CLK_PD_3 = (FMC_CLK<<16)|(3<<12)|(3<<4)|(12<<0),  //!< .
      FMC_D0_PD_14 = (FMC_D0<<16)|(3<<12)|(14<<4)|(12<<0),  //!< .
      FMC_D1_PD_15 = (FMC_D1<<16)|(3<<12)|(15<<4)|(12<<0),  //!< .
      FMC_D10_PE_13 = (FMC_D10<<16)|(4<<12)|(13<<4)|(12<<0),  //!< .
      FMC_D11_PE_14 = (FMC_D11<<16)|(4<<12)|(14<<4)|(12<<0),  //!< .
      FMC_D12_PE_15 = (FMC_D12<<16)|(4<<12)|(15<<4)|(12<<0),  //!< .
      FMC_D13_PD_8 = (FMC_D13<<16)|(3<<12)|(8<<4)|(12<<0),  //!< .
      FMC_D14_PD_9 = (FMC_D14<<16)|(3<<12)|(9<<4)|(12<<0),  //!< .
      FMC_D15_PD_10 = (FMC_D15<<16)|(3<<12)|(10<<4)|(12<<0),  //!< .
      FMC_D16_PH_8 = (FMC_D16<<16)|(7<<12)|(8<<4)|(12<<0),  //!< .
      FMC_D17_PH_9 = (FMC_D17<<16)|(7<<12)|(9<<4)|(12<<0),  //!< .
      FMC_D18_PH_10 = (FMC_D18<<16)|(7<<12)|(10<<4)|(12<<0),  //!< .
      FMC_D19_PH_11 = (FMC_D19<<16)|(7<<12)|(11<<4)|(12<<0),  //!< .
      FMC_D2_PD_0 = (FMC_D2<<16)|(3<<12)|(0<<4)|(12<<0),  //!< .
      FMC_D20_PH_12 = (FMC_D20<<16)|(7<<12)|(12<<4)|(12<<0),  //!< .
      FMC_D21_PH_13 = (FMC_D21<<16)|(7<<12)|(13<<4)|(12<<0),  //!< .
      FMC_D22_PH_14 = (FMC_D22<<16)|(7<<12)|(14<<4)|(12<<0),  //!< .
      FMC_D23_PH_15 = (FMC_D23<<16)|(7<<12)|(15<<4)|(12<<0),  //!< .
      FMC_D24_PI_0 = (FMC_D24<<16)|(8<<12)|(0<<4)|(12<<0),  //!< .
      FMC_D25_PI_1 = (FMC_D25<<16)|(8<<12)|(1<<4)|(12<<0),  //!< .
      FMC_D26_PI_2 = (FMC_D26<<16)|(8<<12)|(2<<4)|(12<<0),  //!< .
      FMC_D27_PI_3 = (FMC_D27<<16)|(8<<12)|(3<<4)|(12<<0),  //!< .
      FMC_D28_PI_6 = (FMC_D28<<16)|(8<<12)|(6<<4)|(12<<0),  //!< .
      FMC_D29_PI_7 = (FMC_D29<<16)|(8<<12)|(7<<4)|(12<<0),  //!< .
      FMC_D3_PD_1 = (FMC_D3<<16)|(3<<12)|(1<<4)|(12<<0),  //!< .
      FMC_D30_PI_9 = (FMC_D30<<16)|(8<<12)|(9<<4)|(12<<0),  //!< .
      FMC_D31_PI_10 = (FMC_D31<<16)|(8<<12)|(10<<4)|(12<<0),  //!< .
      FMC_D4_PE_7 = (FMC_D4<<16)|(4<<12)|(7<<4)|(12<<0),  //!< .
      FMC_D5_PE_8 = (FMC_D5<<16)|(4<<12)|(8<<4)|(12<<0),  //!< .
      FMC_D6_PE_9 = (FMC_D6<<16)|(4<<12)|(9<<4)|(12<<0),  //!< .
      FMC_D7_PE_10 = (FMC_D7<<16)|(4<<12)|(10<<4)|(12<<0),  //!< .
      FMC_D8_PE_11 = (FMC_D8<<16)|(4<<12)|(11<<4)|(12<<0),  //!< .
      FMC_D9_PE_12 = (FMC_D9<<16)|(4<<12)|(12<<4)|(12<<0),  //!< .
      FMC_INT_PG_7 = (FMC_INT<<16)|(6<<12)|(7<<4)|(12<<0),  //!< .
      FMC_NBL0_PE_0 = (FMC_NBL0<<16)|(4<<12)|(0<<4)|(12<<0),  //!< .
      FMC_NBL1_PE_1 = (FMC_NBL1<<16)|(4<<12)|(1<<4)|(12<<0),  //!< .
      FMC_NBL2_PI_4 = (FMC_NBL2<<16)|(8<<12)|(4<<4)|(12<<0),  //!< .
      FMC_NBL3_PI_5 = (FMC_NBL3<<16)|(8<<12)|(5<<4)|(12<<0),  //!< .
      FMC_NCE_PC_8 = (FMC_NCE<<16)|(2<<12)|(8<<4)|(9<<0),  //!< .
      FMC_NCE_PG_9 = (FMC_NCE<<16)|(6<<12)|(9<<4)|(12<<0),  //!< .
      FMC_NE1_PC_7 = (FMC_NE1<<16)|(2<<12)|(7<<4)|(9<<0),  //!< .
      FMC_NE1_PD_7 = (FMC_NE1<<16)|(3<<12)|(7<<4)|(12<<0),  //!< .
      FMC_NE2_PC_8 = (FMC_NE2<<16)|(2<<12)|(8<<4)|(9<<0),  //!< .
      FMC_NE2_PG_9 = (FMC_NE2<<16)|(6<<12)|(9<<4)|(12<<0),  //!< .
      FMC_NE3_PG_6 = (FMC_NE3<<16)|(6<<12)|(6<<4)|(12<<0),  //!< .
      FMC_NE3_PG_10 = (FMC_NE3<<16)|(6<<12)|(10<<4)|(12<<0),  //!< .
      FMC_NE4_PG_12 = (FMC_NE4<<16)|(6<<12)|(12<<4)|(12<<0),  //!< .
      FMC_NOE_PD_4 = (FMC_NOE<<16)|(3<<12)|(4<<4)|(12<<0),  //!< .
      FMC_NWAIT_PC_6 = (FMC_NWAIT<<16)|(2<<12)|(6<<4)|(9<<0),  //!< .
      FMC_NWAIT_PD_6 = (FMC_NWAIT<<16)|(3<<12)|(6<<4)|(12<<0),  //!< .
      FMC_NWE_PD_5 = (FMC_NWE<<16)|(3<<12)|(5<<4)|(12<<0),  //!< .
      FMC_SDCKE0_PC_3 = (FMC_SDCKE0<<16)|(2<<12)|(3<<4)|(12<<0),  //!< .
      FMC_SDCKE0_PC_5 = (FMC_SDCKE0<<16)|(2<<12)|(5<<4)|(12<<0),  //!< .
      FMC_SDCKE0_PH_2 = (FMC_SDCKE0<<16)|(7<<12)|(2<<4)|(12<<0),  //!< .
      FMC_SDCKE1_PB_5 = (FMC_SDCKE1<<16)|(1<<12)|(5<<4)|(12<<0),  //!< .
      FMC_SDCKE1_PH_7 = (FMC_SDCKE1<<16)|(7<<12)|(7<<4)|(12<<0),  //!< .
      FMC_SDCLK_PG_8 = (FMC_SDCLK<<16)|(6<<12)|(8<<4)|(12<<0),  //!< .
      FMC_SDNCAS_PG_15 = (FMC_SDNCAS<<16)|(6<<12)|(15<<4)|(12<<0),  //!< .
      FMC_SDNE0_PC_2 = (FMC_SDNE0<<16)|(2<<12)|(2<<4)|(12<<0),  //!< .
      FMC_SDNE0_PC_4 = (FMC_SDNE0<<16)|(2<<12)|(4<<4)|(12<<0),  //!< .
      FMC_SDNE0_PH_3 = (FMC_SDNE0<<16)|(7<<12)|(3<<4)|(12<<0),  //!< .
      FMC_SDNE1_PB_6 = (FMC_SDNE1<<16)|(1<<12)|(6<<4)|(12<<0),  //!< .
      FMC_SDNE1_PH_6 = (FMC_SDNE1<<16)|(7<<12)|(6<<4)|(12<<0),  //!< .
      FMC_SDNRAS_PF_11 = (FMC_SDNRAS<<16)|(5<<12)|(11<<4)|(12<<0),  //!< .
      FMC_SDNWE_PA_7 = (FMC_SDNWE<<16)|(0<<12)|(7<<4)|(12<<0),  //!< .
      FMC_SDNWE_PC_0 = (FMC_SDNWE<<16)|(2<<12)|(0<<4)|(12<<0),  //!< .
      FMC_SDNWE_PH_5 = (FMC_SDNWE<<16)|(7<<12)|(5<<4)|(12<<0),  //!< .
      HDMICEC_PA_15 = (HDMICEC<<16)|(0<<12)|(15<<4)|(3<<0),  //!< .
      HDMICEC_PB_6 = (HDMICEC<<16)|(1<<12)|(6<<4)|(3<<0),  //!< .
      I2C1_SCL_PB_6 = (I2C1_SCL<<16)|(1<<12)|(6<<4)|(4<<0),  //!< .
      I2C1_SCL_PB_8 = (I2C1_SCL<<16)|(1<<12)|(8<<4)|(4<<0),  //!< .
      I2C1_SDA_PB_9 = (I2C1_SDA<<16)|(1<<12)|(9<<4)|(4<<0),  //!< .
			I2C1_SMBA_PB_5 = (I2C1_SMBA<<16)|(1<<12)|(5<<4)|(4<<0),  //!< .
      I2C2_SCL_PF_1 = (I2C2_SCL<<16)|(5<<12)|(1<<4)|(4<<0),  //!< .
      I2C2_SCL_PH_4 = (I2C2_SCL<<16)|(7<<12)|(4<<4)|(4<<0),  //!< .
      I2C2_SDA_PF_0 = (I2C2_SDA<<16)|(5<<12)|(0<<4)|(4<<0),  //!< .
      I2C2_SDA_PH_5 = (I2C2_SDA<<16)|(7<<12)|(5<<4)|(4<<0),  //!< .
      I2C2_SMBA_PF_2 = (I2C2_SMBA<<16)|(5<<12)|(2<<4)|(4<<0),  //!< .
      I2C2_SMBA_PH_6 = (I2C2_SMBA<<16)|(7<<12)|(6<<4)|(4<<0),  //!< .
      I2C3_SCL_PA_8 = (I2C3_SCL<<16)|(0<<12)|(8<<4)|(4<<0),  //!< .
      I2C3_SCL_PH_7 = (I2C3_SCL<<16)|(7<<12)|(7<<4)|(4<<0),  //!< .
      I2C3_SDA_PC_9 = (I2C3_SDA<<16)|(2<<12)|(9<<4)|(4<<0),  //!< .
      I2C3_SDA_PH_8 = (I2C3_SDA<<16)|(7<<12)|(8<<4)|(4<<0),  //!< .
      I2C3_SMBA_PA_9 = (I2C3_SMBA<<16)|(0<<12)|(9<<4)|(4<<0),  //!< .
      I2C3_SMBA_PH_9 = (I2C3_SMBA<<16)|(7<<12)|(9<<4)|(4<<0),  //!< .
      I2C4_SCL_PB_6 = (I2C4_SCL<<16)|(1<<12)|(6<<4)|(11<<0),  //!< .
      I2C4_SCL_PD_12 = (I2C4_SCL<<16)|(3<<12)|(12<<4)|(4<<0),  //!< .
      I2C4_SCL_PF_14 = (I2C4_SCL<<16)|(5<<12)|(14<<4)|(4<<0),  //!< .
      I2C4_SCL_PH_11 = (I2C4_SCL<<16)|(7<<12)|(11<<4)|(4<<0),  //!< .
      I2C4_SDA_PB_7  = (I2C4_SDA<<16)|(1<<12)|(7<<4)|(11<<0),  //!< .
      I2C4_SDA_PD_13 = (I2C4_SDA<<16)|(3<<12)|(13<<4)|(4<<0),  //!< .
      I2C4_SDA_PF_15 = (I2C4_SDA<<16)|(5<<12)|(15<<4)|(4<<0),  //!< .
      I2C4_SDA_PH_12 = (I2C4_SDA<<16)|(7<<12)|(12<<4)|(4<<0),  //!< .
      I2C4_SMBA_PD_11 = (I2C4_SMBA<<16)|(3<<12)|(11<<4)|(4<<0),  //!< .
      I2C4_SMBA_PF_13 = (I2C4_SMBA<<16)|(5<<12)|(13<<4)|(4<<0),  //!< .
      I2C4_SMBA_PH_10 = (I2C4_SMBA<<16)|(7<<12)|(10<<4)|(4<<0),  //!< .
      I2S_CKIN_PC_9 = (I2S_CKIN<<16)|(2<<12)|(9<<4)|(5<<0),  //!< .
      I2S1_CK_PA_5 = (I2S1_CK<<16)|(0<<12)|(5<<4)|(5<<0),  //!< .
      I2S1_CK_PB_3 = (I2S1_CK<<16)|(1<<12)|(3<<4)|(5<<0),  //!< .
      I2S1_CK_PG_11 = (I2S1_CK<<16)|(6<<12)|(11<<4)|(5<<0),  //!< .
      I2S1_MCK_PC_4 = (I2S1_MCK<<16)|(2<<12)|(4<<4)|(5<<0),  //!< .
      I2S1_SD_PA_7 = (I2S1_SD<<16)|(0<<12)|(7<<4)|(5<<0),  //!< .
      I2S1_SD_PB_5 = (I2S1_SD<<16)|(1<<12)|(5<<4)|(5<<0),  //!< .
      I2S1_SD_PD_7 = (I2S1_SD<<16)|(3<<12)|(7<<4)|(5<<0),  //!< .
      I2S1_WS_PA_4 = (I2S1_WS<<16)|(0<<12)|(4<<4)|(5<<0),  //!< .
      I2S1_WS_PA_15 = (I2S1_WS<<16)|(0<<12)|(15<<4)|(5<<0),  //!< .
      I2S1_WS_PG_10 = (I2S1_WS<<16)|(6<<12)|(10<<4)|(5<<0),  //!< .
      I2S2_CK_PA_9 = (I2S2_CK<<16)|(0<<12)|(9<<4)|(5<<0),  //!< .
      I2S2_CK_PA_12 = (I2S2_CK<<16)|(0<<12)|(12<<4)|(5<<0),  //!< .
      I2S2_CK_PD_3 = (I2S2_CK<<16)|(3<<12)|(3<<4)|(5<<0),  //!< .
      I2S2_CK_PI_1 = (I2S2_CK<<16)|(8<<12)|(1<<4)|(5<<0),  //!< .
      I2S2_MCK_PC_6 = (I2S2_MCK<<16)|(2<<12)|(6<<4)|(5<<0),  //!< .
      I2S2_SD_PC_1 = (I2S2_SD<<16)|(2<<12)|(1<<4)|(5<<0),  //!< .
      I2S2_SD_PC_3 = (I2S2_SD<<16)|(2<<12)|(3<<4)|(5<<0),  //!< .
      I2S2_SD_PI_3 = (I2S2_SD<<16)|(8<<12)|(3<<4)|(5<<0),  //!< .
      I2S2_WS_PA_11 = (I2S2_WS<<16)|(0<<12)|(11<<4)|(5<<0),  //!< .
      I2S2_WS_PB_4 = (I2S2_WS<<16)|(1<<12)|(4<<4)|(7<<0),  //!< .
      I2S2_WS_PI_0 = (I2S2_WS<<16)|(8<<12)|(0<<4)|(5<<0),  //!< .
      I2S3_CK_PB_3 = (I2S3_CK<<16)|(1<<12)|(3<<4)|(6<<0),  //!< .
      I2S3_CK_PC_10 = (I2S3_CK<<16)|(2<<12)|(10<<4)|(6<<0),  //!< .
      I2S3_MCK_PC_7 = (I2S3_MCK<<16)|(2<<12)|(7<<4)|(6<<0),  //!< .
      I2S3_SD_PB_2 = (I2S3_SD<<16)|(1<<12)|(2<<4)|(7<<0),  //!< .
      I2S3_SD_PB_5 = (I2S3_SD<<16)|(1<<12)|(5<<4)|(6<<0),  //!< .
      I2S3_SD_PC_12 = (I2S3_SD<<16)|(2<<12)|(12<<4)|(6<<0),  //!< .
      I2S3_SD_PD_6 = (I2S3_SD<<16)|(3<<12)|(6<<4)|(5<<0),  //!< .
      I2S3_WS_PA_4 = (I2S3_WS<<16)|(0<<12)|(4<<4)|(6<<0),  //!< .
      I2S3_WS_PA_15 = (I2S3_WS<<16)|(0<<12)|(15<<4)|(6<<0),  //!< .
      JTCKSWCLK_PA_14 = (JTCKSWCLK<<16)|(0<<12)|(14<<4)|(0<<0),  //!< .
      JTDI_PA_15 = (JTDI<<16)|(0<<12)|(15<<4)|(0<<0),  //!< .
      JTDO_PB_3 = (JTDO<<16)|(1<<12)|(3<<4)|(0<<0),  //!< .
      JTMSSWDIO_PA_13 = (JTMSSWDIO<<16)|(0<<12)|(13<<4)|(0<<0),  //!< .
      LCD_B0_PE_4 = (LCD_B0<<16)|(4<<12)|(4<<4)|(14<<0),  //!< .
      LCD_B0_PG_14 = (LCD_B0<<16)|(6<<12)|(14<<4)|(14<<0),  //!< .
      LCD_B0_PJ_12 = (LCD_B0<<16)|(9<<12)|(12<<4)|(14<<0),  //!< .
      LCD_B1_PA_10 = (LCD_B1<<16)|(0<<12)|(10<<4)|(14<<0),  //!< .
      LCD_B1_PG_12 = (LCD_B1<<16)|(6<<12)|(12<<4)|(14<<0),  //!< .
      LCD_B1_PJ_13 = (LCD_B1<<16)|(9<<12)|(13<<4)|(14<<0),  //!< .
      LCD_B2_PA_3 = (LCD_B2<<16)|(0<<12)|(3<<4)|(9<<0),  //!< .
      LCD_B2_PC_9 = (LCD_B2<<16)|(2<<12)|(9<<4)|(14<<0),  //!< .
      LCD_B2_PD_6 = (LCD_B2<<16)|(3<<12)|(6<<4)|(14<<0),  //!< .
      LCD_B2_PG_10 = (LCD_B2<<16)|(6<<12)|(10<<4)|(14<<0),  //!< .
      LCD_B2_PJ_14 = (LCD_B2<<16)|(9<<12)|(14<<4)|(14<<0),  //!< .
      LCD_B3_PA_8 = (LCD_B3<<16)|(0<<12)|(8<<4)|(13<<0),  //!< .
      LCD_B3_PD_10 = (LCD_B3<<16)|(3<<12)|(10<<4)|(14<<0),  //!< .
      LCD_B3_PG_11 = (LCD_B3<<16)|(6<<12)|(11<<4)|(14<<0),  //!< .
      LCD_B3_PJ_15 = (LCD_B3<<16)|(9<<12)|(15<<4)|(14<<0),  //!< .
      LCD_B4_PA_10 = (LCD_B4<<16)|(0<<12)|(10<<4)|(9<<0),  //!< .
      LCD_B4_PE_12 = (LCD_B4<<16)|(4<<12)|(12<<4)|(14<<0),  //!< .
      LCD_B4_PG_12 = (LCD_B4<<16)|(6<<12)|(12<<4)|(9<<0),  //!< .
      LCD_B4_PI_4 = (LCD_B4<<16)|(8<<12)|(4<<4)|(14<<0),  //!< .
      LCD_B4_PK_3 = (LCD_B4<<16)|(10<<12)|(3<<4)|(14<<0),  //!< .
      LCD_B5_PA_3 = (LCD_B5<<16)|(0<<12)|(3<<4)|(14<<0),  //!< .
      LCD_B5_PI_5 = (LCD_B5<<16)|(8<<12)|(5<<4)|(14<<0),  //!< .
      LCD_B5_PK_4 = (LCD_B5<<16)|(10<<12)|(4<<4)|(14<<0),  //!< .
      LCD_B6_PI_6 = (LCD_B6<<16)|(8<<12)|(6<<4)|(14<<0),  //!< .
      LCD_B6_PK_5 = (LCD_B6<<16)|(10<<12)|(5<<4)|(14<<0),  //!< .
      LCD_B7_PI_7 = (LCD_B7<<16)|(8<<12)|(7<<4)|(14<<0),  //!< .
      LCD_B7_PK_6 = (LCD_B7<<16)|(10<<12)|(6<<4)|(14<<0),  //!< .
      LCD_CLK_PE_14 = (LCD_CLK<<16)|(4<<12)|(14<<4)|(14<<0),  //!< .
      LCD_CLK_PG_7 = (LCD_CLK<<16)|(6<<12)|(7<<4)|(14<<0),  //!< .
      LCD_CLK_PI_14 = (LCD_CLK<<16)|(8<<12)|(14<<4)|(14<<0),  //!< .
      LCD_DE_PE_13 = (LCD_DE<<16)|(4<<12)|(13<<4)|(14<<0),  //!< .
      LCD_DE_PF_10 = (LCD_DE<<16)|(5<<12)|(10<<4)|(14<<0),  //!< .
      LCD_DE_PK_7 = (LCD_DE<<16)|(10<<12)|(7<<4)|(14<<0),  //!< .
      LCD_G0_PB_1 = (LCD_G0<<16)|(1<<12)|(1<<4)|(14<<0),  //!< .
      LCD_G0_PE_5 = (LCD_G0<<16)|(4<<12)|(5<<4)|(14<<0),  //!< .
      LCD_G0_PJ_7 = (LCD_G0<<16)|(9<<12)|(7<<4)|(14<<0),  //!< .
      LCD_G1_PB_0 = (LCD_G1<<16)|(1<<12)|(0<<4)|(14<<0),  //!< .
      LCD_G1_PE_6 = (LCD_G1<<16)|(4<<12)|(6<<4)|(14<<0),  //!< .
      LCD_G1_PJ_8 = (LCD_G1<<16)|(9<<12)|(8<<4)|(14<<0),  //!< .
      LCD_G2_PA_6 = (LCD_G2<<16)|(0<<12)|(6<<4)|(14<<0),  //!< .
      LCD_G2_PH_13 = (LCD_G2<<16)|(7<<12)|(13<<4)|(14<<0),  //!< .
      LCD_G2_PI_15 = (LCD_G2<<16)|(8<<12)|(15<<4)|(9<<0),  //!< .
      LCD_G2_PJ_9 = (LCD_G2<<16)|(9<<12)|(9<<4)|(14<<0),  //!< .
      LCD_G3_PC_9 = (LCD_G3<<16)|(2<<12)|(9<<4)|(10<<0),  //!< .
      LCD_G3_PE_11 = (LCD_G3<<16)|(4<<12)|(11<<4)|(14<<0),  //!< .
      LCD_G3_PG_10 = (LCD_G3<<16)|(6<<12)|(10<<4)|(9<<0),  //!< .
      LCD_G3_PH_14 = (LCD_G3<<16)|(7<<12)|(14<<4)|(14<<0),  //!< .
      LCD_G3_PJ_10 = (LCD_G3<<16)|(9<<12)|(10<<4)|(14<<0),  //!< .
      LCD_G3_PJ_12 = (LCD_G3<<16)|(9<<12)|(12<<4)|(9<<0),  //!< .
      LCD_G4_PH_4 = (LCD_G4<<16)|(7<<12)|(4<<4)|(14<<0),  //!< .
      LCD_G4_PH_15 = (LCD_G4<<16)|(7<<12)|(15<<4)|(14<<0),  //!< .
      LCD_G4_PJ_11 = (LCD_G4<<16)|(9<<12)|(11<<4)|(14<<0),  //!< .
      LCD_G4_PJ_13 = (LCD_G4<<16)|(9<<12)|(13<<4)|(9<<0),  //!< .
      LCD_G5_PH_4 = (LCD_G5<<16)|(7<<12)|(4<<4)|(9<<0),  //!< .
      LCD_G5_PI_0 = (LCD_G5<<16)|(8<<12)|(0<<4)|(14<<0),  //!< .
      LCD_G5_PK_0 = (LCD_G5<<16)|(10<<12)|(0<<4)|(14<<0),  //!< .
      LCD_G6_PC_7 = (LCD_G6<<16)|(2<<12)|(7<<4)|(14<<0),  //!< .
      LCD_G6_PI_1 = (LCD_G6<<16)|(8<<12)|(1<<4)|(14<<0),  //!< .
      LCD_G6_PI_11 = (LCD_G6<<16)|(8<<12)|(11<<4)|(9<<0),  //!< .
      LCD_G6_PK_1 = (LCD_G6<<16)|(10<<12)|(1<<4)|(14<<0),  //!< .
      LCD_G7_PB_5 = (LCD_G7<<16)|(1<<12)|(5<<4)|(14<<0),  //!< .
      LCD_G7_PD_3 = (LCD_G7<<16)|(3<<12)|(3<<4)|(14<<0),  //!< .
      LCD_G7_PG_8 = (LCD_G7<<16)|(6<<12)|(8<<4)|(14<<0),  //!< .
      LCD_G7_PI_2 = (LCD_G7<<16)|(8<<12)|(2<<4)|(14<<0),  //!< .
      LCD_G7_PK_2 = (LCD_G7<<16)|(10<<12)|(2<<4)|(14<<0),  //!< .
      LCD_HSYNC_PC_6 = (LCD_HSYNC<<16)|(2<<12)|(6<<4)|(14<<0),  //!< .
      LCD_HSYNC_PI_10 = (LCD_HSYNC<<16)|(8<<12)|(10<<4)|(14<<0),  //!< .
      LCD_HSYNC_PI_12 = (LCD_HSYNC<<16)|(8<<12)|(12<<4)|(14<<0),  //!< .
      LCD_R0_PG_13 = (LCD_R0<<16)|(6<<12)|(13<<4)|(14<<0),  //!< .
      LCD_R0_PH_2 = (LCD_R0<<16)|(7<<12)|(2<<4)|(14<<0),  //!< .
      LCD_R0_PI_15 = (LCD_R0<<16)|(8<<12)|(15<<4)|(14<<0),  //!< .
      LCD_R1_PA_2 = (LCD_R1<<16)|(0<<12)|(2<<4)|(14<<0),  //!< .
      LCD_R1_PH_3 = (LCD_R1<<16)|(7<<12)|(3<<4)|(14<<0),  //!< .
      LCD_R1_PJ_0 = (LCD_R1<<16)|(9<<12)|(0<<4)|(14<<0),  //!< .
      LCD_R2_PA_1 = (LCD_R2<<16)|(0<<12)|(1<<4)|(14<<0),  //!< .
      LCD_R2_PC_10 = (LCD_R2<<16)|(2<<12)|(10<<4)|(14<<0),  //!< .
      LCD_R2_PH_8 = (LCD_R2<<16)|(7<<12)|(8<<4)|(14<<0),  //!< .
      LCD_R2_PJ_1 = (LCD_R2<<16)|(9<<12)|(1<<4)|(14<<0),  //!< .
      LCD_R3_PB_0 = (LCD_R3<<16)|(1<<12)|(0<<4)|(9<<0),  //!< .
      LCD_R3_PH_9 = (LCD_R3<<16)|(7<<12)|(9<<4)|(14<<0),  //!< .
      LCD_R3_PJ_2 = (LCD_R3<<16)|(9<<12)|(2<<4)|(14<<0),  //!< .
      LCD_R4_PA_5 = (LCD_R4<<16)|(0<<12)|(5<<4)|(14<<0),  //!< .
      LCD_R4_PA_11 = (LCD_R4<<16)|(0<<12)|(11<<4)|(14<<0),  //!< .
      LCD_R4_PH_10 = (LCD_R4<<16)|(7<<12)|(10<<4)|(14<<0),  //!< .
      LCD_R4_PJ_3 = (LCD_R4<<16)|(9<<12)|(3<<4)|(14<<0),  //!< .
      LCD_R5_PA_9 = (LCD_R5<<16)|(0<<12)|(9<<4)|(14<<0),  //!< .
      LCD_R5_PA_12 = (LCD_R5<<16)|(0<<12)|(12<<4)|(14<<0),  //!< .
      LCD_R5_PC_0 = (LCD_R5<<16)|(2<<12)|(0<<4)|(14<<0),  //!< .
      LCD_R5_PH_11 = (LCD_R5<<16)|(7<<12)|(11<<4)|(14<<0),  //!< .
      LCD_R5_PJ_4 = (LCD_R5<<16)|(9<<12)|(4<<4)|(14<<0),  //!< .
      LCD_R6_PA_8 = (LCD_R6<<16)|(0<<12)|(8<<4)|(14<<0),  //!< .
      LCD_R6_PB_1 = (LCD_R6<<16)|(1<<12)|(1<<4)|(9<<0),  //!< .
      LCD_R6_PH_12 = (LCD_R6<<16)|(7<<12)|(12<<4)|(14<<0),  //!< .
      LCD_R6_PJ_5 = (LCD_R6<<16)|(9<<12)|(5<<4)|(14<<0),  //!< .
      LCD_R7_PE_15 = (LCD_R7<<16)|(4<<12)|(15<<4)|(14<<0),  //!< .
      LCD_R7_PG_6 = (LCD_R7<<16)|(6<<12)|(6<<4)|(14<<0),  //!< .
      LCD_R7_PJ_0 = (LCD_R7<<16)|(9<<12)|(0<<4)|(9<<0),  //!< .
      LCD_R7_PJ_6 = (LCD_R7<<16)|(9<<12)|(6<<4)|(14<<0),  //!< .
      LCD_VSYNC_PI_13 = (LCD_VSYNC<<16)|(8<<12)|(13<<4)|(14<<0),  //!< .
      LCD_VSYNC_PA_4 = (LCD_VSYNC<<16)|(0<<12)|(4<<4)|(14<<0),  //!< .
      LCD_VSYNC_PI_9 = (LCD_VSYNC<<16)|(8<<12)|(9<<4)|(14<<0),  //!< .
      LPTIM1_ETR_PE_0 = (LPTIM1_ETR<<16)|(4<<12)|(0<<4)|(3<<0),  //!< .
      LPTIM1_ETR_PG_14 = (LPTIM1_ETR<<16)|(6<<12)|(14<<4)|(3<<0),  //!< .
      LPTIM1_IN1_PG_12 = (LPTIM1_IN1<<16)|(6<<12)|(12<<4)|(3<<0),  //!< .
      LPTIM1_IN2_PE_1 = (LPTIM1_IN2<<16)|(4<<12)|(1<<4)|(3<<0),  //!< .
      LPTIM1_IN2_PH_2 = (LPTIM1_IN2<<16)|(7<<12)|(2<<4)|(3<<0),  //!< .
      LPTIM1_OUT_PD_13 = (LPTIM1_OUT<<16)|(3<<12)|(13<<4)|(3<<0),  //!< .
      LPTIM1_OUT_PG_13 = (LPTIM1_OUT<<16)|(6<<12)|(13<<4)|(3<<0),  //!< .
      MCO1_PA_8 = (MCO1<<16)|(0<<12)|(8<<4)|(0<<0),  //!< .
      MCO2_PC_9 = (MCO2<<16)|(2<<12)|(9<<4)|(0<<0),  //!< .
      MDIOS_MDC_PA_6 = (MDIOS_MDC<<16)|(0<<12)|(6<<4)|(12<<0),  //!< .
      MDIOS_MDIO_PA_2 = (MDIOS_MDIO<<16)|(0<<12)|(2<<4)|(12<<0),  //!< .
      MDIOS_MDIO_PA_10 = (MDIOS_MDIO<<16)|(0<<12)|(10<<4)|(12<<0),  //!< .
      NJTRST_PB_4 = (NJTRST<<16)|(1<<12)|(4<<4)|(0<<0),  //!< .
      OTG_FS_DM_PA_11 = (OTG_FS_DM<<16)|(0<<12)|(11<<4)|(10<<0),  //!< .
      OTG_FS_DP_PA_12 = (OTG_FS_DP<<16)|(0<<12)|(12<<4)|(10<<0),  //!< .
      OTG_FS_ID_PA_10 = (OTG_FS_ID<<16)|(0<<12)|(10<<4)|(10<<0),  //!< .
      OTG_FS_SOF_PA_8 = (OTG_FS_SOF<<16)|(0<<12)|(8<<4)|(10<<0),  //!< .
      OTG_HS_SOF_PA_4 = (OTG_HS_SOF<<16)|(0<<12)|(4<<4)|(12<<0),  //!< .
      OTG_HS_ULPI_CK_PA_5 = (OTG_HS_ULPI_CK<<16)|(0<<12)|(5<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_D0_PA_3 = (OTG_HS_ULPI_D0<<16)|(0<<12)|(3<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_D1_PB_0 = (OTG_HS_ULPI_D1<<16)|(1<<12)|(0<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_D2_PB_1 = (OTG_HS_ULPI_D2<<16)|(1<<12)|(1<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_D7_PB_5 = (OTG_HS_ULPI_D7<<16)|(1<<12)|(5<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_DIR_PC_2 = (OTG_HS_ULPI_DIR<<16)|(2<<12)|(2<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_DIR_PI_11 = (OTG_HS_ULPI_DIR<<16)|(8<<12)|(11<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_NXT_PC_3 = (OTG_HS_ULPI_NXT<<16)|(2<<12)|(3<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_NXT_PH_4 = (OTG_HS_ULPI_NXT<<16)|(7<<12)|(4<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_STP_PC_0 = (OTG_HS_ULPI_STP<<16)|(2<<12)|(0<<4)|(10<<0),  //!< .
      QUADSPI_BK1_IO0_PC_9 = (QUADSPI_BK1_IO0<<16)|(2<<12)|(9<<4)|(9<<0),  //!< .
      QUADSPI_BK1_IO0_PD_11 = (QUADSPI_BK1_IO0<<16)|(3<<12)|(11<<4)|(9<<0),  //!< .
      QUADSPI_BK1_IO0_PF_8 = (QUADSPI_BK1_IO0<<16)|(5<<12)|(8<<4)|(10<<0),  //!< .
      QUADSPI_BK1_IO1_PC_10 = (QUADSPI_BK1_IO1<<16)|(2<<12)|(10<<4)|(9<<0),  //!< .
      QUADSPI_BK1_IO1_PD_12 = (QUADSPI_BK1_IO1<<16)|(3<<12)|(12<<4)|(9<<0),  //!< .
      QUADSPI_BK1_IO1_PF_9 = (QUADSPI_BK1_IO1<<16)|(5<<12)|(9<<4)|(10<<0),  //!< .
      QUADSPI_BK1_IO2_PE_2 = (QUADSPI_BK1_IO2<<16)|(4<<12)|(2<<4)|(9<<0),  //!< .
      QUADSPI_BK1_IO2_PF_7 = (QUADSPI_BK1_IO2<<16)|(5<<12)|(7<<4)|(9<<0),  //!< .
      QUADSPI_BK1_IO3_PA_1 = (QUADSPI_BK1_IO3<<16)|(0<<12)|(1<<4)|(9<<0),  //!< .
      QUADSPI_BK1_IO3_PD_13 = (QUADSPI_BK1_IO3<<16)|(3<<12)|(13<<4)|(9<<0),  //!< .
      QUADSPI_BK1_IO3_PF_6 = (QUADSPI_BK1_IO3<<16)|(5<<12)|(6<<4)|(9<<0),  //!< .
      QUADSPI_BK1_NCS_PB_6 = (QUADSPI_BK1_NCS<<16)|(1<<12)|(6<<4)|(10<<0),  //!< .
      QUADSPI_BK2_IO0_PE_7 = (QUADSPI_BK2_IO0<<16)|(4<<12)|(7<<4)|(10<<0),  //!< .
      QUADSPI_BK2_IO0_PH_2 = (QUADSPI_BK2_IO0<<16)|(7<<12)|(2<<4)|(9<<0),  //!< .
      QUADSPI_BK2_IO1_PE_8 = (QUADSPI_BK2_IO1<<16)|(4<<12)|(8<<4)|(10<<0),  //!< .
      QUADSPI_BK2_IO1_PH_3 = (QUADSPI_BK2_IO1<<16)|(7<<12)|(3<<4)|(9<<0),  //!< .
      QUADSPI_BK2_IO2_PE_9 = (QUADSPI_BK2_IO2<<16)|(4<<12)|(9<<4)|(10<<0),  //!< .
      QUADSPI_BK2_IO2_PG_9 = (QUADSPI_BK2_IO2<<16)|(6<<12)|(9<<4)|(9<<0),  //!< .
      QUADSPI_BK2_IO3_PE_10 = (QUADSPI_BK2_IO3<<16)|(4<<12)|(10<<4)|(10<<0),  //!< .
      QUADSPI_BK2_IO3_PG_14 = (QUADSPI_BK2_IO3<<16)|(6<<12)|(14<<4)|(9<<0),  //!< .
      QUADSPI_BK2_NCS_PC_11 = (QUADSPI_BK2_NCS<<16)|(2<<12)|(11<<4)|(9<<0),  //!< .
      QUADSPI_CLK_PB_2 = (QUADSPI_CLK<<16)|(1<<12)|(2<<4)|(9<<0),  //!< .
      QUADSPI_CLK_PF_10 = (QUADSPI_CLK<<16)|(5<<12)|(10<<4)|(9<<0),  //!< .
      SAI1_FS_A_PE_4 = (SAI1_FS_A<<16)|(4<<12)|(4<<4)|(6<<0),  //!< .
      SAI1_FS_B_PF_9 = (SAI1_FS_B<<16)|(5<<12)|(9<<4)|(6<<0),  //!< .
      SAI1_MCLK_A_PE_2 = (SAI1_MCLK_A<<16)|(4<<12)|(2<<4)|(6<<0),  //!< .
      SAI1_MCLK_A_PG_7 = (SAI1_MCLK_A<<16)|(6<<12)|(7<<4)|(6<<0),  //!< .
      SAI1_MCLK_B_PF_7 = (SAI1_MCLK_B<<16)|(5<<12)|(7<<4)|(6<<0),  //!< .
      SAI1_SCK_A_PE_5 = (SAI1_SCK_A<<16)|(4<<12)|(5<<4)|(6<<0),  //!< .
      SAI1_SCK_B_PF_8 = (SAI1_SCK_B<<16)|(5<<12)|(8<<4)|(6<<0),  //!< .
      SAI1_SD_A_PB_2 = (SAI1_SD_A<<16)|(1<<12)|(2<<4)|(6<<0),  //!< .
      SAI1_SD_A_PC_1 = (SAI1_SD_A<<16)|(2<<12)|(1<<4)|(6<<0),  //!< .
      SAI1_SD_A_PD_6 = (SAI1_SD_A<<16)|(3<<12)|(6<<4)|(6<<0),  //!< .
      SAI1_SD_A_PE_6 = (SAI1_SD_A<<16)|(4<<12)|(6<<4)|(6<<0),  //!< .
      SAI1_SD_B_PE_3 = (SAI1_SD_B<<16)|(4<<12)|(3<<4)|(6<<0),  //!< .
      SAI1_SD_B_PF_6 = (SAI1_SD_B<<16)|(5<<12)|(6<<4)|(6<<0),  //!< .
      SAI2_FS_A_PD_12 = (SAI2_FS_A<<16)|(3<<12)|(12<<4)|(10<<0),  //!< .
      SAI2_FS_A_PI_7 = (SAI2_FS_A<<16)|(8<<12)|(7<<4)|(10<<0),  //!< .
      SAI2_FS_B_PA_12 = (SAI2_FS_B<<16)|(0<<12)|(12<<4)|(8<<0),  //!< .
      SAI2_FS_B_PC_0 = (SAI2_FS_B<<16)|(2<<12)|(0<<4)|(8<<0),  //!< .
      SAI2_FS_B_PE_13 = (SAI2_FS_B<<16)|(4<<12)|(13<<4)|(10<<0),  //!< .
      SAI2_FS_B_PG_9 = (SAI2_FS_B<<16)|(6<<12)|(9<<4)|(10<<0),  //!< .
      SAI2_MCK_A_PE_0 = (SAI2_MCK_A<<16)|(4<<12)|(0<<4)|(10<<0),  //!< .
      SAI2_MCK_A_PI_4 = (SAI2_MCK_A<<16)|(8<<12)|(4<<4)|(10<<0),  //!< .
      SAI2_MCK_B_PA_1 = (SAI2_MCK_B<<16)|(0<<12)|(1<<4)|(10<<0),  //!< .
      SAI2_MCK_B_PE_6 = (SAI2_MCK_B<<16)|(4<<12)|(6<<4)|(10<<0),  //!< .
      SAI2_MCK_B_PE_14 = (SAI2_MCK_B<<16)|(4<<12)|(14<<4)|(10<<0),  //!< .
      SAI2_MCK_B_PH_3 = (SAI2_MCK_B<<16)|(7<<12)|(3<<4)|(10<<0),  //!< .
      SAI2_SCK_A_PD_13 = (SAI2_SCK_A<<16)|(3<<12)|(13<<4)|(10<<0),  //!< .
      SAI2_SCK_A_PI_5 = (SAI2_SCK_A<<16)|(8<<12)|(5<<4)|(10<<0),  //!< .
      SAI2_SCK_B_PA_2 = (SAI2_SCK_B<<16)|(0<<12)|(2<<4)|(8<<0),  //!< .
      SAI2_SCK_B_PE_12 = (SAI2_SCK_B<<16)|(4<<12)|(12<<4)|(10<<0),  //!< .
      SAI2_SCK_B_PH_2 = (SAI2_SCK_B<<16)|(7<<12)|(2<<4)|(10<<0),  //!< .
      SAI2_SD_A_PD_11 = (SAI2_SD_A<<16)|(3<<12)|(11<<4)|(10<<0),  //!< .
      SAI2_SD_A_PI_6 = (SAI2_SD_A<<16)|(8<<12)|(6<<4)|(10<<0),  //!< .
      SAI2_SD_B_PA_0 = (SAI2_SD_B<<16)|(0<<12)|(0<<4)|(10<<0),  //!< .
      SAI2_SD_B_PE_11 = (SAI2_SD_B<<16)|(4<<12)|(11<<4)|(10<<0),  //!< .
      SAI2_SD_B_PF_11 = (SAI2_SD_B<<16)|(5<<12)|(11<<4)|(10<<0),  //!< .
      SAI2_SD_B_PG_10 = (SAI2_SD_B<<16)|(6<<12)|(10<<4)|(10<<0),  //!< .
      SDMMC_CK_PC_12 = (SDMMC_CK<<16)|(2<<12)|(12<<4)|(12<<0),  //!< .
      SDMMC_CMD_PD_2 = (SDMMC_CMD<<16)|(3<<12)|(2<<4)|(12<<0),  //!< .
      SDMMC_D0_PC_8 = (SDMMC_D0<<16)|(2<<12)|(8<<4)|(12<<0),  //!< .
      SDMMC_D1_PC_9 = (SDMMC_D1<<16)|(2<<12)|(9<<4)|(12<<0),  //!< .
      SDMMC_D2_PC_10 = (SDMMC_D2<<16)|(2<<12)|(10<<4)|(12<<0),  //!< .
      SDMMC_D3_PC_11 = (SDMMC_D3<<16)|(2<<12)|(11<<4)|(12<<0),  //!< .
      SDMMC_D6_PC_6 = (SDMMC_D6<<16)|(2<<12)|(6<<4)|(12<<0),  //!< .
      SDMMC_D7_PC_7 = (SDMMC_D7<<16)|(2<<12)|(7<<4)|(12<<0),  //!< .
      SDMMC2_CK_PD_6 = (SDMMC2_CK<<16)|(3<<12)|(6<<4)|(11<<0),  //!< .
      SDMMC2_CMD_PD_7 = (SDMMC2_CMD<<16)|(3<<12)|(7<<4)|(11<<0),  //!< .
      SDMMC2_D0_PG_9 = (SDMMC2_D0<<16)|(6<<12)|(9<<4)|(11<<0),  //!< .
      SDMMC2_D1_PG_10 = (SDMMC2_D1<<16)|(6<<12)|(10<<4)|(11<<0),  //!< .
      SDMMC2_D2_PB_3 = (SDMMC2_D2<<16)|(1<<12)|(3<<4)|(10<<0),  //!< .
      SDMMC2_D2_PG_11 = (SDMMC2_D2<<16)|(6<<12)|(11<<4)|(10<<0),  //!< .
      SDMMC2_D3_PB_4 = (SDMMC2_D3<<16)|(1<<12)|(4<<4)|(10<<0),  //!< .
      SDMMC2_D3_PG_12 = (SDMMC2_D3<<16)|(6<<12)|(12<<4)|(11<<0),  //!< .
      SDMMC2_D6_PC_6 = (SDMMC2_D6<<16)|(2<<12)|(6<<4)|(10<<0),  //!< .
      SDMMC2_D7_PC_7 = (SDMMC2_D7<<16)|(2<<12)|(7<<4)|(10<<0),  //!< .
      SPDIF_RX0_PD_7 = (SPDIF_RX0<<16)|(3<<12)|(7<<4)|(8<<0),  //!< .
      SPDIF_RX0_PG_11 = (SPDIF_RX0<<16)|(6<<12)|(11<<4)|(7<<0),  //!< .
      SPDIF_RX1_PD_8 = (SPDIF_RX1<<16)|(3<<12)|(8<<4)|(8<<0),  //!< .
      SPDIF_RX1_PG_12 = (SPDIF_RX1<<16)|(6<<12)|(12<<4)|(7<<0),  //!< .
      SPDIF_RX2_PC_4 = (SPDIF_RX2<<16)|(2<<12)|(4<<4)|(8<<0),  //!< .
      SPDIF_RX2_PG_8 = (SPDIF_RX2<<16)|(6<<12)|(8<<4)|(7<<0),  //!< .
      SPDIF_RX3_PC_5 = (SPDIF_RX3<<16)|(2<<12)|(5<<4)|(8<<0),  //!< .
      SPDIF_RX3_PG_9 = (SPDIF_RX3<<16)|(6<<12)|(9<<4)|(7<<0),  //!< .
      SPI1_MISO_PA_6 = (SPI1_MISO<<16)|(0<<12)|(6<<4)|(5<<0),  //!< .
      SPI1_MISO_PB_4 = (SPI1_MISO<<16)|(1<<12)|(4<<4)|(5<<0),  //!< .
      SPI1_MISO_PG_9 = (SPI1_MISO<<16)|(6<<12)|(9<<4)|(5<<0),  //!< .
      SPI1_MOSI_PA_7 = (SPI1_MOSI<<16)|(0<<12)|(7<<4)|(5<<0),  //!< .
      SPI1_MOSI_PB_5 = (SPI1_MOSI<<16)|(1<<12)|(5<<4)|(5<<0),  //!< .
      SPI1_MOSI_PD_7 = (SPI1_MOSI<<16)|(3<<12)|(7<<4)|(5<<0),  //!< .
      SPI1_NSS_PA_15 = (SPI1_NSS<<16)|(0<<12)|(15<<4)|(4<<0),  //!< .
      SPI1_NSS_PA_4 = (SPI1_NSS<<16)|(0<<12)|(4<<4)|(5<<0),  //!< .
      SPI1_NSS_PG_10 = (SPI1_NSS<<16)|(6<<12)|(10<<4)|(5<<0),  //!< .
      SPI1_SCK_PA_5 = (SPI1_SCK<<16)|(0<<12)|(5<<4)|(5<<0),  //!< .
      SPI1_SCK_PB_3 = (SPI1_SCK<<16)|(1<<12)|(3<<4)|(5<<0),  //!< .
      SPI1_SCK_PG_11 = (SPI1_SCK<<16)|(6<<12)|(11<<4)|(5<<0),  //!< .
      SPI2_MISO_PC_2 = (SPI2_MISO<<16)|(2<<12)|(2<<4)|(5<<0),  //!< .
      SPI2_MISO_PI_2 = (SPI2_MISO<<16)|(8<<12)|(2<<4)|(5<<0),  //!< .
      SPI2_MOSI_PC_1 = (SPI2_MOSI<<16)|(2<<12)|(1<<4)|(5<<0),  //!< .
      SPI2_MOSI_PC_3 = (SPI2_MOSI<<16)|(2<<12)|(3<<4)|(5<<0),  //!< .
      SPI2_MOSI_PI_3 = (SPI2_MOSI<<16)|(8<<12)|(3<<4)|(5<<0),  //!< .
      SPI2_NSS_PA_11 = (SPI2_NSS<<16)|(0<<12)|(11<<4)|(5<<0),  //!< .
      SPI2_NSS_PB_4 = (SPI2_NSS<<16)|(1<<12)|(4<<4)|(7<<0),  //!< .
      SPI2_NSS_PI_0 = (SPI2_NSS<<16)|(8<<12)|(0<<4)|(5<<0),  //!< .
      SPI2_SCK_PA_9 = (SPI2_SCK<<16)|(0<<12)|(9<<4)|(5<<0),  //!< .
      SPI2_SCK_PA_12 = (SPI2_SCK<<16)|(0<<12)|(12<<4)|(5<<0),  //!< .
      SPI2_SCK_PD_3 = (SPI2_SCK<<16)|(3<<12)|(3<<4)|(5<<0),  //!< .
      SPI2_SCK_PI_1 = (SPI2_SCK<<16)|(8<<12)|(1<<4)|(5<<0),  //!< .
      SPI3_MISO_PB_4 = (SPI3_MISO<<16)|(1<<12)|(4<<4)|(6<<0),  //!< .
      SPI3_MISO_PC_11 = (SPI3_MISO<<16)|(2<<12)|(11<<4)|(6<<0),  //!< .
      SPI3_MOSI_PB_2 = (SPI3_MOSI<<16)|(1<<12)|(2<<4)|(7<<0),  //!< .
      SPI3_MOSI_PB_5 = (SPI3_MOSI<<16)|(1<<12)|(5<<4)|(6<<0),  //!< .
      SPI3_MOSI_PC_12 = (SPI3_MOSI<<16)|(2<<12)|(12<<4)|(6<<0),  //!< .
      SPI3_NSS_PA_4 = (SPI3_NSS<<16)|(0<<12)|(4<<4)|(6<<0),  //!< .
      SPI3_NSS_PA_15 = (SPI3_NSS<<16)|(0<<12)|(15<<4)|(6<<0),  //!< .
      SPI3_SCK_PB_3 = (SPI3_SCK<<16)|(1<<12)|(3<<4)|(6<<0),  //!< .
      SPI3_SCK_PC_10 = (SPI3_SCK<<16)|(2<<12)|(10<<4)|(6<<0),  //!< .
      SPI4_MISO_PE_5 = (SPI4_MISO<<16)|(4<<12)|(5<<4)|(5<<0),  //!< .
      SPI4_MISO_PE_13 = (SPI4_MISO<<16)|(4<<12)|(13<<4)|(5<<0),  //!< .
      SPI4_MOSI_PE_6 = (SPI4_MOSI<<16)|(4<<12)|(6<<4)|(5<<0),  //!< .
      SPI4_MOSI_PE_14 = (SPI4_MOSI<<16)|(4<<12)|(14<<4)|(5<<0),  //!< .
      SPI4_NSS_PE_4 = (SPI4_NSS<<16)|(4<<12)|(4<<4)|(5<<0),  //!< .
      SPI4_NSS_PE_11 = (SPI4_NSS<<16)|(4<<12)|(11<<4)|(5<<0),  //!< .
      SPI4_SCK_PE_2 = (SPI4_SCK<<16)|(4<<12)|(2<<4)|(5<<0),  //!< .
      SPI4_SCK_PE_12 = (SPI4_SCK<<16)|(4<<12)|(12<<4)|(5<<0),  //!< .
      SPI5_MISO_PF_8 = (SPI5_MISO<<16)|(5<<12)|(8<<4)|(5<<0),  //!< .
      SPI5_MISO_PH_7 = (SPI5_MISO<<16)|(7<<12)|(7<<4)|(5<<0),  //!< .
      SPI5_MOSI_PF_9 = (SPI5_MOSI<<16)|(5<<12)|(9<<4)|(5<<0),  //!< .
      SPI5_MOSI_PF_11 = (SPI5_MOSI<<16)|(5<<12)|(11<<4)|(5<<0),  //!< .
      SPI5_NSS_PF_6 = (SPI5_NSS<<16)|(5<<12)|(6<<4)|(5<<0),  //!< .
      SPI5_NSS_PH_5 = (SPI5_NSS<<16)|(7<<12)|(5<<4)|(5<<0),  //!< .
      SPI5_SCK_PF_7 = (SPI5_SCK<<16)|(5<<12)|(7<<4)|(5<<0),  //!< .
      SPI5_SCK_PH_6 = (SPI5_SCK<<16)|(7<<12)|(6<<4)|(5<<0),  //!< .
      SPI6_MISO_PA_6 = (SPI6_MISO<<16)|(0<<12)|(6<<4)|(8<<0),  //!< .
      SPI6_MISO_PB_4 = (SPI6_MISO<<16)|(1<<12)|(4<<4)|(8<<0),  //!< .
      SPI6_MISO_PG_12 = (SPI6_MISO<<16)|(6<<12)|(12<<4)|(5<<0),  //!< .
      SPI6_MOSI_PA_7 = (SPI6_MOSI<<16)|(0<<12)|(7<<4)|(8<<0),  //!< .
      SPI6_MOSI_PB_5 = (SPI6_MOSI<<16)|(1<<12)|(5<<4)|(8<<0),  //!< .
      SPI6_MOSI_PG_14 = (SPI6_MOSI<<16)|(6<<12)|(14<<4)|(5<<0),  //!< .
      SPI6_NSS_PA_4 = (SPI6_NSS<<16)|(0<<12)|(4<<4)|(8<<0),  //!< .
      SPI6_NSS_PA_15 = (SPI6_NSS<<16)|(0<<12)|(15<<4)|(7<<0),  //!< .
      SPI6_NSS_PG_8 = (SPI6_NSS<<16)|(6<<12)|(8<<4)|(5<<0),  //!< .
      SPI6_SCK_PA_5 = (SPI6_SCK<<16)|(0<<12)|(5<<4)|(8<<0),  //!< .
      SPI6_SCK_PB_3 = (SPI6_SCK<<16)|(1<<12)|(3<<4)|(8<<0),  //!< .
      SPI6_SCK_PG_13 = (SPI6_SCK<<16)|(6<<12)|(13<<4)|(5<<0),  //!< .
      TIM1_BKIN_PA_6 = (TIM1_BKIN<<16)|(0<<12)|(6<<4)|(1<<0),  //!< .
      TIM1_BKIN_PE_15 = (TIM1_BKIN<<16)|(4<<12)|(15<<4)|(1<<0),  //!< .
      TIM1_BKIN2_PE_6 = (TIM1_BKIN2<<16)|(4<<12)|(6<<4)|(1<<0),  //!< .
      TIM1_CH1_PA_8 = (TIM1_CH1<<16)|(0<<12)|(8<<4)|(1<<0),  //!< .
      TIM1_CH1_PE_9 = (TIM1_CH1<<16)|(4<<12)|(9<<4)|(1<<0),  //!< .
      TIM1_CH1N_PA_7 = (TIM1_CH1N<<16)|(0<<12)|(7<<4)|(1<<0),  //!< .
      TIM1_CH1N_PE_8 = (TIM1_CH1N<<16)|(4<<12)|(8<<4)|(1<<0),  //!< .
      TIM1_CH2_PA_9 = (TIM1_CH2<<16)|(0<<12)|(9<<4)|(1<<0),  //!< .
      TIM1_CH2_PE_11 = (TIM1_CH2<<16)|(4<<12)|(11<<4)|(1<<0),  //!< .
      TIM1_CH2N_PB_0 = (TIM1_CH2N<<16)|(1<<12)|(0<<4)|(1<<0),  //!< .
      TIM1_CH2N_PE_10 = (TIM1_CH2N<<16)|(4<<12)|(10<<4)|(1<<0),  //!< .
      TIM1_CH3_PA_10 = (TIM1_CH3<<16)|(0<<12)|(10<<4)|(1<<0),  //!< .
      TIM1_CH3_PE_13 = (TIM1_CH3<<16)|(4<<12)|(13<<4)|(1<<0),  //!< .
      TIM1_CH3N_PB_1 = (TIM1_CH3N<<16)|(1<<12)|(1<<4)|(1<<0),  //!< .
      TIM1_CH3N_PE_12 = (TIM1_CH3N<<16)|(4<<12)|(12<<4)|(1<<0),  //!< .
      TIM1_CH4_PA_11 = (TIM1_CH4<<16)|(0<<12)|(11<<4)|(1<<0),  //!< .
      TIM1_CH4_PE_14 = (TIM1_CH4<<16)|(4<<12)|(14<<4)|(1<<0),  //!< .
      TIM1_ETR_PA_12 = (TIM1_ETR<<16)|(0<<12)|(12<<4)|(1<<0),  //!< .
      TIM1_ETR_PE_7 = (TIM1_ETR<<16)|(4<<12)|(7<<4)|(1<<0),  //!< .
      TIM1_IN1_PD_12 = (TIM1_IN1<<16)|(3<<12)|(12<<4)|(3<<0),  //!< .
      TIM10_CH1_PF_6 = (TIM10_CH1<<16)|(5<<12)|(6<<4)|(3<<0),  //!< .
      TIM11_CH1_PF_7 = (TIM11_CH1<<16)|(5<<12)|(7<<4)|(3<<0),  //!< .
      TIM12_CH1_PH_6 = (TIM12_CH1<<16)|(7<<12)|(6<<4)|(9<<0),  //!< .
      TIM12_CH2_PH_9 = (TIM12_CH2<<16)|(7<<12)|(9<<4)|(9<<0),  //!< .
      TIM13_CH1_PA_6 = (TIM13_CH1<<16)|(0<<12)|(6<<4)|(9<<0),  //!< .
      TIM13_CH1_PF_8 = (TIM13_CH1<<16)|(5<<12)|(8<<4)|(9<<0),  //!< .
      TIM14_CH1_PA_7 = (TIM14_CH1<<16)|(0<<12)|(7<<4)|(9<<0),  //!< .
      TIM14_CH1_PF_9 = (TIM14_CH1<<16)|(5<<12)|(9<<4)|(9<<0),  //!< .
      TIM2_CH1_PA_0 = (TIM2_CH1<<16)|(0<<12)|(0<<4)|(1<<0),  //!< .
      TIM2_CH1_PA_5 = (TIM2_CH1<<16)|(0<<12)|(5<<4)|(1<<0),  //!< .
      TIM2_CH1_PA_15 = (TIM2_CH1<<16)|(0<<12)|(15<<4)|(1<<0),  //!< .
      TIM2_CH2_PA_1 = (TIM2_CH2<<16)|(0<<12)|(1<<4)|(1<<0),  //!< .
      TIM2_CH2_PB_3 = (TIM2_CH2<<16)|(1<<12)|(3<<4)|(1<<0),  //!< .
      TIM2_CH3_PA_2 = (TIM2_CH3<<16)|(0<<12)|(2<<4)|(1<<0),  //!< .
      TIM2_CH4_PA_3 = (TIM2_CH4<<16)|(0<<12)|(3<<4)|(1<<0),  //!< .
      TIM2_ETR_PA_0 = (TIM2_ETR<<16)|(0<<12)|(0<<4)|(1<<0),  //!< .
      TIM2_ETR_PA_5 = (TIM2_ETR<<16)|(0<<12)|(5<<4)|(1<<0),  //!< .
      TIM2_ETR_PA_15 = (TIM2_ETR<<16)|(0<<12)|(15<<4)|(1<<0),  //!< .
      TIM3_CH1_PA_6 = (TIM3_CH1<<16)|(0<<12)|(6<<4)|(2<<0),  //!< .
      TIM3_CH1_PB_4 = (TIM3_CH1<<16)|(1<<12)|(4<<4)|(2<<0),  //!< .
      TIM3_CH1_PC_6 = (TIM3_CH1<<16)|(2<<12)|(6<<4)|(2<<0),  //!< .
      TIM3_CH2_PA_7 = (TIM3_CH2<<16)|(0<<12)|(7<<4)|(2<<0),  //!< .
      TIM3_CH2_PB_5 = (TIM3_CH2<<16)|(1<<12)|(5<<4)|(2<<0),  //!< .
      TIM3_CH2_PC_7 = (TIM3_CH2<<16)|(2<<12)|(7<<4)|(2<<0),  //!< .
      TIM3_CH3_PB_0 = (TIM3_CH3<<16)|(1<<12)|(0<<4)|(2<<0),  //!< .
      TIM3_CH3_PC_8 = (TIM3_CH3<<16)|(2<<12)|(8<<4)|(2<<0),  //!< .
      TIM3_CH4_PB_1 = (TIM3_CH4<<16)|(1<<12)|(1<<4)|(2<<0),  //!< .
      TIM3_CH4_PC_9 = (TIM3_CH4<<16)|(2<<12)|(9<<4)|(2<<0),  //!< .
      TIM3_ETR_PD_2 = (TIM3_ETR<<16)|(3<<12)|(2<<4)|(2<<0),  //!< .
      TIM4_CH1_PB_6 = (TIM4_CH1<<16)|(1<<12)|(6<<4)|(2<<0),  //!< .
      TIM4_CH1LP_PD_12 = (TIM4_CH1LP<<16)|(3<<12)|(12<<4)|(2<<0),  //!< .
      TIM4_CH2_PD_13 = (TIM4_CH2<<16)|(3<<12)|(13<<4)|(2<<0),  //!< .
      TIM4_CH3_PD_14 = (TIM4_CH3<<16)|(3<<12)|(14<<4)|(2<<0),  //!< .
      TIM4_CH4_PD_15 = (TIM4_CH4<<16)|(3<<12)|(15<<4)|(2<<0),  //!< .
      TIM4_ETR_PE_0 = (TIM4_ETR<<16)|(4<<12)|(0<<4)|(2<<0),  //!< .
      TIM5_CH1_PA_0 = (TIM5_CH1<<16)|(0<<12)|(0<<4)|(2<<0),  //!< .
      TIM5_CH1_PH_10 = (TIM5_CH1<<16)|(7<<12)|(10<<4)|(2<<0),  //!< .
      TIM5_CH2_PA_1 = (TIM5_CH2<<16)|(0<<12)|(1<<4)|(2<<0),  //!< .
      TIM5_CH2_PH_11 = (TIM5_CH2<<16)|(7<<12)|(11<<4)|(2<<0),  //!< .
      TIM5_CH3_PA_2 = (TIM5_CH3<<16)|(0<<12)|(2<<4)|(2<<0),  //!< .
      TIM5_CH3_PH_12 = (TIM5_CH3<<16)|(7<<12)|(12<<4)|(2<<0),  //!< .
      TIM5_CH4_PA_3 = (TIM5_CH4<<16)|(0<<12)|(3<<4)|(2<<0),  //!< .
      TIM5_CH4_PI_0 = (TIM5_CH4<<16)|(8<<12)|(0<<4)|(2<<0),  //!< .
      TIM8_BKIN_PA_6 = (TIM8_BKIN<<16)|(0<<12)|(6<<4)|(3<<0),  //!< .
      TIM8_BKIN_PI_4 = (TIM8_BKIN<<16)|(8<<12)|(4<<4)|(3<<0),  //!< .
      TIM8_BKIN2_PA_8 = (TIM8_BKIN2<<16)|(0<<12)|(8<<4)|(3<<0),  //!< .
      TIM8_BKIN2_PI_1 = (TIM8_BKIN2<<16)|(8<<12)|(1<<4)|(3<<0),  //!< .
      TIM8_CH1_PC_6 = (TIM8_CH1<<16)|(2<<12)|(6<<4)|(3<<0),  //!< .
      TIM8_CH1_PI_5 = (TIM8_CH1<<16)|(8<<12)|(5<<4)|(3<<0),  //!< .
      TIM8_CH1N_PA_5 = (TIM8_CH1N<<16)|(0<<12)|(5<<4)|(3<<0),  //!< .
      TIM8_CH1N_PA_7 = (TIM8_CH1N<<16)|(0<<12)|(7<<4)|(3<<0),  //!< .
      TIM8_CH1N_PH_13 = (TIM8_CH1N<<16)|(7<<12)|(13<<4)|(3<<0),  //!< .
      TIM8_CH2_PC_7 = (TIM8_CH2<<16)|(2<<12)|(7<<4)|(3<<0),  //!< .
      TIM8_CH2_PI_6 = (TIM8_CH2<<16)|(8<<12)|(6<<4)|(3<<0),  //!< .
      TIM8_CH2N_PB_0 = (TIM8_CH2N<<16)|(1<<12)|(0<<4)|(3<<0),  //!< .
      TIM8_CH2N_PH_14 = (TIM8_CH2N<<16)|(7<<12)|(14<<4)|(3<<0),  //!< .
      TIM8_CH3_PC_8 = (TIM8_CH3<<16)|(2<<12)|(8<<4)|(3<<0),  //!< .
      TIM8_CH3_PI_7 = (TIM8_CH3<<16)|(8<<12)|(7<<4)|(3<<0),  //!< .
      TIM8_CH3N_PB_1 = (TIM8_CH3N<<16)|(1<<12)|(1<<4)|(3<<0),  //!< .
      TIM8_CH3N_PH_15 = (TIM8_CH3N<<16)|(7<<12)|(15<<4)|(3<<0),  //!< .
      TIM8_CH4_PC_9 = (TIM8_CH4<<16)|(2<<12)|(9<<4)|(3<<0),  //!< .
      TIM8_CH4_PI_2 = (TIM8_CH4<<16)|(8<<12)|(2<<4)|(3<<0),  //!< .
      TIM8_ETR_PA_0 = (TIM8_ETR<<16)|(0<<12)|(0<<4)|(3<<0),  //!< .
      TIM8_ETR_PI_3 = (TIM8_ETR<<16)|(8<<12)|(3<<4)|(3<<0),  //!< .
      TIM9_CH1_PA_2 = (TIM9_CH1<<16)|(0<<12)|(2<<4)|(3<<0),  //!< .
      TIM9_CH1_PE_5 = (TIM9_CH1<<16)|(4<<12)|(5<<4)|(3<<0),  //!< .
      TIM9_CH2_PA_3 = (TIM9_CH2<<16)|(0<<12)|(3<<4)|(3<<0),  //!< .
      TIM9_CH2_PE_6 = (TIM9_CH2<<16)|(4<<12)|(6<<4)|(3<<0),  //!< .
      TRACECLK_PE_2 = (TRACECLK<<16)|(4<<12)|(2<<4)|(0<<0),  //!< .
      TRACED0_PC_1 = (TRACED0<<16)|(2<<12)|(1<<4)|(0<<0),  //!< .
      TRACED0_PE_3 = (TRACED0<<16)|(4<<12)|(3<<4)|(0<<0),  //!< .
      TRACED0_PG_13 = (TRACED0<<16)|(6<<12)|(13<<4)|(0<<0),  //!< .
      TRACED1_PC_8 = (TRACED1<<16)|(2<<12)|(8<<4)|(0<<0),  //!< .
      TRACED1_PE_4 = (TRACED1<<16)|(4<<12)|(4<<4)|(0<<0),  //!< .
      TRACED1_PG_14 = (TRACED1<<16)|(6<<12)|(14<<4)|(0<<0),  //!< .
      TRACED2_PD_2 = (TRACED2<<16)|(3<<12)|(2<<4)|(0<<0),  //!< .
      TRACED2_PE_5 = (TRACED2<<16)|(4<<12)|(5<<4)|(0<<0),  //!< .
      TRACED3_PC_12 = (TRACED3<<16)|(2<<12)|(12<<4)|(0<<0),  //!< .
      TRACED3_PE_6 = (TRACED3<<16)|(4<<12)|(6<<4)|(0<<0),  //!< .
      TRACESWO_PB_3 = (TRACESWO<<16)|(1<<12)|(3<<4)|(0<<0),  //!< .
      UART4_CTS_PB_0 = (UART4_CTS<<16)|(1<<12)|(0<<4)|(8<<0),  //!< .
      UART4_RTS_PA_15 = (UART4_RTS<<16)|(0<<12)|(15<<4)|(8<<0),  //!< .
      UART4_RX_PA_1 = (UART4_RX<<16)|(0<<12)|(1<<4)|(8<<0),  //!< .
      UART4_RX_PA_11 = (UART4_RX<<16)|(0<<12)|(11<<4)|(6<<0),  //!< .
      UART4_RX_PC_11 = (UART4_RX<<16)|(2<<12)|(11<<4)|(8<<0),  //!< .
      UART4_RX_PD_0 = (UART4_RX<<16)|(3<<12)|(0<<4)|(8<<0),  //!< .
      UART4_RX_PH_14 = (UART4_RX<<16)|(7<<12)|(14<<4)|(8<<0),  //!< .
      UART4_RX_PI_9 = (UART4_RX<<16)|(8<<12)|(9<<4)|(8<<0),  //!< .
      UART4_TX_PA_0 = (UART4_TX<<16)|(0<<12)|(0<<4)|(8<<0),  //!< .
      UART4_TX_PA_12 = (UART4_TX<<16)|(0<<12)|(12<<4)|(6<<0),  //!< .
      UART4_TX_PC_10 = (UART4_TX<<16)|(2<<12)|(10<<4)|(8<<0),  //!< .
      UART4_TX_PD_1 = (UART4_TX<<16)|(3<<12)|(1<<4)|(8<<0),  //!< .
      UART4_TX_PH_13 = (UART4_TX<<16)|(7<<12)|(13<<4)|(8<<0),  //!< .
      UART5_CTS_PC_9 = (UART5_CTS<<16)|(2<<12)|(9<<4)|(7<<0),  //!< .
      UART5_RTS_PC_8 = (UART5_RTS<<16)|(2<<12)|(8<<4)|(7<<0),  //!< .
      UART5_RX_PB_5 = (UART5_RX<<16)|(1<<12)|(5<<4)|(1<<0),  //!< .
      UART5_RX_PD_2 = (UART5_RX<<16)|(3<<12)|(2<<4)|(8<<0),  //!< .
      UART5_TX_PB_6 = (UART5_TX<<16)|(1<<12)|(6<<4)|(1<<0),  //!< .
      UART5_TX_PC_12 = (UART5_TX<<16)|(2<<12)|(12<<4)|(8<<0),  //!< .
      UART7_CTS_PE_10 = (UART7_CTS<<16)|(4<<12)|(10<<4)|(8<<0),  //!< .
      UART7_CTS_PF_9 = (UART7_CTS<<16)|(5<<12)|(9<<4)|(8<<0),  //!< .
      UART7_RTS_PE_9 = (UART7_RTS<<16)|(4<<12)|(9<<4)|(8<<0),  //!< .
      UART7_RTS_PF_8 = (UART7_RTS<<16)|(5<<12)|(8<<4)|(8<<0),  //!< .
      UART7_RX_PA_8 = (UART7_RX<<16)|(0<<12)|(8<<4)|(12<<0),  //!< .
      UART7_RX_PB_3 = (UART7_RX<<16)|(1<<12)|(3<<4)|(12<<0),  //!< .
      UART7_RX_PE_7 = (UART7_RX<<16)|(4<<12)|(7<<4)|(8<<0),  //!< .
      UART7_RX_PF_6 = (UART7_RX<<16)|(5<<12)|(6<<4)|(8<<0),  //!< .
      UART7_TX_PA_15 = (UART7_TX<<16)|(0<<12)|(15<<4)|(12<<0),  //!< .
      UART7_TX_PB_4 = (UART7_TX<<16)|(1<<12)|(4<<4)|(12<<0),  //!< .
      UART7_TX_PE_8 = (UART7_TX<<16)|(4<<12)|(8<<4)|(8<<0),  //!< .
      UART7_TX_PF_7 = (UART7_TX<<16)|(5<<12)|(7<<4)|(8<<0),  //!< .
      UART8_CTS_PD_14 = (UART8_CTS<<16)|(3<<12)|(14<<4)|(8<<0),  //!< .
      UART8_RTS_PD_15 = (UART8_RTS<<16)|(3<<12)|(15<<4)|(8<<0),  //!< .
      UART8_Rx_PE_0 = (UART8_Rx<<16)|(4<<12)|(0<<4)|(8<<0),  //!< .
      UART8_Tx_PE_1 = (UART8_Tx<<16)|(4<<12)|(1<<4)|(8<<0),  //!< .
      USART1_CK_PA_8 = (USART1_CK<<16)|(0<<12)|(8<<4)|(7<<0),  //!< .
      USART1_CTS_PA_11 = (USART1_CTS<<16)|(0<<12)|(11<<4)|(7<<0),  //!< .
      USART1_RTS_PA_12 = (USART1_RTS<<16)|(0<<12)|(12<<4)|(7<<0),  //!< .
      USART1_RX_PA_10 = (USART1_RX<<16)|(0<<12)|(10<<4)|(7<<0),  //!< .
      USART1_TX_PA_9 = (USART1_TX<<16)|(0<<12)|(9<<4)|(7<<0),  //!< .
      USART1_TX_PB_6 = (USART1_TX<<16)|(1<<12)|(6<<4)|(7<<0),  //!< .
      USART2_CK_PA_4 = (USART2_CK<<16)|(0<<12)|(4<<4)|(7<<0),  //!< .
      USART2_CK_PD_7 = (USART2_CK<<16)|(3<<12)|(7<<4)|(7<<0),  //!< .
      USART2_CTS_PA_0 = (USART2_CTS<<16)|(0<<12)|(0<<4)|(7<<0),  //!< .
      USART2_CTS_PD_3 = (USART2_CTS<<16)|(3<<12)|(3<<4)|(7<<0),  //!< .
      USART2_RTS_PA_1 = (USART2_RTS<<16)|(0<<12)|(1<<4)|(7<<0),  //!< .
      USART2_RTS_PD_4 = (USART2_RTS<<16)|(3<<12)|(4<<4)|(7<<0),  //!< .
      USART2_RX_PA_3 = (USART2_RX<<16)|(0<<12)|(3<<4)|(7<<0),  //!< .
      USART2_RX_PD_6 = (USART2_RX<<16)|(3<<12)|(6<<4)|(7<<0),  //!< .
      USART2_TX_PA_2 = (USART2_TX<<16)|(0<<12)|(2<<4)|(7<<0),  //!< .
      USART2_TX_PD_5 = (USART2_TX<<16)|(3<<12)|(5<<4)|(7<<0),  //!< .
      USART3_CK_PC_12 = (USART3_CK<<16)|(2<<12)|(12<<4)|(7<<0),  //!< .
      USART3_CK_PD_10 = (USART3_CK<<16)|(3<<12)|(10<<4)|(7<<0),  //!< .
      USART3_CTS_PD_11 = (USART3_CTS<<16)|(3<<12)|(11<<4)|(7<<0),  //!< .
      USART3_RTS_PD_12 = (USART3_RTS<<16)|(3<<12)|(12<<4)|(7<<0),  //!< .
      USART3_RX_PC_11 = (USART3_RX<<16)|(2<<12)|(11<<4)|(7<<0),  //!< .
      USART3_RX_PD_9 = (USART3_RX<<16)|(3<<12)|(9<<4)|(7<<0),  //!< .
      USART3_TX_PC_10 = (USART3_TX<<16)|(2<<12)|(10<<4)|(7<<0),  //!< .
      USART3_TX_PD_8 = (USART3_TX<<16)|(3<<12)|(8<<4)|(7<<0),  //!< .
      USART6_CK_PC_8 = (USART6_CK<<16)|(2<<12)|(8<<4)|(8<<0),  //!< .
      USART6_CK_PG_7 = (USART6_CK<<16)|(6<<12)|(7<<4)|(8<<0),  //!< .
      USART6_CTS_PG_13 = (USART6_CTS<<16)|(6<<12)|(13<<4)|(8<<0),  //!< .
      USART6_CTS_PG_15 = (USART6_CTS<<16)|(6<<12)|(15<<4)|(8<<0),  //!< .
      USART6_RTS_PG_8 = (USART6_RTS<<16)|(6<<12)|(8<<4)|(8<<0),  //!< .
      USART6_RTS_PG_12 = (USART6_RTS<<16)|(6<<12)|(12<<4)|(8<<0),  //!< .
      USART6_RX_PC_7 = (USART6_RX<<16)|(2<<12)|(7<<4)|(8<<0),  //!< .
      USART6_RX_PG_9 = (USART6_RX<<16)|(6<<12)|(9<<4)|(8<<0),  //!< .
      USART6_TX_PC_6 = (USART6_TX<<16)|(2<<12)|(6<<4)|(8<<0),  //!< .
      USART6_TX_PG_14 = (USART6_TX<<16)|(6<<12)|(14<<4)|(8<<0),  //!< .
      END_OF_TABLE     = 0
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
                     DWORD         mode, 
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

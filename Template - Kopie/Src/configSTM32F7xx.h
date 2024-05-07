//*******************************************************************
// STM32L1xx
//*******************************************************************

//-------------------------------------------------------------------
#include "Peripheral/Disp_OTM8009A.h"

//-------------------------------------------------------------------
#include "Com/Hardware/Display/Font/Font_8x12.h"
#include "Com/Hardware/Display/Font/Font_10x20.h"
#include "Com/Hardware/Display/Font/Font_16x24.h"

//-------------------------------------------------------------------
cSystem sys;

//-------------------------------------------------------------------
cHwPinConfig::MAP cHwPinConfig::table[] =
{
  // ADC
  ADC3_IN8_PF_10,
  ADC3_IN12_PC_2,

  // DAC
  DAC_OUT1_PA_4,

  // UART
  USART1_RX_PA_10,
  USART1_TX_PA_9,

  UART5_RX_PD_2,
  UART5_TX_PC_12,

  USART6_RX_PC_7,
  USART6_TX_PC_6,

  // I2C
  I2C4_SCL_PD_12,
  I2C4_SDA_PB_7,

  //FMC
  FMC_D0_PD_14,  
  FMC_D1_PD_15,  
  FMC_D2_PD_0, 
  FMC_D3_PD_1,
  FMC_D4_PE_7,
  FMC_D5_PE_8, 
  FMC_D6_PE_9, 
  FMC_D7_PE_10, 
  FMC_D8_PE_11, 
  FMC_D9_PE_12, 
  FMC_D10_PE_13, 
  FMC_D11_PE_14, 
  FMC_D12_PE_15,
  FMC_D13_PD_8,  
  FMC_D14_PD_9,
  FMC_D15_PD_10,  
  FMC_D16_PH_8,
  FMC_D17_PH_9,
  FMC_D18_PH_10,
  FMC_D19_PH_11,
  FMC_D20_PH_12,
  FMC_D21_PH_13,
  FMC_D22_PH_14,
  FMC_D23_PH_15,
  FMC_D24_PI_0,
  FMC_D25_PI_1,
  FMC_D26_PI_2,
  FMC_D27_PI_3,
  FMC_D28_PI_6,
  FMC_D29_PI_7,
  FMC_D30_PI_9,
  FMC_D31_PI_10,

  FMC_A0_PF_0,
  FMC_A1_PF_1,
  FMC_A2_PF_2,
  FMC_A3_PF_3,
  FMC_A4_PF_4,
  FMC_A5_PF_5,
  FMC_A6_PF_12,
  FMC_A7_PF_13,
  FMC_A8_PF_14,
  FMC_A9_PF_15,
  FMC_A10_PG_0,
  FMC_A11_PG_1,
  FMC_A12_PG_2,
  FMC_A13_PG_3,
  FMC_A14_PG_4,
  FMC_A15_PG_5,

  FMC_SDCLK_PG_8,
  FMC_SDNCAS_PG_15,
  FMC_SDCKE0_PH_2,
  FMC_SDNE0_PH_3,
  FMC_SDNWE_PH_5,
  FMC_SDNRAS_PF_11,
  FMC_NBL0_PE_0,
  FMC_NBL1_PE_1, 
  FMC_NBL2_PI_4,
  FMC_NBL3_PI_5,


  END_OF_TABLE
};

//- Timer------------------------------------------------------------
cHwTimer_N timerFast ( cHwTimer_N::TIM_4,  1000L/*us*/ );
cHwTimer_N timerSlow ( cHwTimer_N::TIM_2, 10000L/*us*/ );

//- Digital Port ----------------------------------------------------
cHwPort_N  portA( cHwPort_N::PA );
cHwPort_N  portB( cHwPort_N::PB );
cHwPort_N  portC( cHwPort_N::PC );
cHwPort_N  portD( cHwPort_N::PD );
cHwPort_N  portE( cHwPort_N::PE );
cHwPort_N  portF( cHwPort_N::PF );
cHwPort_N  portI( cHwPort_N::PI );
cHwPort_N  portJ( cHwPort_N::PJ );

//- Analog Input ----------------------------------------------------
cHwADC_0    adc0( &timerFast );
cHwADC     &adc = adc0;

//- Analog Output ---------------------------------------------------
cHwDAC_0    dac0;
cHwDAC     &dac = dac0;

//- Display ---------------------------------------------------------
cHwFMC fmc(cHwFMC::SDRAM_Bank1);  
cHwDSI hwDSI( fmc.startAddr() );
cHwPort::Pin   lcdResetPin( portJ, 15 );
                         
cHwDisp_OTM8009Aram dispHw( hwDSI,lcdResetPin, 
                            cHwDisp_OTM8009A::LANDSCAPE_90, 
                            fontFont_8x12, 2 );

cDevDisplayGraphic disp( dispHw );

//- Joystick/Drehknopf ----------------------------------------------
cDevDigital    btnLeft ( portF, 8, cDevDigital::InPU, 1 );
cDevDigital    btnCtrl ( portF, 9, cDevDigital::InPU, 1 );
cDevDigital    btnRight( portA, 6, cDevDigital::InPU, 1 );

cDevControlEncoderJoystick enc( &btnLeft, &btnRight, &btnCtrl, &timerFast );

//- Button/Switch ---------------------------------------------------
cDevDigital    switch0 ( portA, 0, cDevDigital::InPU  , 0 );
cDevDigital   &btnPlus  = btnLeft;  // HW hat zu wenige Buttons, daher müssen
cDevDigital   &btnMinus = btnRight; // einige Buttons doppelt genutzt werden 

//- LED -------------------------------------------------------------
cDevDigital    led0    ( portJ, 13, cDevDigital::Out,  0 );;

//EOF

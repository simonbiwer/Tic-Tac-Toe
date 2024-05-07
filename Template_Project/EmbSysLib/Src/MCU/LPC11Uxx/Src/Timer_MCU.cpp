//*******************************************************************
/*!
\file   Timer_MCU.cpp
\author Thomas Breuer
\date   14.02.2011
*/

//*******************************************************************
//
// cHwTimer_N
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_TIM != 48000000 )
  #error "system_PCLK_TIM not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwTimer_N *cHwTimer_N::timerCT16B0_Ptr = 0;
cHwTimer_N *cHwTimer_N::timerCT16B1_Ptr = 0;
cHwTimer_N *cHwTimer_N::timerCT32B0_Ptr = 0;
cHwTimer_N *cHwTimer_N::timerCT32B1_Ptr = 0;

//-------------------------------------------------------------------
cHwTimer_N::cHwTimer_N( TIM_ID  idIn,
                        DWORD   cycleTimeIn )

: cHwTimer()

{
  id = idIn;

  switch(id)
  {
    default:
      // error!
      break;
    case CT16B0: timerCT16B0_Ptr = this;
                 ptr = LPC_CT16B0;
                 NVIC_EnableIRQ( TIMER_16_0_IRQn );
                 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<7);
                 break;

    case CT16B1: timerCT16B1_Ptr = this;
                 ptr = LPC_CT16B1;
                 NVIC_EnableIRQ( TIMER_16_1_IRQn );
                 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<8);
                 break;

    case CT32B0: timerCT32B0_Ptr = this;
                 ptr = LPC_CT32B0;
                 NVIC_EnableIRQ( TIMER_32_0_IRQn );
                 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9);
                 break;

    case CT32B1: timerCT32B1_Ptr = this;
                 ptr = LPC_CT32B1;
                 NVIC_EnableIRQ( TIMER_32_1_IRQn );
                 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<10);
                 break;
  }

  // calculate tics and prescaler
  float rawTics = (float)system_PCLK_TIM * cycleTimeIn * 1E-6;
  DWORD ps      = 1;
  while( rawTics > 0xFFFF ) // tics must be < 16Bits
  {
    ps      *= 10;
    rawTics /= 10;
  }

  tics      = (DWORD)rawTics;
  cycleTime = (DWORD)(1E6 * tics * ps / (float)system_PCLK_TIM);

  ptr->PR = ps - 1;         // Prescale Register

  ptr->MR3 = tics;      // match register 3

  ptr->MCR =  (1<<9)   // interrupt on match compare
             |(1<<10);  // reset timer on match compare

  ptr->TCR =  (1<<0)    // counter enable
             |(1<<3);   // PWM enable

}

//-------------------------------------------------------------------
void cHwTimer_N::enablePWM( BYTE ch, cHwTimer::Mode mode )
{
  switch( id )
  {
    case CT16B0:
      switch(ch)
      {
        case 0: cHwPinConfig::set( cHwPinConfig::CT16B0_MAT0, cHwPinConfig::PU ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::CT16B0_MAT1, cHwPinConfig::PU ); break;
        case 2: cHwPinConfig::set( cHwPinConfig::CT16B0_MAT2, cHwPinConfig::PU ); break;
      }
      break;

    case CT16B1:
      switch(ch)
      {
        case 0: cHwPinConfig::set( cHwPinConfig::CT16B1_MAT0, cHwPinConfig::PU ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::CT16B1_MAT1, cHwPinConfig::PU ); break;
      }
      break;

    case CT32B0:
      switch(ch)
      {
        case 0: cHwPinConfig::set( cHwPinConfig::CT32B0_MAT0, cHwPinConfig::PU ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::CT32B0_MAT1, cHwPinConfig::PU ); break;
        case 2: cHwPinConfig::set( cHwPinConfig::CT32B0_MAT2, cHwPinConfig::PU ); break;
        case 3: cHwPinConfig::set( cHwPinConfig::CT32B0_MAT3, cHwPinConfig::PU ); break;
      }
      break;

    case CT32B1:
      switch(ch)
      {
        case 0: cHwPinConfig::set( cHwPinConfig::CT32B1_MAT0, cHwPinConfig::PU ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::CT32B1_MAT1, cHwPinConfig::PU ); break;
        case 2: cHwPinConfig::set( cHwPinConfig::CT32B1_MAT2, cHwPinConfig::PU ); break;
        case 3: cHwPinConfig::set( cHwPinConfig::CT32B1_MAT3, cHwPinConfig::PU ); break;
      }
      break;
  }

  ptr->PWMC |= (1<<ch);
}

//-------------------------------------------------------------------
void cHwTimer_N::setPWM( WORD value, BYTE ch )
{
  value = (WORD)((unsigned long)(0xFFFF - value)*tics >> 16);

  switch( ch )
  {
    case 0: ptr->MR0  = value; break;
    case 1: ptr->MR1  = value; break;
    case 2: ptr->MR2  = value; break;
  }
}

//-------------------------------------------------------------------
void cHwTimer_N::irq( void )
{
    // use IR to identify interrupt source
    if(ptr->IR & (1<<3))
    {
      ptr->IR = (1<<3); // clear request by writing a logic '1'(!!!)
      isrHandler();
    }
    else
    {
      ptr->IR = ptr->IR; // clear request by writing a logic '1'(!!!)
    }
}

//-------------------------------------------------------------------
extern "C" {
  void TIMER16_0_IRQHandler(void)
  {
    cHwTimer_N::timerCT16B0_Ptr->irq();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIMER16_1_IRQHandler(void)
  {
    cHwTimer_N::timerCT16B1_Ptr->irq();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIMER32_0_IRQHandler(void)
  {
    cHwTimer_N::timerCT32B0_Ptr->irq();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIMER32_1_IRQHandler(void)
  {
    cHwTimer_N::timerCT32B1_Ptr->irq();
  }
}

//EOF

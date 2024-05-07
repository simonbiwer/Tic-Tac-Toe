//*******************************************************************
/*!
\file   .cpp
\author Thomas Breuer
\date


*/

//*******************************************************************
//
// cHwRTOS_MCU
//
//*******************************************************************

DWORD (*cHwRTOS_MCU::schedule)( DWORD sp, BYTE flag ) = 0;
unsigned long  cHwRTOS_MCU::sysTic = 0;
unsigned       cHwRTOS_MCU::sysTicTime = 0;


//-------------------------------------------------------------------
cHwRTOS_MCU::cHwRTOS_MCU( void
                          )


{
}

//-------------------------------------------------------------------
extern "C"
{
  void     load_context(unsigned ptr);
  unsigned save_context(void);
}

//###################################################################
#ifdef _KEIL
  #pragma push
  #pragma O0
#elif defined _GCC
  #pragma GCC push_options
  #pragma GCC optimize ("O0")
#else
  #error "no compiler definition"
#endif
//###################################################################

//-------------------------------------------------------------------
extern "C"
{
  void SysTick_Handler( void )
  {
    static unsigned stackPointer = 0;

    stackPointer = save_context();
    cHwRTOS_MCU::sysTic++;
    //sp = cRTOS::ptr->scheduler(sp, true);
    stackPointer = cHwRTOS_MCU::schedule( stackPointer, true );

    load_context( stackPointer );
  }
}

//-------------------------------------------------------------------
extern "C"
{
  void PendSV_Handler( void )
  {
    static unsigned stackPointer = 0;

    stackPointer = save_context();

    // sp = cRTOS::ptr->scheduler(sp, false);


    stackPointer = cHwRTOS_MCU::schedule( stackPointer, false );

    load_context( stackPointer );
  }
}

//###################################################################
#ifdef _KEIL
  #pragma pop
#elif defined _GCC
  #pragma GCC pop_options
#else
  #error "no compiler definition"
#endif
//###################################################################

//EOF

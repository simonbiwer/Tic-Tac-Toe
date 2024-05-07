//*******************************************************************
/*!
\file   RTOS_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_RTOS_MCU_H
#define _HW_RTOS_MCU_H

//-------------------------------------------------------------------
#if ( system_PCLK_SYSTIC != 84000000 )
  #error "system_PCLK_SYSTIC not defined or wrong value"
#endif

//-------------------------------------------------------------------
#define MAIN_RETURN   0xFFFFFFF9  //Tells the handler to return using the MSP
#define THREAD_RETURN 0xFFFFFFFD  //Tells the handler to return using the PSP

//*******************************************************************
/*!
\class cHwRTOS_MCU

\brief Interupt and context switching used by RTOS

\see http://coactionos.com/embedded%20design%20tips/2013/10/09/Tips-Context-Switching-on-the-Cortex-M3/

\example cHwRTOS.cpp
*/
class cHwRTOS_MCU
{
  private:
    //---------------------------------------------------------------
    typedef struct
    {
      struct
      {
        float s[32];
      } fpu;

      struct
      {
        uint32_t r4;
        uint32_t r5;
        uint32_t r6;
        uint32_t r7;
        uint32_t r8;
        uint32_t r9;
        uint32_t r10;
        uint32_t r11;
      } sw;

      struct
      {
        uint32_t r4;
        uint32_t lr_pc;
      } add;

      struct
      {
        uint32_t r0;
        uint32_t r1;
        uint32_t r2;
        uint32_t r3;
        uint32_t r12;
        uint32_t lr;
        uint32_t pc;
        uint32_t psr;
      } hw;

    } StackFrame;

  public:
    //---------------------------------------------------------------
    /*! Instantiate RTOS
    */
    cHwRTOS_MCU( void );

    //---------------------------------------------------------------
    /*! Initialize RTOS related hardware
  
        The scheduler is called by SysTick interrupt with parameter 
        flag=true or by PendSV interrupt with flag=false after saving 
        the context and before loading the next context.
        The parameter sp must be the stack pointer of the current 
        context. The scheduler has to return the stack pointer where 
        to switch the context.           
        \param us         System tick cycle time in microseconds
        \param scheduleIn Function pointer to the scheduler
    */
    static void init( WORD us, DWORD (*scheduleIn)( DWORD sp, BYTE flag ))
    {
      schedule = scheduleIn;

      SysTick->CTRL =   SysTick_CTRL_ENABLE_Msk
                      | SysTick_CTRL_TICKINT_Msk
                      | SysTick_CTRL_CLKSOURCE_Msk;

      SysTick->LOAD = (1E-6 * system_PCLK_SYSTIC * us) - 1;

			sysTicTime = us;
    }

    //---------------------------------------------------------------
    /*! Start a RTOS task
    
        Initialize stack frame and start a task by calling the 
        function \b starter
        
        \param stackAddrIn Address of stack memory
        \param stackSizeIn Size of stack memory
        \param arg         Pointer to arguments of the \b starter 
                           function
        \param starter     Function pointer
        \return Current stack pointer
    */
    static unsigned start( char     *stackAddrIn,
                           unsigned  stackSizeIn,
                           void     *arg,
                           DWORD   (*startFunc)(void *) )
    {
      void *stackAddr = (void*)( ( (unsigned)stackAddrIn+3) & ~0x03 ); // gerade adrersse erzwingen
      int   stackSize = stackSizeIn - 4;

      StackFrame *stack = (StackFrame *)((unsigned)stackAddr + stackSize - sizeof(StackFrame));

      stack->hw.r0  = (uint32_t)arg;
      stack->hw.r1  = 0;
      stack->hw.r2  = 0;
      stack->hw.r3  = 0;
      stack->hw.r12 = 0;
      stack->hw.pc  = ((uint32_t)startFunc ) & ~0x01;
      stack->hw.lr  = ((uint32_t)deleteFunc) & ~0x01;
      stack->hw.psr = 0x21000000; //default PSR value

      stack->sw.r4  = 0;
      stack->sw.r5  = 0;
      stack->sw.r6  = 0;
      stack->sw.r7  = 0;
      stack->sw.r8  = 0;
      stack->sw.r9  = 0;
      stack->sw.r10 = 0;
      stack->sw.r11 = 0;

      stack->add.r4    = 0;
      stack->add.lr_pc = MAIN_RETURN;

      for( int i = 0; i < 32; i++ )
      {
        stack->fpu.s[i] = 0;
      }

      return( (unsigned)stackAddr + stackSize - sizeof(StackFrame) );
    }

    //---------------------------------------------------------------
    /*! Stop a task
    
        Here we can't stop a task, but we can switch the context
        \para id Task ID, reserved for future use
    */
    static void stop( DWORD id )
    {
      SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk; //switch the context
    }

    //---------------------------------------------------------------
    /*! Pause a task
    
        Here we can't pause a task, but we can switch the context
    */
    static void pause( void )
    {
      SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk; //switch the context
    }

		//---------------------------------------------------------------
    /*! Get the system time (measured by system tick)
    
        \return System time in milliseconds
    */
		//---------------------------------------------------------------
    static unsigned long getSysTime( void )
		{
			return( (unsigned long)((unsigned long long)sysTic*sysTicTime/1000) );
		}

    //---------------------------------------------------------------
    /*! This is called when the task returns
    */
    static void deleteFunc( void )
    {
      while(1);
    }

  public:    
    //---------------------------------------------------------------
    static DWORD (*schedule)( DWORD sp, BYTE flag );

  public:
    //---------------------------------------------------------------
    static unsigned long  sysTic;
    static unsigned       sysTicTime;

}; //cHwRTOS_MCU

#endif

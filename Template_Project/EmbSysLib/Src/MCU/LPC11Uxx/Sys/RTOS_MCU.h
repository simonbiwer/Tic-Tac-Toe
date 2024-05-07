//*******************************************************************
/*!
\file   RTOS_MCU.h
\author Thomas Breuer
\date
*/

//*******************************************************************
#ifndef _HW_RTOS_MCU_H
#define _HW_RTOS_MCU_H

//*******************************************************************
//#include "Hardware/Common/SPImaster.h"

//-------------------------------------------------------------------
#if ( system_PCLK_SYSTIC != 48000000 )
  #error "system_PCLK_SYSTIC not defined or wrong value"
#endif

//-------------------------------------------------------------------
typedef struct
{
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

} stack_frame_t;

//-------------------------------------------------------------------
#define MAIN_RETURN   0xFFFFFFF9  //Tells the handler to return using the MSP
#define THREAD_RETURN 0xFFFFFFFD  //Tells the handler to return using the PSP


//*******************************************************************
/*!
\class cHwRTOS_MCU

\brief

\example
*/
class cHwRTOS_MCU
{
  public:
    //---------------------------------------------------------------

  public:
    //---------------------------------------------------------------
    /*!
    */
    cHwRTOS_MCU( void );

    static void init( WORD us, DWORD (*scheduleIn)( DWORD sp, BYTE flag ))
    {
      schedule = scheduleIn;


      SysTick->CTRL =  SysTick_CTRL_ENABLE_Msk
                 | SysTick_CTRL_TICKINT_Msk
                 | SysTick_CTRL_CLKSOURCE_Msk;

        SysTick->LOAD = (1E-6 * system_PCLK_SYSTIC * us) - 1;

			sysTicTime = us;
    }


    static unsigned start( char     *stackAddrIn,
                       unsigned  stackSizeIn,
                       void *  arg,
                       DWORD (*starter)(void *) )  //uint32_t  starter )
    {
      void *stackaddr = (void*)(  ((unsigned)stackAddrIn+3) & ~0x03); // gerade adrersse erzwingen
      int stack_size = stackSizeIn - 4;

      stack_frame_t *process_frame = (stack_frame_t *)((unsigned)stackaddr + stack_size - sizeof(stack_frame_t));

      process_frame->hw.r0  = (uint32_t)arg;
      process_frame->hw.r1  = 0;
      process_frame->hw.r2  = 0;
      process_frame->hw.r3  = 0;
      process_frame->hw.r12 = 0;
      process_frame->hw.pc  = ((uint32_t)starter) & ~0x01;
      process_frame->hw.lr  = ((uint32_t)del_process) & ~0x01;
      process_frame->hw.psr = 0x21000000; //default PSR value

      process_frame->sw.r4  = 0;
      process_frame->sw.r5  = 0;
      process_frame->sw.r6  = 0;
      process_frame->sw.r7  = 0;
      process_frame->sw.r8  = 0;
      process_frame->sw.r9  = 0;
      process_frame->sw.r10 = 0;
      process_frame->sw.r11 = 0;

      process_frame->add.r4 = 0;
      process_frame->add.lr_pc = MAIN_RETURN;

      return( (unsigned) stackaddr + stack_size - sizeof(stack_frame_t) );

    }

    static void stop(DWORD id)
    {
      SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk; //switch the context
    }

    static void pause()
    {
      SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
    }

		//---------------------------------------------------------------
    static unsigned long getSysTime( void )
		{
			return( (unsigned long)((unsigned long long)sysTic*sysTicTime/1000) );
		}



    static DWORD (*schedule)( DWORD sp, BYTE flag );

    static unsigned long  sysTic;
    static unsigned       sysTicTime;

//-------------------------------------------------------------------
//This is called when the task returns
static void del_process( void )
{

//  task_table[current_task].flags = 0; //clear the in use and exec flags
//  SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk; //switch the context
//  while(1); //once the context changes, the program will no longer return to this thread

 //// cRTOS::ptr->taskStop();
  while(1);
}


}; //cHwRTOS_MCU

#endif

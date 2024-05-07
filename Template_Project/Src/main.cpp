//*******************************************************************
#include "lib.h"
#include "Module/RTOS.h"
#include "View.h"
#include "Controller.h"

//*******************************************************************
#if defined _MCU_TYPE_STM32L1XX
  #include "configSTM32L1xx.h"
#elif defined _MCU_TYPE_STM32F7XX
  #include "configSTM32F7xx.h"
#elif defined _MCU_TYPE_LPC1758
  #include "configLPC1758.h"
#elif defined _MCU_TYPE_VIRTUAL
  #include "configVirtual.h"
#else
  #error "Device type not defined"
#endif

//*******************************************************************
class cTask_Example : public cTaskHandler::Task
{
  public:
    //---------------------------------------------------------------
    unsigned cnt;
    //---------------------------------------------------------------
    cTask_Example(cTaskHandler &taskHandler)
    : Task(taskHandler)
    {
      cnt = 0;
    }

  private:
    //---------------------------------------------------------------
    virtual void update(void)
    {
      cnt++;
    }
};

//*******************************************************************
class cRtosTask_Example : public cRTOS::Task
{
  public:
    //---------------------------------------------------------------
    cRtosTask_Example(cRTOS &rtosIn )

    : cRTOS::Task( rtosIn, 500/* stack size*/ )

    {
      sec = 0;
      Start();
    }

    //---------------------------------------------------------------
    virtual ~cRtosTask_Example()
    {
    }

    //---------------------------------------------------------------
    virtual void update( )
    {
      while( 1 )
      {
        Pause( 10 );
        if( timer.timeout() )
        {
          sec+=0.1f;
        }
      }
    }

    //---------------------------------------------------------------
    virtual void OnStop(void)
    {
    }

    //---------------------------------------------------------------
    virtual void OnStart(void)
    {
      timer.start( 100 );
    }

    //---------------------------------------------------------------
    float   sec;

    cRTOS::Timer timer;
};


//*******************************************************************
cTaskHandler  taskHandler(&timer);

cTask_Example task_Example(taskHandler);

//*******************************************************************
cRTOS_RR<3> rtos( 100/*time per task [ms]*/ );

cRtosTask_Example  rtos_task_Example( rtos );

//*******************************************************************
int main(void)
{
  int num = 0;
	
	Controller controller(disp);
	controller.setUpStartView();
	

  while(1)
  {
    switch( enc.get() )
    {
        case cDevControlEncoder::LEFT:     num -= 1; break;
        case cDevControlEncoder::RIGHT:    num += 1; break;
        case cDevControlEncoder::CTRL_DWN: num  = 0; break;
        default:                                     break;
    }

    cHwRTC::Properties prop;
    rtc.get( prop );

    disp.printf(1,0,20,"Timer-Task: %d",   task_Example.cnt );
    disp.printf(2,0,20,"RTOS-Task:  %.1f", rtos_task_Example.sec );
    disp.printf(3,0,20,"BTN:%d Enc:%2d RTC:%2d", btn.get(),num, prop.second );

    if( btn.getEvent() == cDevDigital::ACTIVATED )
    {
      led.toggle();
    }

    dacA.set( adcA.get() );
		
		cDevControlPointer::cData event = pointer.get();
//		disp.refresh();
		
		if (!controller.gameRunning){
			controller.beforeGame(event);
		} else {
			controller.duringGame(event);
		}
	}
}

//EOF

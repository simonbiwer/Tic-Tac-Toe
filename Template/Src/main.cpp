//*******************************************************************
#include "lib.h"

//*******************************************************************
#if defined _MCU_TYPE_LPC17XX
  #include "configLPC17xx.h"
#elif defined _MCU_TYPE_STM32L1XX
  #include "configSTM32L1xx.h"
#elif defined _MCU_TYPE_STM32F7XX
  #include "configSTM32F7xx.h"
#elif defined _MCU_TYPE_VIRTUAL
  #include "configVirtual.h"
#else
  #error "Device type not defined"
#endif

//*******************************************************************
int main(void)
{
  int  cnt = 0;
  int  num = 0;
  int  val = 0;
  bool sw0 = false;

  adc.enable(2);
  dac.enable(0);

  disp.printf(0,0,0,__DATE__ " " __TIME__);
  disp.printf(1,0,0,"Hello world!");

  while(1)
  {
    // evaluate input
    //---------------
    if( btnPlus.get() )
    {
      cnt++;
    }

    if( btnMinus.getEvent() == cDevDigital::ACTIVATED )
    {
      cnt = 0;
    }

    switch( enc.get() )
    {
        case cDevControlEncoder::LEFT:     num -= 1; break;
        case cDevControlEncoder::RIGHT:    num += 1; break;
        case cDevControlEncoder::CTRL_DWN: num  = 0; break;
        default:                                     break;
    }

    val = adc.get(2);

    sw0 = switch0.get();

    // set output
    //-----------
    led0.set(sw0);

    dac.set(num*1000, 0);

    disp.printf(2, 0,10,"cnt:%d",cnt);
    disp.printf(2,10,10,"num:%d",num);
    disp.printf(3, 0,10,"val:%d",val);
    disp.printf(3,10,10,"sw0:%d",sw0);
    disp.refresh();
  }
}

class AnalogInADC{
	
	private:
		const int kanal;
		static int anzahl = 0;
	
	public:	
	
		AnalogInADC(int kanal){
			this->kanal = kanal;
			adc.enable(kanal);
			anzahl++;
		}
		
		unsigned short getValue(){
			return adc.get(kanal);
		}
		
		~AnalogInADC(){
			anzahl--;
		}
};

class AnalogOutDAC{
	
	private:
		int kanal;
	
	public:
		
		AnalogOutDAC(int kanal){
			this->kanal = kanal;
			dac.enable(kanal);
		}
		void enterValue(unsigned short value){
		dac.set(value, kanal);
		}
};
//EOF

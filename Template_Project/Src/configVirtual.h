//*******************************************************************
// Virtual
//*******************************************************************

#include "Com/Hardware/Display/Font/Font_8x12.h"

//-------------------------------------------------------------------
cSystem sys;

//-------------------------------------------------------------------
cNetWin  net;
cNetUDP  udp( net );
cNetTCP  tcp( net );

cNetAddr<4> server = {127,0,0,1};

//- Timer------------------------------------------------------------
cHwTimer_MCU   timer( 10000/*us*/ );
cHwTimer      &timerPWM = timer;

//- Digital Port ----------------------------------------------------
cHwPort_Virtual port( server,1000);

//- Analog In -------------------------------------------------------
cHwADC_Virtual   adcHw( server, 1002, &timer);
cDevAnalogInADC  adcA( adcHw, 0, 3.3, 0.0 );

//- Analog OutIn ----------------------------------------------------
cHwDAC_Virtual   dacHw( server, 1002);
cDevAnalogOutDAC dacA( dacHw, 1, 3.3, 0.0 );

//- Display ---------------------------------------------------------
#ifdef USE_CHARACTER_DISPLAY
  cHwDispChar_Virtual    dispHw( server, 1001 );
  cDevDisplayChar        disp  ( dispHw );
#elif defined USE_GRAPHIC_DISPLAY
  cHwDisp_Virtual        dispHw( server, 1001,fontFont_8x12, 1  );
  cDevDisplayGraphic     disp  ( dispHw );
#endif

//- Touch -----------------------------------------------------------
#ifdef USE_GRAPHIC_DISPLAY
  cHwTouch_Virtual    touch( server, 1001, 320, 240 );
  cDevControlPointer  pointer( touch );
#endif

//- Joystick --------------------------------------------------------
cDevDigital    btnLeft ( port, 0,cDevDigital::In, 0 );
cDevDigital    btnCtrl ( port, 1,cDevDigital::In, 0 );
cDevDigital    btnRight( port, 2,cDevDigital::In, 0 );

cDevControlEncoderJoystick enc( &btnLeft, &btnRight, &btnCtrl, &timer, 120 );

//- Button ----------------------------------------------------------
cDevDigital    btn( port, 5,cDevDigital::In, 0 );

//- LED -------------------------------------------------------------
cDevDigital    led( port, 8, cDevDigital::Out, 0 );

//- Real Time Clock (RTC) -------------------------------------------
cHwRTC_0         rtc;

//EOF

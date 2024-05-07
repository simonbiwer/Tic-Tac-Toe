//*******************************************************************
// Virtual
//*******************************************************************

//-------------------------------------------------------------------
#include "Com/Hardware/Display/Font/Font_8x12.h"
#include "Com/Hardware/Display/Font/Font_10x20.h"
#include "Com/Hardware/Display/Font/Font_16x24.h"

//-------------------------------------------------------------------
cSystem sys;

//-------------------------------------------------------------------
cNetWin  net;
cNetUDP  udp( net );
cNetTCP  tcp( net );

cNetAddr<4> server = {127,0,0,1};

//- Timer------------------------------------------------------------

cHwTimer_MCU   timerSlow( 10000/*us*/ );
cHwTimer      &timerPWM = timerSlow;

//- Digital Port ----------------------------------------------------
cHwPort_Virtual port( server,1000);

//- Analog Input ----------------------------------------------------
cHwADC_Virtual adc0( server, 1002, &timerSlow);
cHwADC         &adc = adc0;

//- Analog Output ---------------------------------------------------
cHwDAC_Virtual dac0( server, 1002);
cHwDAC         &dac = dac0;

//- Display ---------------------------------------------------------
cHwDispChar_Virtual dispHw( server, 1001 );
cDevDisplayChar     disp  ( dispHw );
//- Joystick/Drehknopf ----------------------------------------------
cDevDigital    btnLeft ( port, 0,cDevDigital::In, 0 );
cDevDigital    btnCtrl ( port, 1,cDevDigital::In, 0 );
cDevDigital    btnRight( port, 2,cDevDigital::In, 0 );

cDevControlEncoderJoystick enc( &btnLeft, &btnRight, &btnCtrl, &timerSlow, 120 );

//- Button/Switch ---------------------------------------------------
cDevDigital    switch0 ( port,10,cDevDigital::In, 0 );
cDevDigital    btnPlus ( port, 3,cDevDigital::In, 0 );
cDevDigital    btnMinus( port, 4,cDevDigital::In, 0 );

//- LED -------------------------------------------------------------
cDevDigital    led0    ( port, 8, cDevDigital::Out, 0 );


//EOF

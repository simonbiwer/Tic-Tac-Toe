//*******************************************************************
/*!
\file   USBhardware.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "USB.h"

//*******************************************************************
// 
// cHwUSB
//
//*******************************************************************
//-------------------------------------------------------------------
cHwUSB::cHwUSB( cHwUSBdesc &descIn )

:desc( descIn ),
 epCtrl( *this )

{
}

//-------------------------------------------------------------------
void cHwUSB::eventHandler( BYTE epAddr, BYTE isSetup )
{
  cHwUSBendpoint *ptr = NULL;
  
  switch( epAddr )
  {
    case 0x00: // Control EP OUT
      if( isSetup )
      {
        epCtrl.setup();
      }
      else
      {
        epCtrl.out();
      }
      break;
      
    case 0x80: // Control-EP IN 
      epCtrl.in();
      break;
    
    default:
      if( (ptr = desc.getEndpoint( epAddr )) != NULL )
      {
        if( epAddr & 0x80 ) // IN
        {
          ptr->in();
        }
        else  // OUT
        {
          ptr->out();
        }
      }
      break;
  }
}  

//EOF

//*******************************************************************
/*!
\file   Net.h
\author Thomas Breuer
\date   10.03.2014

\brief

\example .cpp
*/

//*******************************************************************
#ifndef _HW_NET_H
#define _HW_NET_H

//-------------------------------------------------------------------
#include "NetStd.h"
#include "NetApp.h"
#include "NetTransport.h"

#ifndef _MCU_TYPE_VIRTUAL

  #include "NetARP.h"
  #include "NetDHCP.h"
  #include "NetICMP.h"
  #include "NetTCP.h"
  #include "NetUDP.h"
#endif
//-------------------------------------------------------------------
#endif //_HW_NET_H

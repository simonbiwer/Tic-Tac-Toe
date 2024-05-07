//*******************************************************************
/*!
\file   Net.cpp
\author Thomas Breuer
\date   10.03.2014
*/

//-------------------------------------------------------------------
#include "NetStd.cpp"
#include "NetTransport.cpp"

#ifndef _MCU_TYPE_VIRTUAL
  #include "NetARP.cpp"
  #include "NetDHCP.cpp"
  #include "NetICMP.cpp"
  #include "NetIP.cpp"
  #include "NetTCP.cpp"
  #include "NetUDP.cpp"
#endif

// EOF

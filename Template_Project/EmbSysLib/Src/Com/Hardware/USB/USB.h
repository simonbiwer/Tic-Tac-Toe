//*******************************************************************
/*!
\file   Com/Hardware/USB.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\brief USB interface summary

Einschr�nkungen
===============
- Nur eine Configuration
- Kein alternate setting

Anwendung
=========
�berladen der Klasse cUSBinterface

GGf. setFeature/clrFeature �berladen

Host-Treiber f�r Vendor Specific Class:
libusb-win32

HINWEISE
========
cHwUSBinterfClassVSCstd NICHT verwenden, wenn Interface auf Ctrl-EP zugreift

TODO
====
- Test, ob mehr/weniger als maxPacketSize Bytes verschickt werden k�nnen
- Mindestens cUSBinterface dokumentieren
- Compliance-Test (www.usb.org)
- Aufruf setFeature fehlerhaft
- ggf. Referenz auf ein IN und ein OUT endpoint in cUSBinterf
- Zugriff auf cUSBendpoint-Objekt bzw. Endpoint-Descriptor in cUSBdesc (GenDesc)
  (Schleifen in cUSBctrl, cUSBinterf und cUSBinterfClassMSC vermeiden)
- Endpoint nicht dynamisch erzeugen ?

- GGf. template <class BUF_IN, class BUF_OUT, BYTE size> cUSBinterfGeneric : public cUSBinterf
  mit FIFO f�r BUF_OUT und SharedMem f�r BUF_IN


- AT90USB:
  + Problem mit TXINI, daher funktioniert USBinterfClassCDC::isInProgress nicht, siehe auch USBinterfClassCDC::set, USBinterfClassCDC::transmit()) .
  + Example cHwUSB_MCU.cpp noch nicht generisch


\remark
    - Einschr�nkungen
      + Nur eine Configuration
      + Kein alternate setting
    - Anwendung\n
      + �berladen der Klasse cUSBinterface
      + GGf. setFeature/clrFeature �berladen
      + Host-Treiber f�r Vendor Specific Class: libusb-win32
    - HINWEISE
      + cHwUSBinterfClassVSCstd NICHT verwenden, wenn Interface auf Ctrl-EP zugreift


\todo
    - Test, ob mehr/weniger als maxPacketSize Bytes verschickt werden k�nnen
    - Mindestens cUSBinterface dokumentieren
    - Compliance-Test (www.usb.org)
    - Aufruf setFeature fehlerhaft
    - ggf. Referenz auf ein IN und ein OUT endpoint in cUSBinterf
    - Zugriff auf cUSBendpoint-Objekt bzw. Endpoint-Descriptor in cUSBdesc (GenDesc)
      (Schleifen in cUSBctrl, cUSBinterf und cUSBinterfClassMSC vermeiden)
    - Endpoint nicht dynamisch erzeugen ?
    - GGf. template <class BUF_IN, class BUF_OUT, BYTE size> cUSBinterfGeneric : public cUSBinterf
      mit FIFO f�r BUF_OUT und SharedMem f�r BUF_IN
    - AT90USB:
      + Problem mit TXINI, daher funktioniert USBinterfClassCDC::isInProgress nicht, siehe auch USBinterfClassCDC::set, USBinterfClassCDC::transmit()) .
      + Example cHwUSB_MCU.cpp noch nicht generisch

\example cHwUSB.cpp
*/

//*******************************************************************
#ifndef _HW_USB_H
#define _HW_USB_H

//-------------------------------------------------------------------
#include "USBdesc.h"
#include "USBendpoint.h"
#include "USBctrl.h"
#include "USBinterf.h"
#include "USBhardware.h"

#endif //_HW_USB_H

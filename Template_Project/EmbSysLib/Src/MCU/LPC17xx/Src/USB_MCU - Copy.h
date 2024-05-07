//*******************************************************************
/*!
\file   USB_MCU.h
\author Thomas Breuer
\date   01.06.02012
*/

//*******************************************************************
#ifndef _HW_USB_MCU_H
#define _HW_USB_MCU_H

#include "Hardware/Common/USB.h"
//*******************************************************************
// Konfiguration

//*******************************************************************
/*! 
\class cHwUSB

\brief 


\example cHwUSB.cpp
*/
class cHwUSB_0 : public cHwUSB
{
  public:
    //---------------------------------------------------------------
    /*! 
    */
   cHwUSB_0(void);
    
  public: 
    //---------------------------------------------------------------
    // 
    virtual void start();
 
    //---------------------------------------------------------------
    // 
    virtual WORD read(BYTE EPId, BYTE *dataPtr, WORD len);

    //---------------------------------------------------------------
    // 
    virtual WORD write(BYTE EPId, BYTE *pData, WORD cnt);

 
  public:
    //-------------------------------------------------------------------
    virtual void setAddress (BYTE adr = 0);

    //---------------------------------------------------------------
    virtual void registerEP(BYTE epId, cHwUSBendpoint *epIn)
    {              
      ep[iEPAdr(epId)] = epIn;
    }


public:
    //---------------------------------------------------------------
    virtual void SetStallEP (BYTE epId);

    //---------------------------------------------------------------
    virtual void ClrStallEP (BYTE epId);

    //---------------------------------------------------------------
    virtual void EnableEP (BYTE epId);

    //---------------------------------------------------------------
    virtual void DisableEP (BYTE epId);

    //---------------------------------------------------------------
    virtual void ResetEP (BYTE epId);

    //---------------------------------------------------------------
    virtual void ClearFeatureEP(BYTE epId)
    {
			BYTE EPphy = iEPAdr(epId);
			
      if( ep[EPphy] )
      {
        ep[EPphy]->ClearFeature();
      }
    }

    //---------------------------------------------------------------
    virtual void ConfigEP (BYTE epId, 
			                     WORD epMaxPacketSize, 
		                       BYTE epType);

    //---------------------------------------------------------------
    virtual BYTE isMaskEP(BYTE epId)
    {
			BYTE EPphy = iEPAdr(epId);
      return(  (EndPointMask & (1<<EPphy))?1:0 );
    }

    //---------------------------------------------------------------
    virtual BYTE isHaltEP(BYTE epId)
    {
			BYTE EPphy = iEPAdr(epId);
      return(  (EndPointHalt & (1<<EPphy))?1:0 );
    }
		
    //---------------------------------------------------------------
    virtual void Configure (BYTE flag);

		   //---------------------------------------------------------------
    // 
    virtual void isr();

    //---------------------------------------------------------------
    // ok
    virtual void Reset (void);
		
		
		
	  private:
    BYTE  DeviceAddress;

private:
 
    //-------------------------------------------------------------------
    virtual void iWrCmd   (DWORD data);

    //---------------------------------------------------------------
    virtual void iWrCmdDat(DWORD cmd, DWORD val);

    //---------------------------------------------------------------
    virtual void iWrCmdEP (DWORD EPphy, DWORD cmd);

    //---------------------------------------------------------------
    virtual DWORD iRdCmdDat (DWORD cmd);

	
		//---------------------------------------------------------------
    virtual void iSetConfigurationEP(BYTE EPphy)
    {
      if( ep[EPphy] )
      {
        ep[EPphy]->SetConfiguration();
      }
    }


  protected:
    //---------------------------------------------------------------
    void isetMask(BYTE EPphy)
    {
      EndPointMask |= (1<<EPphy);
    }

    //---------------------------------------------------------------
    void iclrMask(BYTE EPphy)
    {
      EndPointMask &= ~(1<<EPphy);
    }

    //---------------------------------------------------------------
    void isetHalt(BYTE EPphy)
    {
      EndPointHalt |= (1<<EPphy);
    }

    //---------------------------------------------------------------
    void iclrHalt(BYTE EPphy)
    {
      EndPointHalt &= ~(1<<EPphy);
    }

    //---------------------------------------------------------------
  private:
    DWORD EndPointMask;
    DWORD EndPointHalt;

    BYTE iEPAdr (BYTE EPNum)
    {
      BYTE val;
    
      val = (EPNum & 0x0F) << 1;
      if (EPNum & 0x80) {
        val |= 0x01;
      }
      return (val);
    }

  private:
    static const WORD USB_EP_NUM  = 32;
    cHwUSBendpoint *ep[USB_EP_NUM];

  public:
     //---------------------------------------------------------------
    // ok
    static cHwUSB *usbPtr;


    
  
}; //cHwUSB

#endif

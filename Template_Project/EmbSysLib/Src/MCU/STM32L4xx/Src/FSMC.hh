//*******************************************************************
/*!
\file   .h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   

This file is released under the MIT License.
*/

// see: www.element14.com/community, STM: Software examples for STM32F4xx, STM32F4xx_LCD_Example.zip

//*******************************************************************
#ifndef _HW_FSMC_MCU_H
#define _HW_FSMC_MCU_H

//*******************************************************************

//*******************************************************************
/*! 
\class 

\brief Implementation of 

\example .cpp
*/
class cHwFSMC //: public cHwADC
{
  public:
    //---------------------------------------------------------------
    /*! Initialize the FSCM hardware
        \param xxx  xxx
    */
    cHwFSMC( BYTE type, BYTE id )
    { 
      WORD mode =  cHwPinConfig::FAST_SPEED
                 | cHwPinConfig::PUSH_PULL
                 | cHwPinConfig::NO_PUPD;
          
      cHwPinConfig::set(cHwPinConfig::FSMC_D0,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D1,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D2,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D3,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D4,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D5,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D6,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D7,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D8,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D9,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D10,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D11,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D12,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D13,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D14,mode);  
      cHwPinConfig::set(cHwPinConfig::FSMC_D15,mode);  

      cHwPinConfig::set(cHwPinConfig::FSMC_NOE,mode); 
      cHwPinConfig::set(cHwPinConfig::FSMC_NWE,mode); 
      cHwPinConfig::set(cHwPinConfig::FSMC_A19,mode); 
      cHwPinConfig::set(cHwPinConfig::FSMC_NCE2,mode); 
      
      id = id << 1;
      
      RCC->AHB3ENR |= RCC_AHB3ENR_FSMCEN; // Enable FSMC clock
      
      // Bank1 NOR/SRAM control register configuration
      FSMC_Bank1->BTCR[id] 
        = (uint32_t) ( 0 <<  1 ) // data adress multiplex: disable
                    |( 0 <<  2 ) // memory type: SRAM
                    |( 1 <<  4 ) // data width: 16 bit
                    |( 0 <<  8 ) // burst access mode: disable
                    |( 0 <<  9 ) // wait signal priority: low
                    |( 0 << 10 ) // wrap mode: disable
                    |( 0 << 11 ) // wait signal active: before wait state
                    |( 1 << 12 ) // write operation: 
                    |( 0 << 13 ) // wait signal: disable
                    |( 0 << 14 ) // extended mode: disable
                    |( 0 << 15 ) // asynchronous wait: disable
                    |( 0 << 19 );// write burst: disable
      
      // Bank1 NOR/SRAM timing register configuration
      FSMC_Bank1->BTCR[id+1] 
        = (uint32_t) ( 1 <<  0 ) // AddressSetupTime 
                    |( 0 <<  4 ) // AddressHoldTime
                    |( 9 <<  8 ) // DataSetupTime 
                    |( 0 << 16 ) // BusTurnAroundDuration
                    |( 0 << 20 ) // CLKDivision
                    |( 0 << 24 ) // DataLatency
                    |( 0 << 28 );// AccessMode: A
                
      FSMC_Bank1E->BWTR[id] = 0x0FFFFFFF; // no extended mode
      
      FSMC_Bank1->BTCR[id] |= ( 1 << 0 ); // memory bank enable: on
    }

}; //

#endif

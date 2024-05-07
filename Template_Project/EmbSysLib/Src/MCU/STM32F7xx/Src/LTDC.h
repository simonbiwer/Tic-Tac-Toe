//*******************************************************************
/*!
\file   LTDC.h
\author Thomas Breuer
\date   27.11.2018
*/

//*******************************************************************
#ifndef _LTDC_H
#define _LTDC_H

//*******************************************************************
/*! 
\class cHwLTDC

\brief ...

Datasheet: ...

\example  ...
*/
class cHwLTDC
{
  public:
		//---------------------------------------------------------------
		cHwLTDC( uint32_t startAddrIn )   
		{
      startAddr = startAddrIn;
      
			RCC->APB2ENR  |=  RCC_APB2ENR_LTDCEN;   // clock enable		 
			RCC->APB2RSTR |=  RCC_APB2RSTR_LTDCRST; // reset cycle
			RCC->APB2RSTR &= ~RCC_APB2RSTR_LTDCRST;
		}
  
		//---------------------------------------------------------------
		void Init( WORD Hsize, WORD Vsize )
		{
      DWORD h = 0;
      DWORD v = 0;
      
			// Global control register 
			LTDC->GCR = (!LTDC_GCR_HSPOL   // Horizontal Synchronization Polarity: activ low
									|!LTDC_GCR_VSPOL   // Vertical Synchronization Polarity: activ low
									|!LTDC_GCR_DEPOL   // Not Data Enable Polarity: activ low
                  |!LTDC_GCR_PCPOL );// Pixel Clock Polarity: activ low

			// Synchronization size configuration register 
      h += 1; // add H-Sync
      v += 1; // add V-Sync
			LTDC->SSCR = ((h << 16)  // Horizontal Synchronization Width: 1
                   |(v <<  0));// Vertical Synchronization Height: 1

			// Back porch configuration register 
      h += 1; // add H-Back porch
      v += 1; // add V-Back porch
			LTDC->BPCR = ((h << 16)  // Accumulated Horizontal back porch
                   |(v <<  0));// Accumulated Vertical back porch

			// Active width configuration register
      h += Hsize;
      v += Vsize;      
			LTDC->AWCR = ((h << 16)  // Accumulated Active Width
                   |(v <<  0));// Accumulated Active Height 

			// Total width configuration register
      h += 1; // add H-Front porch
      v += 1; // add V-Front porch      
			LTDC->TWCR = ((h << 16)  // Total Width 
                   |(v <<  0));// Total Height

			// Background color configuration register 
			LTDC->BCCR = ( (0x00 << 16)    // Red value
                   | (0x00 <<  8)    // Green value
                   | (0x00 <<  0) ); // Blue value

      // Interrupt enable register
      LTDC->IER = 0; // no interrupts

			// Global control register 
			LTDC->GCR |= LTDC_GCR_LTDCEN; // LTDC enable
		}
  
    //---------------------------------------------------------------
    uint32_t LayerConfig( uint32_t width, uint32_t height, uint8_t layerID = 0 )
		{
      LTDC_Layer_TypeDef *layer = (layerID) ? LTDC_Layer2 : LTDC_Layer1; 
     
      uint32_t hbp  = (LTDC->BPCR & LTDC_BPCR_AHBP) >> 16; // H-Back porch
      uint32_t vbp  = (LTDC->BPCR & LTDC_BPCR_AVBP) >> 0;  // V-Back porch
      uint32_t bpp  = 2; // RGB565: 16-Bit pixel format = 2 bytes per pixel
            
      // Layerx window horizontal position configuration register
      layer->WHPCR = ( ((width       + hbp) << 16)    // Window Horizontal Stop Position
                     | ((0/*X0*/ + 1 + hbp) <<  0) ); // Window Horizontal Start Position

      // Layerx window vertical position configuration register
      layer->WVPCR = ( ((height      + vbp) << 16)    // Window Vertical Stop Position
                     | ((0/*Y0*/ + 1 + vbp) <<  0) ); // Window Vertical Start Position

      // Layerx pixel format configuration register
      layer->PFCR = 0x02; // PixelFormat: RGB565

      // Layerx default color configuration register
      layer->DCCR = ( (0x00 << 24)    // Alpha
                    | (0x00 << 16)    // Red
                    | (0x00 <<  8)    // Green
                    | (0x00 <<  0) ); // Blue

      // Layerx constant alpha configuration register
      layer->CACR = (0xFF); // Alpha

      // Layerx blending factors configuration register
      layer->BFCR = ( (0x06 << 8)   // Blending Factor 1:Pixel Alpha x Constant Alpha
                    | (0x07 << 0) );// Blending Factor 2:1-(Pixel Alpha x Constant Alpha)

      // Layerx color frame buffer address register
      layer->CFBAR = startAddr;

      
      // Layerx color frame buffer length register
      layer->CFBLR  = ( ((((width          )*bpp)  ) << 16)   // Color Frame Buffer Pitch in bytes
                      | ((((width - 0/*X0*/)*bpp)+3) <<  0) );// Color Frame Buffer Line Length

      // Layerx color frame buffer line number register
      layer->CFBLNR = height; // Frame Buffer Number of Lines 

      // Layerx control register 
      layer->CR |= LTDC_LxCR_LEN; // Layer Enable

      // Shadow reload configuration register 
			LTDC->SRCR = LTDC_SRCR_IMR; // Immediate Reload: enable

      return( startAddr );
		}
    
  private:
    //---------------------------------------------------------------
    uint32_t startAddr;

};

#endif

//*******************************************************************
/*!
\file   CRC.h
\author Thomas Breuer
\date   18.10.2012
*/

//*******************************************************************
#ifndef _STD_CRC_H
#define _STD_CRC_H

//*******************************************************************
/*!
\class cCRC

\brief 16 bit cyclic redundancy check (CRC) calculation.

  Calculates CRC16 with defaults
    GP    = 0xA001
    Start = 0xFFFF

  Test condition:
    Data  = 0x01,0x23,0x45,0x67,0x89,0xAB
    CRC   = 0xF146

\example cCRC.cpp

\see http://www.lammertbies.nl/comm/info/crc-calculation.html
*/
class cCRC
{
  public:
    //---------------------------------------------------------------
    /*! Calculation mode
    */
    typedef enum
    {
      SMALL = 0, //!< Bit-oriented algorithm, no need of extra memory
      FAST       //!< Optimized byte oriented algorithm, needs 512 byte RAM
    } MODE;

    //---------------------------------------------------------------
    /*! Instantiate a object with capabilities to calculate CRC with
        denoted algorithm
        \param mode SMALL (no RAM, but slow)
                    or FAST (fast, but 512 byte RAM) (see \a MODE)
        \param startCRC         Initial CRC value
        \param generatorPolynom 16-bit generator polynom
    */
    cCRC( MODE mode,
          WORD startCRC         = 0xFFFF,
          WORD generatorPolynom = 0xA001 );

    //---------------------------------------------------------------
    /*! Destructor
    */
    ~cCRC( void );

    //---------------------------------------------------------------
    /*! Calculates CRC of BYTE array \a ptr with \a size number of
        bytes
        \param  ptr Pointer to byte-array
        \param  size Number of bytes
        \return CRC
    */
    WORD operator()( const BYTE *ptr,
                     DWORD        size );

    void operator()( const BYTE data );

    WORD get( void )
    {
      return( crc );
    }

    void reset( void )
    {
      crc = startCRC;
    }

  private:
    //---------------------------------------------------------------
    //
    //
    WORD tabMethod( BYTE idx );

  private:
    //---------------------------------------------------------------
    WORD *tabArray;
    WORD  crc;
    WORD  startCRC;
    WORD  generatorPolynom;

}; //cCRC

#endif

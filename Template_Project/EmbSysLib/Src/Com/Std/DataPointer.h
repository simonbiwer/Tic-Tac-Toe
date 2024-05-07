//*******************************************************************
/*!
\file   dataPointer.h
\author Thomas Breuer
\date   21.11.2015 
*/

//*******************************************************************
#ifndef _DATA_POINTER_H
#define _DATA_POINTER_H

//*******************************************************************
/*! 
\class cDataPointer

\brief Combine pointer and size

This class combines a pointer and a size. 
No memory allocation!
*/
class cDataPointer
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate a NULL pointer
    */
    cDataPointer( void )
    {
      ptr  = NULL;
      size = 0;
    }
  
    //---------------------------------------------------------------
    /*! Instantiate a pointer
        \param ptrIn Initial pointer
        \param sizeIn Initial size        
    */
    cDataPointer( BYTE *ptrIn, 
                  WORD  sizeIn )
    {
      ptr  = ptrIn;
      size = sizeIn;
    }

    //---------------------------------------------------------------
    /*! Instantiate a pointer by an object
        \param object Reference to an object
    */
    template <class T> 
    cDataPointer( const T &object )
    {
      ptr  = (BYTE*)( &object );
      size = sizeof( T );
    }

    //---------------------------------------------------------------
    /*! Copy constructor
    */
    void operator=( const cDataPointer &dataIn )
    {
      if( dataIn.ptr && dataIn.size )
      {
        ptr  = dataIn.ptr;
        size = dataIn.size;        
      }
      else
      {
        ptr  = NULL;
        size = 0;
      }
    }

    //---------------------------------------------------------------
    /*! Set pointer
        \param ptrIn Initial pointer
        \param sizeIn Initial size        
    */
    BYTE set( const BYTE *ptrIn, WORD sizeIn )
    {
      if( ptrIn && sizeIn )
      {
        ptr = (BYTE*)ptrIn;
        size = sizeIn;
        return(true);
      }
      return(false);
    }

    //---------------------------------------------------------------
    /*! Set pointer
        \param object Reference to an object
    */
    template <class T> void set( const T &dataIn )
    {
      ptr = (BYTE*)(&dataIn);
      size = sizeof( T );
    }
    
    //---------------------------------------------------------------
    /*! Determine current pointer
        \return Current pointer
    */
    BYTE *getPtr( void ) const
    {
      return( ptr );
    }
    
    //---------------------------------------------------------------
    /*! Determine current pointer and cast
        \return Current pointer
    */
    template <class T> operator T *()
    {
      return( (T *)getPtr() );
    }
    
    //---------------------------------------------------------------
    /*! Check, if size equals to zero
        \return 
                - true, if size = 0
                - false, if size > 0
    */
    BYTE isEmpty( void )
    {
     return( size?false:true );
    }

    //---------------------------------------------------------------
    /*! Determine size
        \return Current size
    */
    WORD getSize( void )
    {
      return( size );
    }
    
    //---------------------------------------------------------------
    /*! Shift pointer and decrement size by \b cnt
        \param shift Number of bytes to shift
    */
    void shift( WORD shift )
    {
      if( shift <= size )
      {
        ptr  += shift;
        size -= shift;
      }
      else
      {
        ptr = NULL;
        size = 0;
      }
    }

  private:
    //---------------------------------------------------------------
    BYTE  *ptr;
    WORD   size;

};

#endif

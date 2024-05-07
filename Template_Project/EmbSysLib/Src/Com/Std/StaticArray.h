//*******************************************************************
/*!
\file   StaticArray.h
\author Thomas Breuer
\date   03.01.2018
*/

//*******************************************************************
#ifndef _STATIC_ARRAY_H
#define _STATIC_ARRAY_H

#pragma pack(1)

//*******************************************************************
template <class T, WORD size> class cStaticArray
{
  public:
    cStaticArray()
    {
      len = 0;
    }

    //-----------------------------------------------------------
    /*BYTE operator==(const cStaticArray &x) const
    {
      return( memcmp(element, x.element, size) == 0 );
    }
    */
    //-----------------------------------------------------------
    void operator=( cStaticArray<T,size> &in)
    {
      len = in.len;
      memcpy( element, in.element, size );
    }

    //-----------------------------------------------------------
    T &operator[](WORD idx)
    {
      T &r = element[idx];
      return( r );
    }

    //-----------------------------------------------------------
    BYTE operator<<(T x)
    {
      if( len < size )
      {
        element[len++] = x;
        return( true );
      }
      return( false );
    }

    //-----------------------------------------------------------
    void clear( void )
    {
      len = 0;
      memset( element,0, size );
    }

		WORD length()
		{
			return( len );
		}

		BYTE isFull()
		{
			return( len >= size );
		}
    
    BYTE isEmpty()
		{
			return( len == 0 );
		}

    //-----------------------------------------------------------
  /*  void operator=(T elementIn)
    {
      WORD i=0;
      while(i < size)
      {
        element[i] = (elementIn>>(8*i))&0xFF;
        i++;
       }
    }
*/
    //-----------------------------------------------------------
   // operator DWORD()
   // {
   //   return( (DWORD)(*((DWORD*)element)) );
   // }

  private:
    //-----------------------------------------------------------
    WORD  len;
    T element[size];

};



#pragma pack()



#endif

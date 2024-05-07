//*******************************************************************
/*!
\file   List.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "List.h"

//*******************************************************************
//
// cList::Item
//
//*******************************************************************
//-------------------------------------------------------------------
cList::Item::Item( cList *list )
{
  PtrNext = 0;
  if( list )
  {
    list->add( this );
  }
}

//-------------------------------------------------------------------
cList::Item *cList::Item::getNext( void )
{
  return( PtrNext );
}

//-------------------------------------------------------------------
cList::Item *cList::Item::getPrev( cList &list )
{
  Item *tmp = list.getFirst();
  while( tmp && tmp->getNext() != this )
  {
    tmp = tmp->getNext();
  }
  return( (tmp==this)?NULL:tmp );
}

//*******************************************************************
//
// cList
//
//*******************************************************************
//-------------------------------------------------------------------
cList::cList( void )
{
  PtrFirst = 0;
}

//-------------------------------------------------------------------
BYTE cList::add(Item *itemPtr)
{
  Item *ptr;

  // Is itemPtr still in list?
  ptr = PtrFirst;

  while( ptr )
  {
    if( ptr == itemPtr )
    {
      return( false );
    }
    if(ptr->PtrNext) // Does curent object have a next object?
    {
      ptr = ptr->PtrNext;
    }
    else
    {
      break;
    }
  }

  // Add a new object,
  // ptr may referes to last object in the list
  if( ptr ) // append new object to last object in list
  {
    ptr->PtrNext = itemPtr;
  }
  else // insert first object into list
  {
    PtrFirst = itemPtr;
  }
  return( true );
}

//-------------------------------------------------------------------
cList::Item* cList::getFirst( void )
{
  return( PtrFirst );
}

//-------------------------------------------------------------------
cList::Item* cList::operator[](WORD index)
{
  Item* ptr = PtrFirst;
  while( ptr && index-- )
  {
    ptr = ptr->PtrNext;
  }
  return( ptr );
}

//-------------------------------------------------------------------
void cList::updateAll( void )
{
  Item* ptr = PtrFirst;

  while( ptr )
  {
    ptr->update();
    ptr = ptr->PtrNext;
  }
}

// EOF

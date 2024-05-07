//*******************************************************************
/*!
\file   List.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _LIST_H
#define _LIST_H

//*******************************************************************
/*!
\class cList

\brief Base class for single linked lists

\example cList.cpp
*/
class cList
{
  public:
    //***************************************************************
    /*!
    \class cList::Item

    \brief Base class for list items

    Drived classes should at least implement the \a update() method.
    The update() method is called by cList::updateAll()

    \example cList.cpp
    */
    class Item
    {
      public:
          //---------------------------------------------------------
          /*! Instatiate a list item
              \param list If not zero, the item is added to \a list
          */
          Item( cList *list = 0 );

          //---------------------------------------------------------
          /*! Get the next item of linked list
              \return Pointer to next item or zero
          */
          Item *getNext( void );

          //---------------------------------------------------------
          /*! Get the prev item of linked list
              \param  list Reference to a list
              \return Pointer to prev item or zero
          */
          Item *getPrev( cList &list );

        private:
          //---------------------------------------------------------
          /*! Update the item
          */
          virtual void update( void ) {};

        private:
          //---------------------------------------------------------
          Item *PtrNext; // Pointer to next entry

        friend class cList;
      }; //cList::Item
      //-------------------------------------------------------------

  public:
    //---------------------------------------------------------------
    /*! Instantiate an empty list
    */
    cList( void );

    //---------------------------------------------------------------
    /*! Add an item to the list
        \param itemPtr Pointer to the item
        \return
                - true: Item added
                - false: Item not added, because it was already in list
    */
    BYTE add( Item *itemPtr );

    //---------------------------------------------------------------
    /*! Run \a update() method of all items in the list
    */
    void updateAll( void );

    //---------------------------------------------------------------
    /*! Get the pointer to the first item in the list
        \return Pointer to the first item\n
                Zero, if list is empty
    */
    Item* getFirst( void );

    //---------------------------------------------------------------
    /*! Get the pointer to an indexed item in the list
        \return Pointer to the item\n
                Zero, if list is empty or index exeeds size of list
    */
    Item* operator[](WORD index);

  private:
    //---------------------------------------------------------------
    Item *PtrFirst; // Pointer to first entry

}; //cList

#endif

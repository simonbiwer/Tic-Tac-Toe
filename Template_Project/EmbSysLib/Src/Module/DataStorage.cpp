#include "lib.h"
#include "Module/DataStorage.h"


cDataStorage::Record::Record(cDataStorage &ds,cDataStorage::Record &p, DWORD keyIN, DWORD sizeIN)
      :rh(ds,p)
      {
        h.length = sizeIN;
        h.key    = keyIN;
        rh.open(h);

      }

      void cDataStorage::Record::storeRecord()
      {
        rh.create( h );
        store();
      }

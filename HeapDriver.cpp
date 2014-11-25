#include "HeapSkew.h"
//#include "PQHeap.h"
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;
using CSC2110::String;
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << num_items << endl;
cout<<"a";
while(true)
{
   HeapSkew<CD>* sh = new HeapSkew<CD>(&CD::compare_items);

cout<<"c";
   ListArrayIterator<CD>* iter = cds->iterator();
   while(iter->hasNext())
   {
      CD* cd = iter->next();
      sh->heapInsert(cd);
   }
cout<<"d";
   delete iter;
cout<<"b";

   while(!(sh->heapIsEmpty()))
   {
cout<<"e";
      CD* cd = sh->heapRemove();
cout<<"f";
	if (cd==NULL)
		cout<<"cd is null";
      //cd->displayCD();
   }

   delete sh;
}
   deleteCDs(cds);
   delete cds;

   return 0;
}

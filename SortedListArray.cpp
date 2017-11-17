//Victor Li
//Data Structures with Doctor Li Yanjun
//October 5th
//source code fo the methods listed in sortedlistbyarray header file

#include "SortedListArray.h"

SortedListByArray::SortedListByArray()
{
  length = 0;
}

bool SortedListByArray::IsFull() const
{
  return (length == MAX_ITEM);
}

int SortedListByArray::GetLength( ) const
{
  return length;
}

bool SortedListByArray::IsEmpty() const
{
  return (length == 0);
}

void SortedListByArray::InsertItem(ItemType item) 
{
   bool moreToSearch; 
   int location = 0;
   moreToSearch = (location < length);
   while (moreToSearch)
   {
      switch(item.ComparedTo(info[location]))
      {
         case LESS : moreToSearch = false; break;
         case GREATER : location++;
                        moreToSearch = (location < length);
                        break;
      }
   }

   for ( int index = length; index > location; index--)
        info[index] = info[index-1];

   info[location] = item;
   length++;
}

void SortedListByArray::RetrieveItem(ItemType& item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged. 
{
  int midPoint;
  int first =0;
  int last = length -1;
  
  bool moreToSearch = (first <= last);
  found = false;
  while (moreToSearch && !found) 
  {
    midPoint = (first+last)/2;
    switch (item.ComparedTo(info[midPoint]))
    { 
      case LESS    : last = midPoint -1;
                     moreToSearch = (first <= last);
                     break;
      case GREATER : first = midPoint +1;
                     moreToSearch = (first <= last);
                     break;
      case EQUAL   : found = true;
                     item = info[midPoint];
                     break;
    }
  }
}


void SortedListByArray::DeleteItem(ItemType item) 
// Pre: item�s key has been inititalized.
//	One and only one element in the list has a key that matches item�s.
// Post: No element in the list has a key that matches item�s.
{
   int location = 0;
   while(item.ComparedTo(info[location])!= EQUAL)
       location++;

   for ( int index = location +1; index < length; index++)
        info[index-1] = info[index];
   info[location] = item;
   length--;
}

void SortedListByArray::MakeEmpty()
// Pre:  N/A   
// Post: the list is empty
{
   length = 0;
}


void SortedListByArray::ResetList ( )  
// Pre:  List has been inititalized.
// Post: Current position is prior to first element.
{    
  currentPos  =  -1 ;
}

void SortedListByArray::GetNextItem ( ItemType&  item )  
// Pre:  List has been initialized. Current position is 
//       defined. 
//       Element at current position is not last in list.
// Post: Current position is updated to next position.
// 	  item is a copy of element at current position.
{
  currentPos++  ;
  item = info [currentPos] ;
}

void SortedListByArray::SplitList(ItemType item, SortedListByArray& listOne, SortedListByArray& listTwo){
	currentPos = -1;//Resetting the list to initial value
	ItemType thisOne;
	 for (int i=0; i<GetLength(); i++)
        {
		
		GetNextItem(thisOne);
		//Using the comparedTo function to sort values into listOne or listTwo.
                if (thisOne.ComparedTo(item)== LESS || thisOne.ComparedTo(item)== EQUAL)
                        listOne.InsertItem(thisOne);

                else if (thisOne.ComparedTo(item)== GREATER)
                        listTwo.InsertItem(thisOne);
        }
}

void SortedListByArray::MergeList(SortedListByArray& listOne, SortedListByArray& listTwo){
	currentPos = -1;

	listOne.ResetList();
	listTwo.ResetList();

	ItemType thisOne,thisTwo;



	//Iterating through listOne
	for (int i = 0; i<listOne.GetLength(); i++){
		listOne.GetNextItem(thisOne);
		//Insert object in now

	   bool moreToSearch;
  	   int location = 0;
   		moreToSearch = (location < length);
   		while (moreToSearch)
   		{
      			switch(thisOne.ComparedTo(info[location]))
      			{
         			case LESS : moreToSearch = false; break;
         			case GREATER : location++;
                        	moreToSearch = (location < length);
                        	break;
      			}
   		}		

   		for ( int index = length; index > location; index--)
        		info[index] = info[index-1];

   		info[location] = thisOne;
   		length++;
	}




	//Repeating the same process in order to get the info from listTwo.
	for(int j = 0; j < listTwo.GetLength();j++){
		listTwo.GetNextItem(thisTwo);
		//Insert object now

	   bool moreToSearch;
	   int location = 0;
	   moreToSearch = (location < length);
	   while (moreToSearch)
	   {
	      switch(thisTwo.ComparedTo(info[location]))
	      {
	         case LESS : moreToSearch = false; break;
        	 case GREATER : location++;
                 moreToSearch = (location < length);
                       break;
      	      }
   	   }

   	for ( int index = length; index > location; index--)
       		 info[index] = info[index-1];

   	info[location] = thisTwo;
   	length++;
	}
}


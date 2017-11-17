//Victor Li
//Data Structures with Dr. Yanjun Li
//October 5th
//Driver file in which we test the functions for sorted list
#include "itemType.h"
#include "SortedListArray.h"

void PrintList( SortedListByArray& list)
// Pre:  list has been initialized.         
// Post: Each component in list has been written. 
// 
{
  int length;
  ItemType item;

  list.ResetList( );
  length = list.GetLength( );
  for (int counter = 1; counter <= length; counter++)
  {
    list.GetNextItem(item);
    item.Print( );
  }
}

int main(){

    SortedListByArray listOne, listTwo, listThree;

    ItemType x;
    x.Initialize(8);
    listOne.InsertItem(x);

    ItemType y;
    y.Initialize(6);
    listOne.InsertItem(y);

    ItemType z;
    z.Initialize(9);
    listOne.InsertItem(z);

    ItemType a;
    x.Initialize(1); 
    listOne.InsertItem(x);
         
    ItemType b;
    y.Initialize(7);
    listOne.InsertItem(y);

    ItemType c;
    z.Initialize(3);
    listOne.InsertItem(z);

    cout << "Orignal list is: " << endl;
    PrintList(listOne);
    cout << endl;

    
    listOne.SplitList(z, listTwo, listThree);
    cout << "After split, list1 is split on value 5: " << endl;
    PrintList(listTwo);
    cout << endl;
    cout << "After split, list2 is split on value 5: " << endl;
    PrintList(listThree);
    cout << endl;



    listOne.MakeEmpty();

    listOne.MergeList(listTwo, listThree);
    cout << "Merge List is: " << endl;
    PrintList(listOne);
    cout<<"Emptying the list now: " << listOne.IsEmpty()<<endl;

    return 0;
}

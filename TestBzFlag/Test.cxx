#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList* list = new LinkedList();
    /* Start with the empty list */
    list->printList();
    cout << endl << list->isEmpty() << endl;

    // Insert 0,0,0,3. So linked list becomes 6->NULL  
    list->insertInOrder(0,0,0,30);

    // Insert 0,1,1,2 at the beginning.  
    list->insertInOrder(0,1,1,15);

    // Insert  at the beginning.  
    list->insertInOrder(0,2,2,23);

    // Insert 0,3,3,0 at the end.  
    list->insertInOrder(0,3,3,7);

    cout << "Created Linked list is: ";
    list->printList();
    cout << endl << "Head: ";
    list->printHead();
    cout <<endl << "Tail: ";
    list->printTail();
    cout << endl << "Pop: ";
    list->print(list->pop());

    return 0;
}
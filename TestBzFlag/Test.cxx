#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

void printList(LinkedList* list)
{
    Node* node;
    list->getHead(&node);
    while (node != NULL)
    {
        cout << endl;
        cout << "X: " << node->x << endl;
        cout << "Y: " << node->y << endl;
        cout << "DistTraveled: " << node->distanceTraveled << endl;
        cout << "DistGoal: " << node->distanceToGoal << endl;
        cout << "Weigth: " << node->weight << endl;
        node = node->child;
    }
}

int main()
{
    LinkedList* list = new LinkedList();
        /* Start with the empty list */
        Node* head = NULL;

        // Insert 0,0,0,3. So linked list becomes 6->NULL  
        list->append(0,0,0,3);

        // Insert 0,1,1,2 at the beginning.  
        // So linked list becomes 7->6->NULL  
        list->push(0,1,1,2);

        // Insert  at the beginning.  
        // So linked list becomes 1->7->6->NULL  
        //list->push(0,2,2,1);

        // Insert 0,3,3,0 at the end. So  
        // linked list becomes 1->7->6->4->NULL  
        list->append(0,3,3,0);

        cout << "Created Linked list is: ";
        printList(list);

        return 0;
    }
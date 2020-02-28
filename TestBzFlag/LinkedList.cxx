/************************************************
*Node functions from Node.h
* includes constructors, getter/setters, and hasChild
*
*************************************************/


#include "Node.h"
#include "LinkedList.h"
LinkedList::LinkedList()
{
    this->Head = nullptr;
    this->Tail = nullptr;
    this->length = 0;
}
void LinkedList::push(int x, int y, int distanceTraveled, int distanceToGoal)
{
    //declare head ref
    Node** head_ref = &Head;
    /* 1. allocate node */
    Node* new_node = new Node();

    /* 2. put in the data */
    new_node->x = x;
    new_node->y = y;
    new_node->distanceTraveled = distanceTraveled;
    new_node->distanceToGoal = distanceToGoal;
    new_node->weight = distanceToGoal + distanceTraveled;


    /* 3. Make next of new node as head */
    new_node->child = (*head_ref);
    new_node->childExists = true;

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Given a node prev_node, insert a new node after the given
   prev_node */
void LinkedList::insertAfter(Node* prev_node, int x, int y, int distanceTraveled, int distanceToGoal)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == nullptr)
    {
        return;
    }

    /* 2. allocate new node */
    Node* new_node = new Node();

    /* 3. put in the data  */
    new_node->x = x;
    new_node->y = y;
    new_node->distanceTraveled = distanceTraveled;
    new_node->distanceToGoal = distanceToGoal;
    new_node->weight = distanceToGoal + distanceTraveled;
    /* 4. Make next of new node as next of prev_node */
    new_node->child = prev_node->child;

    /* 5. move the next of prev_node as new_node */
    prev_node->child = new_node;
}

/* Given a reference (pointer to pointer) to the tail
   of a list and an int, appends a new node at the end  */
void LinkedList::append(int x, int y, int distanceTraveled, int distanceToGoal)
{   
    //Declare tail_ref
    Node** tail_ref = &Tail;
    /* 1. allocate node */
    Node* new_node = new Node();

    Node* last = *tail_ref;  /* used in step 5*/

    /* 2. put in the data  */
    new_node->x = x;
    new_node->y = y;
    new_node->distanceTraveled = distanceTraveled;
    new_node->distanceToGoal = distanceToGoal;
    new_node->weight = distanceToGoal + distanceTraveled;

    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->child = nullptr;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*tail_ref == nullptr)
    {
        *tail_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->child != nullptr)
        last = last->child;

    /* 6. Change the next of last node */
    last->child = new_node;
    return;
}
void LinkedList::getHead(Node** point) {
    *point = Head;
}
;

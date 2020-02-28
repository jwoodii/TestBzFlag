#pragma once
#include "Node.h"
class LinkedList {
public:
    LinkedList();
    void push(int x, int y, int distanceTraveled, int distanceToGoal);
    void insertAfter(Node* prev_node, int x, int y, int distanceTraveled, int distanceToGoal);
    void append(int x, int y, int distanceTraveled, int distanceToGoal);
    void getHead(Node** point);
    
private:
    Node* Head;
    Node* Tail;
    int length;

};



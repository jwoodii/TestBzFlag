#pragma once
#include "Node.h"
#include "LinkedList.h"
LinkedList::LinkedList(Node start) {
    this->Head = &start;
    this->Tail = &start;
    this->length = 1;
}
LinkedList::LinkedList() {
    this->Head = nullptr;
    this->Tail = nullptr;
    this->length = 0;
}

void LinkedList::lowestSearch(Node low) {
    Node current = *Head;
    Node lowest = *Head;
    while (current.hasChild()) {
        if (lowest.getWeight() > current.getWeight()) {
            lowest = current;
        }
        current = *current.getChild();
    }
    low = lowest;
}

void LinkedList::addNode(Node add) {
    if (Head == nullptr && Tail == nullptr) {
        Head = &add;
        Tail = &add;
    }
    else {
        Tail->setChild(add);
        Tail = &add;
    }
    length++;
}

void LinkedList::addAtHead(Node add)
{
    if (Head == nullptr && Tail == nullptr)
    {
        Head = &add;
        Tail = &add;
    }
    else {
        Node temp = *Head;
        Head = &add;
        Head->setChild(temp);
    }
}

void LinkedList::remNode(Node rem) {
    Node current = *Head;
    Node prev;
    while (current != rem) {
        prev = current;
        current = *current.getChild();
    }
    prev.setChild(*current.getChild());
    length--;
    rem = current;
}
Node LinkedList::popHead() {
    Node ret = *Head;
    Head = Head->getChild();
    return ret;
}

bool LinkedList::contains(Node check)
{
    Node* current = this->Head;
    while (current != nullptr) {
        if (check.getX() == current->getX() && check.getY() == current->getY()) {
            return true;
        }
        else {
            current = current->getChild();
        }
    }
    return false;
}

int LinkedList::getLength()
{
    return length;
}

bool LinkedList::isEmpty() {
    if (Head != nullptr) {
        return false;
    }
    return true;
}
;

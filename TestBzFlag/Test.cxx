#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

int main()
{
    Node second = Node(2, 5, 1, 9);
    Node first = Node(1, 5, 0, 10,second);
    Node third = Node(3, 5, 2, 8);
    second.setChild(third);
    cout << "This is Second" << endl;
    cout << "X: " << second.getX() << endl;
    cout << "Y: " << second.getY() << endl;
    cout << "Dist Traveled: " << second.getDistanceTraveled() << endl;
    cout << "Dist Goal: " << second.getDistanceToGoal() << endl;
    cout << "Weight: " << second.getWeight() << endl;
    cout << "This is Second's Child" << endl;
    cout << "X: " << second.getChild()->getX() << endl;
    cout << "Y: " << second.getChild()->getY() << endl;
    cout << "Dist Traveled: " << second.getChild()->getDistanceTraveled() << endl;
    cout << "Dist Goal: " << second.getChild()->getDistanceToGoal() << endl;
    cout << "Weight: " << second.getChild()->getWeight() << endl;

    return 0;
}

#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedList.h"
#include <queue>
#include <vector>
using namespace std;

struct compare
{
    bool operator()(const Node& a, const Node& b)
    {
        return a.weight < b.weight;
    }
};

Node GenerateNode(int x, int y, int distanceTrav, int distanceGoal) {
    Node temp = new Node();
    temp.x = x;
    temp.y = y;
    temp.distanceToGoal = distanceGoal;
    temp.distanceTraveled = distanceTrav;
    temp.weight = temp.distanceToGoal + temp.distanceTraveled;
    return temp;
}



void aStar(int start[2], int goal[2], std::vector<Node> path) {
    bool foundGoal = false;
    Node* current = nullptr;
    Node temp;
    int x = 1;
    std::priority_queue <Node, std::vector<Node>, compare> open;
    std::priority_queue <Node, std::vector<Node>, compare> closed;
    open.push(GenerateNode(1, 1, 0, 6));
    open.push(GenerateNode(1, 1, 0, 1));
    open.push(GenerateNode(1, 1, 0, 5));
    open.push(GenerateNode(1, 1, 0, 2));
    open.push(GenerateNode(1, 1, 0, 4));
    open.push(GenerateNode(1, 1, 0, 3));
    while (!open.empty()) {
        temp = open.top();
        cout << "Node " << x << ": " << endl;
        cout << temp.x <<endl;
        cout << temp.y << endl;
        cout << temp.distanceToGoal << endl;
        cout << temp.distanceTraveled << endl;
        cout << temp.weight << endl;
        x++;
        open.pop();
    }
    //Begin Astar conversion

}
int main()
{
    int start[2];
    start[0] = 0;
    start[1] = 0;
    int goal[2] = { 5,5 };
    std::vector<Node> path;
    aStar(start,goal,path);

    return 0;
}
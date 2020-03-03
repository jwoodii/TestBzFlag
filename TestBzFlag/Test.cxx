#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "Node.h"
#include "LinkedList.h"
#include <queue>
#include <vector>
using namespace std;

bool IsInQueue(Node* node, std::priority_queue <Node*> open) {
    std::priority_queue <Node*> temp;
    temp = open;
    while (!temp.empty()) {
        if (node == temp.top()) {
            return true;
        }
        temp.pop();
    }
    return false;
}
void PopACertainNode(Node* node, std::priority_queue <Node*> open) {
    std::priority_queue <Node*> temp;
    temp = open;
    while (!temp.empty()) {
        if (temp.top() == node) {
            open.pop();
        }
        temp.push(open.top());
        open.pop();
    }
    open = temp;
}
Node* GenerateNode(Node* parent, int x, int y, int distanceTrav, int distanceGoal) {
    Node* temp = new Node;
    temp->x = x;
    temp->y = y;
    temp->distanceToGoal = distanceGoal;
    temp->distanceTraveled = distanceTrav;
    temp->weight = temp->distanceToGoal + temp->distanceTraveled;
    temp->parent = parent;
    return temp;
}
void printQueue(std::priority_queue <Node*> open) {
    std::priority_queue <Node*> temp = open;
    Node* temper = new Node();
    while (!temp.empty()) {
        temper = temp.top();
        cout << temper->x << endl;
        cout << temper->y << endl;
        temp.pop();
    }
}
void aStar(float start[2], float goal[2], std::vector<Node*> path) {
    bool foundGoal = false;

    int c = 0;

    char buffer[128];

    Node* current = new Node();
    Node* temp = new Node();

    std::priority_queue <Node*> open;
    std::priority_queue <Node*> closed;
    //int newStart[2];
    //int newGoal[2];
    //scaleDown(start, newStart);
    //scaleDown(goal, newGoal);
    open.push(GenerateNode(temp, start[0], start[1], 0, hypotf((goal[0] - start[0]), (goal[1] - start[1]))));
    while (!open.empty() && !foundGoal) {
        current = open.top();
        open.pop();
        cout << "While Loop" << endl;
        if (current->x == goal[0] && current->y == goal[1]) {
            foundGoal = true;
            while (current->parent != nullptr) {
                path.insert(path.begin(), current);
                current = current->parent;

struct compare
{
    bool operator()(const Node& a, const Node& b)
    {
        return a.weight < b.weight;
    }
};


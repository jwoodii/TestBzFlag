#pragma once
class Node
{
public:
    int x, y;
    bool childExists;
    int distanceTraveled;
    int distanceToGoal;
    int weight;
    Node* child;
};

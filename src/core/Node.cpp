#include "Node.h"

SPoint::SPoint(int x, int y){
    this->x = x;
    this->y = y;
}

Node::Node(int x, int y){
    this->gridx = x;
    this->gridy = y;
}

Node::Node(int x, int y, int type, bool visited, int distance = INF){
    this->gridx = x;
    this->gridy = y;
    this->type = type;
    this->visited = visited;
}

int Node::getType(){
    return this->type;
}

void Node::setType(int type){
    this->type = type;
}

int Node::getGridPositionX(){
    return this->gridx;
}

int Node::getGridPositionY(){
    return this->gridy;
}

int Node::getDistance(){
    return this->distance;
}

SPoint Node::getParent(){
    return this->parent;
}

bool Node::isEqual(Node s, Node d){
    if(s.getGridPositionX()==d.getGridPositionX() && s.getGridPositionY()==d.getGridPositionY()) return true;
    return false;
}

bool Node::operator<(const Node& n1){
    return this->distance > n1.distance;
}
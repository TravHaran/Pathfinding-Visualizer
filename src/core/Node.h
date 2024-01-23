#pragma once
#include <stddef.h>

int INF = 9999;

enum Type {
    SOURCE, DEST, WALL, EMPTY, CHECKED, FOUND, NOTFOUND, PATH
};

class SPoint {        
    public:
        int x = NULL;
        int y = NULL;
        SPoint(){}
        SPoint(int x, int y);
};

class Node {
    private:
        int gridx = NULL;
        int gridy = NULL;
        double distance = INF;
        int type = NULL;
        bool visited = false;
        SPoint parent = SPoint(NULL, NULL);

    public:
        Node(){};
        Node(int x, int y);
        Node(int x, int y, int type, bool visited, int distance = INF);

        int getType();
        void setType(int type);
        int getGridPositionX();
        int getGridPositionY();
        int getDistance();
        SPoint getParent();
        bool isEqual(Node s, Node d);
        bool operator<(const Node& n1);
};
#pragma once

#include "Node.h"
#include "Utility.h"
#include <GLUT/glut.h>
#include <stddef.h>
#include <vector>
#include <queue>

using namespace std;



class Grid {
    private:
        int startEndNodes = 0;
        Node mapn[n][n];
        Node *start;
        Node *end;
        vector<SPoint> path;
    public:
        vector<Node> nodes;
        priority_queue<Node> nQueue;
        Grid();
        bool gridHasSource();
        bool gridHasDest();
        bool hasNodePlaced(Node n);
        bool hasSourceAndDest();
        void addPoints(int x, int y);
        void removePoints(int x, int y);
        void showPath(int value);
        void reset();
};
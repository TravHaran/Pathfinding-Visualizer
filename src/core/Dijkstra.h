#pragma once

#include <GLUT/glut.h>
#include "Grid.h"

class Dijkstra {
    private:
        Grid* grid;
        bool* canAcceptInput;
    public:
        Dijkstra(Grid& grid, bool& canAcceptInput);
        void run();
        void drive(int);
};
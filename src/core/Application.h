#pragma once

#include <GLUT/glut.h>
#include "Grid.h"
#include "Dijkstra.h"

class Application {
    private:
        bool isOnStartPage;
        bool canAcceptInput;
        Grid grid;
    public:
        Application(int *argcp, char **argv);
        void run();
        void clicked(int i, int j, int type);
        void reDrawPoints();
        void handleMouse(int button, int state, int x, int y);
        void onMouseMovement(int x, int y);
        void onKeyPress(unsigned char key, int x, int y);
        void resize(int w, int h);
        void display();
};
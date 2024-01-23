#include "Application.h"

Application::Application(int *argcp, char **argv){
    canAcceptInput = false;
    isOnStartPage = true;
    grid = Grid();

}

void Application::run(){
    Dijkstra algo = Dijkstra(grid, canAcceptInput);
    algo.run();
}

void Application::clicked(int i, int j, int type){
    if(type != EMPTY){
        float dif = 0.1;
        switch(type){
            case SOURCE:
                glColor3f(0.258, 0.031, 0.388);
                dif = -0.1;
                break;
            case DEST:
                glColor3f(0.772, 0.447, 1);
                dif = -0.1;
                break;
            case WALL:
                glColor3f(0.047, 0.207, 0.278);
			    dif = 0.05;
                break;
            case CHECKED:
                glColor3f(0.250, 0.807, 0.890);
                dif = 0.08;
                break;
            case PATH:
                glColor3f(1, 0.996, 0.415);
			    dif = 0.0;
                break;
        }

        glBegin(GL_POLYGON);
        glVertex2f(i + dif, j + dif);
        glVertex2f(i + dif, j - dif + 1);
        glVertex2f(i - dif + 1, j - dif + 1);
        glVertex2f(i - dif + 1, j + dif);
        glEnd();
    }
}

void Application::reDrawPoints(){
    for(size_t i = 0; i < grid.nodes.size(); i++) {
        int x = grid.nodes[i].getGridPositionX();
        int y = grid.nodes[i].getGridPositionY();
        clicked(x, y, grid.nodes[i].getType());
    }
}

void Application::handleMouse(int button, int state, int x, int  y){
    if(canAcceptInput){
        if(button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            isMouseLeftDown = 0;
            grid.addPoints(x, y);
        } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
            isMouseLeftDown = 1;
        } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP){
            isMouseRightDown = 0;
            grid.removePoints(x, y);
        } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
            isMouseRightDown = 1;
        }
        glutPostRedisplay();
    }
}

void Application::onMouseMovement(int x, int y){
    if(canAcceptInput) {
        if(isMouseLeftDown && grid.nodes.size() > 1) {
            grid.addPoints(x, y);
            glutPostRedisplay();
        }
        if(isMouseRightDown && grid.nodes.size() > 1){
            grid.removePoints(x, y);
            glutPostRedisplay();
        }
    }
}

void Application::resize(int w, int h){
    screenWidth = w;
    screenHeight = h;
    int ratio = 1.0f * w/h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); // setup viewing projection
    glLoadIdentity(); // start with identity matrix
    glOrtho(0.0, n, n, 0.0, -1.0, 1.0); // setup a 10x10x2 viewing world
}

void Application::onKeyPress(unsigned char key, int x, int y){
    switch(key) {
        case 27: //<ESC KEY>
            exit(0);
            break;
        case 115: //'s'
        case 'S':
            if(canAcceptInput && grid.hasSourceAndDest()){
                run(); //starts algorithm
            }
            break;
        case 114: //'r'
        case 'R':
            grid.reset();
            break;
        case 13: //<ENTER> key
            isOnStartPage = false;
            break;
    }
    glutPostRedisplay();
}

void Application::display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(isOnStartPage){
        glClearColor(0.117, 0.423, 0.713, 1.0);
        char title[30] = "OpenGL Pathfinding Visualizer";
        char instrc[13] = "Instructions";
        char text1[21] = "Press Enter To Start";
		char text2[28] = "Press 'r' or 'R' to Restart";
		char text3[38] = "Press 's' or 'S' to Start Visualizing";
		char text4[64] = "Press Left Mouse to place Nodes and Right Mouse to remove Nodes";
		char text5[35] = "Press <ESC KEY> to quit the window";
        char text6[22] = "By: Travis Ratnaharan";
        drawString(findBitmapMidPoint(title), 13, 0.0, title);
        drawString(findBitmapMidPoint(instrc), 16, 0.0, instrc);
        drawString(findBitmapMidPoint(text1), 18, 0.0, text1);
        drawString(findBitmapMidPoint(text2), 19, 0.0, text2);
        drawString(findBitmapMidPoint(text3), 20, 0.0, text3);
        drawString(findBitmapMidPoint(text4), 21, 0.0, text4);
        drawString(findBitmapMidPoint(text5), 22, 0.0, text5);
    } else {
        // display grid
        glClearColor(0.964, 0.964, 0.964, 1.0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                glLineWidth(1);
                glColor3f(0.686, 0.847, 0.972);
                glBegin(GL_LINE_LOOP);
                glVertex2f(i, j);
                glVertex2f(i, j+1);
                glVertex2f(i+1, j+1);
                glVertex2f(i+1, j);
                glEnd();
            }
        }
        reDrawPoints();
    }
    glutSwapBuffers();
    glutPostRedisplay();
}






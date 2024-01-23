#pragma once
#include <GLUT/glut.h>
#include <string>
using namespace std;

const int n = 40;
float screenWidth = 750;
float screenHeight = 750;
int isMouseLeftDown = 0;
int isMouseRightDown = 0;
int flag = 0;

void drawString(float x, float y, float z, char* string){
    glRasterPos3f(x, y, z);
    for(char* c = string; *c != '\0'; c++){
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

float findBitmapMidPoint(const char* str){
    return ((n/2)-(strlen(str)/2) * 8.76 / 31);
}
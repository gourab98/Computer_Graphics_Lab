#include<bits/stdc++.h>
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
using namespace std;

float xStart, xEnd, yStart, yEnd;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void display(){
    float dx = xEnd - xStart;
    float dy = yEnd - yStart;
    int steps;
    if(abs(dx)>abs(dy)) steps = abs(dx);
    else steps = abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = xStart;
    float y = yStart;

    for(int i=0;i<=steps;i++){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
//    cout<<"X: "<<x<<"    Y: "<<y<<endl;
    glEnd();

    x = x + xInc;
    y = y + yInc;

    }
    glFlush();
}


int main(int argc, char** argv){
    cout<<"Input: xStart, yStart, xEnd, yEnd: "<<endl;
    cin>>xStart>>yStart>>xEnd>>yEnd;

    glutInit(&argc,argv);
    glutCreateWindow("DDA ALGO:");
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    init();
    glutDisplayFunc(display);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutMainLoop();

}


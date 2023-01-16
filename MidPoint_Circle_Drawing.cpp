#include<bits/stdc++.h>
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
using namespace std;

int xCenter, yCenter, r;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+xCenter, y+yCenter);
	glEnd();
}

void display(){
    int x = 0;
    int y = r;

    glClear (GL_COLOR_BUFFER_BIT);
    glEnd();
    glColor3f(0.0,1.0,0.0);
    float p = 5/4 - r;
    plot(x, y);

    while(x<=y){
    cout<<"X: "<<x<<"    Y: "<<y<<endl;
    if(p<0){  p = p + (2*x)+3; }
    else{
    p = p + (2*(x-y))+5;
    y--;
    }
    x++;
        plot(x, y);
	plot(x, -y);
	plot(-x, y);
	plot(-x, -y);
	plot(y, x);
	plot(-y, x);
	plot(y, -x);
	plot(-y, -x);
}

   glFlush();

}


int main(int argc, char** argv){
	cout << "Enter the center co-ordinates and radius:\n";
	cin >> xCenter >> yCenter >> r;

    glutInit(&argc,argv);
    glutCreateWindow("Midpoint Circle Drawing Algo:");
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    init();
    glutDisplayFunc(display);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutMainLoop();
    return 0;
}



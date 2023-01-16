#include<bits/stdc++.h>
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
using namespace std;

int xStart, xEnd, yStart, yEnd;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}

void putPixel(int x, int y){
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        cout<<"X: "<<x<<"    Y: "<<y<<endl;
        glEnd();
}

void display(){

   xStart = min(xStart,xEnd);
   xEnd = max(xStart,xEnd);

   yStart = min(yStart,yEnd);
   yEnd = max(yStart,yEnd);

   int x = xStart;
   int y = yStart;

   int dx = xEnd - xStart;
   int dy = yEnd - yStart;


///   cout<<"dx: "<<dx<<"   dy: "<<dy<<endl;
   if(dx>dy) /// For m<1
   {
   int p = 2* dy - dx;

   while(x<=xEnd){
        putPixel(x,y);
        x++;
        if(p<0) {p = p + (2*dy);  }
        else{
            p = p + (2*dy) - (2*dx);
            y++;
        }
   }
   }
   else /// For m>1
   {

      int p = 2* dx - dy;

    while(y<=yEnd){
        putPixel(x,y);
        y++;
        if(p<0) {p = p + (2*dx);  }
        else{
            p = p + (2*dx) - (2*dy);
            x++;
        }
   }

   }
   glFlush();

}


int main(int argc, char** argv){
    cout<<"Input: xStart, yStart, xEnd, yEnd: "<<endl;
    cin>>xStart>>yStart>>xEnd>>yEnd;

    glutInit(&argc,argv);
    glutCreateWindow("Bresenham Line Drawing Algo:");
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    init();
    glutDisplayFunc(display);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutMainLoop();

}


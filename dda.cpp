
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <iostream>
using namespace std;

void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // used to set the background color.
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION); //  sets the current matrix mode to PROJECTION matrix mode.
    glLoadIdentity();            // replaces the current matrix with the identity matrix, so it resets the matrix back to its default state.
    gluOrtho2D(0, 900.0, 0, 900.0);
}


void display()
{
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    int x1, y1, x2, y2;
    cout << "enter data:  "<< endl;
    cin >> x1 >> y1 >> x2 >> y2;
    
    glBegin(GL_POINTS);
    int dy = y2 - y1;
    int dx = x2 - x1;
    float m = (float)(dy) / (dx);
    int steps;
    if (abs(dx) > abs(dy))
        steps = dx;
    else
        steps = dy;

    float x_inc = (float)dx / steps;
    float y_inc = (float)dy / steps;
    
    float x = x1;
    float y = y1;
    
    for (int i=0 ; i<=steps ; i++) {
        glVertex2f(x,y);
        x += x_inc;
        y += y_inc;
    }
    
    glEnd();
    
    glFlush();
       
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // used to initialize the GLUT library.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // sets the initial display mode.
    // When using GL_SINGLE, you can picture your code drawing directly to the display.
    // When using GL_DOUBLE, you can picture having two buffers.
    // One of them is always visible, the other one is not .

    glutCreateWindow("Hello");          // to give title to the output window.
    glutInitWindowSize(1000.0, 1000.0); // specifies the initial window width and height, in pixels.
    glutInitWindowPosition(50.0, 50.0); // positions the top-left corner of the initial window at (x, y).

    glutDisplayFunc(display); // output function for displaying, it's argument function cannot take arguments in it.

    myinit();
    glutMainLoop(); // it keeps calling the displaying functions.

    return 0;
}

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <iostream>
using namespace std;

void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(5.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 900.0, 0, 900.0);
}

void dda(int x1, int y1, int x2, int y2)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    //    glClear(GL_COLOR_BUFFER_BIT);

    //    int x1, y1, x2, y2;
    //    cout << "Enter Points" << endl;
    //    cin >> x1 >> y1 >> x2 >> y2;

    glBegin(GL_POINTS);
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;
    if (abs(dx) >= abs(dy))
    {
        steps = dx;
    }
    else
    {
        steps = dy;
    }

    float x_inc = (float)(dx) / (steps);
    float y_inc = (float)(dy) / (steps);

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        glVertex2f(x, y);
        x += x_inc;
        y += y_inc;
    }
    glEnd();

    glFlush();
}

void input()
{
    int x[3];
    int y[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter x" << i + 1 << " y" << i + 1 << endl;
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            dda(x[i], y[i], x[j], y[j]);
        }
    }
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

    glutDisplayFunc(input); // output function for displaying

    myinit();
    glutMainLoop(); // it keeps calling and calling the displaying functions

    return 0;
}

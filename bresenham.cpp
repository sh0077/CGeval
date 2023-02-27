
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
    int x = x1;
    int y = y1;
    
    if (abs(m) < 1) {
        int m_new = 2 * dy;
        int slope_error = m_new - dx;
        
        for (x = x1, y = y1 ; x <= x2 ; x++) {
            glVertex2f(x, y);
            slope_error += m_new;
            
            if (slope_error >= 0) {
                y += 1;
                slope_error -= 2*dx;
            }
        }
    }
    else // when m>=1
    {
        swap(dx, dy);
        int m_new = 2 * dy;
        int slope_error = m_new - dx;
        
        for (x = x1, y = y1 ; y <= y2 ; y++) {
            glVertex2f(x, y);
            slope_error += m_new;
            
            if (slope_error >= 0) {
                x += 1;
                slope_error -= 2*dx;
            }
        }
        
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

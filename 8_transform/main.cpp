#include <GL/glut.h>
#include <math.h>
#include <iostream>

void myTransorm() {

    int x1 = 10, y1 = 20, x2 = 60, y2 = 70, x3 = 50, y3 = 100;
    glColor3f(0.8, 0.1, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glEnd();

    int tx = 30, ty = -50;
    glColor3f(0.2, 0.6, 0.6);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1+tx, x1+ty);
    glVertex2i(x2+tx, y2+ty);
    glVertex2i(x3+tx, y3+ty);
    glEnd();
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    myTransorm();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(600, 500);
    glutCreateWindow("DDA application");

    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}
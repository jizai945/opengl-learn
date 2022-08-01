#include <GL/glut.h>
#include <math.h>
#include <iostream>

void myDDA(GLfloat x1, GLfloat y1, GLfloat xn, GLfloat yn) {
    GLfloat dx = xn - x1; 
    GLfloat dy = yn - y1;
    GLfloat steps = fabs(dx) > fabs(dy)? dx: dy;
    GLfloat stepX = fabs(dx) / steps;
    GLfloat stepY = fabs(dy) / steps;

    // 画点
    glBegin(GL_POINTS);
    glVertex2f(100, 100);
    for (int i = 0; i < (int)fabs(steps); i++) {
        glVertex2f(x1, y1);
        x1 += stepX;
        y1 += stepY;
    }

}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1);
    glColor3f(0.9, 0.5, 0.8);
    // myDDA(1.5, 3.8, 189.8, 267.5);
    myDDA(189.8, 267.5, 1.5, 3.8);
    glEnd();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 600, 0, 500);
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
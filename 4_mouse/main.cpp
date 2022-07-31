#include <GL/glut.h>

GLint w = 600, h = 500;
GLint dx = 0, dy = 0;

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.87, 0.56, 0.4);
    glPointSize(2);
    glBegin(GL_POLYGON);
    glVertex2i(10+dx, 10+dy);
    glVertex2i(10+dx, 100+dy);
    glVertex2i(100+dx, 100+dy);
    glVertex2i(100+dx, 10+dy);
    glEnd();
    glFlush();
}

void mouseMotion(GLint button, GLint state, GLint x, GLint y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        dx = x;
        dy = h - y;
        glutPostRedisplay();
    }
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, w, 0, h);
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(w, h);
    glutCreateWindow("Mose Motion");

    init();
    glutDisplayFunc(myDisplay);
    glutMouseFunc(mouseMotion);
    glutMainLoop();

    return 0;
}
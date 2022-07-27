#include <GL/glut.h>

void polygonTriangle() {
    int p1[] = {1, 3};
    int p2[] = {3, 0};
    int p3[] = {6, 0};
    int p4[] = {7, 3};
    int p5[] = {6, 6};
    int p6[] = {3, 6};
    int p7[] = {4, 8};
    int p8[] = {5, 8};

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.6, 0.5, 0.2);
    glPointSize(5);
    // glBegin(GL_POINTS);
    // glBegin(GL_POLYGON); // POLYGON
    // glBegin(GL_TRIANGLES); // 三角形 p1-p2-p3  / p4-p5-p6
    glBegin(GL_QUADS); // 四边形
    glVertex2iv(p1);
    glVertex2iv(p2);
    glVertex2iv(p3);
    glVertex2iv(p4);
    glVertex2iv(p5);
    glVertex2iv(p6);
    glVertex2iv(p7);
    glVertex2iv(p8);
    glEnd();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);// 正投影
    glLoadIdentity();
    gluOrtho2D(-10, 20, -10, 30);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Lines");

    init();
    glutDisplayFunc(polygonTriangle);
    glutMainLoop();
    return 0;
}
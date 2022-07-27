#include <GL/glut.h>

void lines() {
    int p1[] = {6, 4};
    int p2[] = {1, 1};
    int p3[] = {3, 7};
    int p4[] = {5, 1};
    int p5[] = {0, 4};

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.3, 0.1, 0.8);
    glPointSize(5);
    // glBegin(GL_POINTS); // 画点
    // glBegin(GL_LINES);  // p1 - p2线段 p3 - p4线段  两两之间
    // glBegin(GL_LINE_STRIP); // p1 - p2 - p3 - p4 - p5 依次
    glBegin(GL_LINE_LOOP); // p1 - p2 - p3 - p4 - p5 - p1 循环
    glVertex2iv(p1); // v表示向量， 取p1中的点
    glVertex2iv(p2);
    glVertex2iv(p3);
    glVertex2iv(p4);
    glVertex2iv(p5);
    glEnd();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);// 正投影
    gluOrtho2D(-10, 20, -10, 30);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Lines");

    init();
    glutDisplayFunc(lines);
    glutMainLoop();
    return 0;
}
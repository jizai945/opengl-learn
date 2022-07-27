#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>

using namespace std;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // RGB值 透明度, 设置颜色，要通过glClear生效
    glMatrixMode(GL_PROJECTION); // 正投影
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100); // 申明显示的范围
}

void myPoints() {
    glClear(GL_COLOR_BUFFER_BIT); // 颜色生效
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0); // 传3个浮点数的值
    glVertex2i(-3, 3);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(10, 20);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(0, -15);
    glEnd();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(200, 300); // 显示位置
    glutInitWindowSize(300, 300); // 窗口大小
    glutCreateWindow("Display Points"); // 窗口名字

    init(); // 自己的初始化方法
    glutDisplayFunc(myPoints); // 显示方法 回调方式
    glutMainLoop();

    return 0;
}
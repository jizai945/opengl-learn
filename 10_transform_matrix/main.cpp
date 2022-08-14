#include <GL/glut.h>
#include <math.h>
#include <iostream>

void axis() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // 使用opengl的默认的矩阵,把矩阵设为对角单位为1的矩阵
    glColor3f(0.9, 0.2, 0.3);
    glBegin(GL_LINES);
    glVertex2i(-100, 0);
    glVertex2i(100, 0);
    glEnd();

    glColor3f(0.2, 0.3, 0.9);
    glBegin(GL_LINES);
    glVertex2i(0, -100);
    glVertex2i(0, 100);
    glEnd();
}

void drawTrans() {
    glLoadIdentity();

    glColor3f(0.55, 0.78, 0.65);
    glBegin(GL_POLYGON);
    glVertex2i(10, 10);
    glVertex2i(50, 10);
    glVertex2i(50, 40);
    glVertex2i(10, 40);
    glEnd();

    glColor3f(0.8, 0.6, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2i(10, 40);
    glVertex2i(50, 40);
    glVertex2i(30, 70);
    glEnd();

    glLoadIdentity();
    glTranslatef(-50.0, 20.0, 0.0); // 平移函数
    glRotatef(30.0, 0.0, 0.0, 1.0); // 旋转 绕着原点旋转30°
    glScalef(3.0, 0.5, 1); // x放大3倍， y缩小一半

    // --------- 再次绘制图形的代码，这时绘制的图像就是偏移后的图像
    glColor3f(0.55, 0.78, 0.65);
    glBegin(GL_POLYGON);
    glVertex2i(10, 10);
    glVertex2i(50, 10);
    glVertex2i(50, 40);
    glVertex2i(10, 40);
    glEnd();

    glColor3f(0.8, 0.6, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2i(10, 40);
    glVertex2i(50, 40);
    glVertex2i(30, 70);
    glEnd();
    // -----------------------
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1);
    glColor3f(0.8, 0.6, 0.4);

    axis(); //绘制坐标系
    drawTrans();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("transform");

    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}
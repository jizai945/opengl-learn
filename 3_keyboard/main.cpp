#include <GL/glut.h>

int xd = 0, yd = 0;

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.8, 0.5, 0.6);
    glPointSize(5);
    glBegin(GL_POLYGON);
    glVertex2i(10+xd, 10+yd);
    glVertex2i(20+xd, 10+yd);
    glVertex2i(20+xd, 0+yd);
    glVertex2i(10+xd, 0+yd);
    glEnd();
    glFlush();
}

void myKeyBoard(unsigned char key, int x, int y) {
    switch(key) {
        case 'w': // 按下w键
            yd++;
            break;
        case 's':
            yd--;
            break;
        case 'a':
            xd--;
            break;
        case 'd':
            xd++;
            break;
        default:
            break;
    }
    glutPostRedisplay(); // 重新刷新
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20.0, 30.0, -20, 30); // 显示范围
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(600, 500);
    glutCreateWindow("key intersection");

    init();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKeyBoard);
    glutMainLoop();

    return 0;
}
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw triangle
    glBegin(GL_TRIANGLES);

    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.5, -0.5);

    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.5, -0.5);

    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0, 0.5);

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Computer Graphics CO1 - OpenGL Triangle");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
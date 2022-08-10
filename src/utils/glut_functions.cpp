#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

bool leftMouseButtonDown = false;
bool rightMouseButtonDown = false;
int mouseXPos = 0;
int mouseYPos = 0;
double cameraY = 10;
double cameraAngle = 30;
double cameraZoom = 10;

float mariposa_x=0;
float mariposa_y=0;

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: // tecla Esc
    case 'q':
    {
        exit(EXIT_SUCCESS); // Terminar la aplicación
        break;
    }
    case 'a':mariposa_x+=0.2; break;
    case 'd':mariposa_x-=0.2; break;

    case 'w':mariposa_y+=0.2; break;
    case 's':mariposa_y-=0.2; break;
    }
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        leftMouseButtonDown = (state == GLUT_DOWN);
    }
    else if (button == GLUT_RIGHT_BUTTON)
    {
        rightMouseButtonDown = (state == GLUT_DOWN);
    }
    else if (button == 3)
    {
        cameraZoom -= 0.1;
    }
    else if (button == 4)
    {
        cameraZoom += 0.1;
    }

    glutPostRedisplay();
}

void mouseMotion(int x, int y)
{
    if (leftMouseButtonDown)
    {
        if (x > mouseXPos)
            cameraAngle += 0.01;
        else if (x < mouseXPos)
            cameraAngle -= 0.01;
        if (y > mouseYPos)
            cameraY += 0.1;
        else if (y < mouseYPos)
            cameraY -= 0.1;
    }
    mouseXPos = x;
    mouseYPos = y;
    glutPostRedisplay();
}
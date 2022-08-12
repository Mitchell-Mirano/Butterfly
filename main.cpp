//#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include <stdlib.h>
#include "./src/rosas/rosas.cpp"
#include "./src/utils/glut_functions.cpp"
#include "./src/utils/random.cpp"
#include "./src/rosas/mariposa.cpp"

float separation = 1;
float x_init = -2.5;
float y_init = -2.5;

int rosas[5][5] = {};

void Linea(float *X0, float *X1, float *C, float A, int f = 1, int P = 0)
{
    glColor3fv(C);
    glLineWidth(A);
    glEnable(GL_LINE_STIPPLE);
    switch (P)
    {
    case 1:
        glLineStipple(f, 0x0101);
        break;
    case 2:
        glLineStipple(f, 0xAAAA);
        break;
    case 3:
        glLineStipple(f, 0x00FF);
        break;
    case 4:
        glLineStipple(f, 0x0c0F);
        break;
    case 5:
        glLineStipple(f, 0x1C47);
        break;
    default:
        glLineStipple(f, 0xFFFF);
        break;
    }
    glBegin(GL_LINES);
    glVertex3fv(X0);
    glVertex3fv(X1);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}

void Ejes(int c)
{
    float P[] = {-20.0, 0.0, 0.0}, P1[] = {20.0, 0.0, 0.0};
    float P2[] = {0.0, -20.0, 0.0}, P3[] = {0.0, 20.0, 0.0};
    float P4[] = {0.0, 0.0, -20.0}, P5[] = {0.0, 0.0, 20.0};
    float C1[] = {1, 0, 0}, C2[] = {0, 0, 1}, C3[] = {0, 1, 0};
    switch (c)
    { // linea punteada
    case 0:
    {
        Linea(P, P1, C1, 2, 2, 1);
        Linea(P2, P3, C2, 2, 2, 1);
        Linea(P4, P5, C3, 2, 2, 1);
        break;
    }
    default:
    { // linea solida de grosor c
        Linea(P, P1, C1, c);
        Linea(P2, P3, C2, c);
        Linea(P4, P5, C3, c);
    }
    }
}



void display(void)
{
    glClearColor(0, 0.5, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    double cameraX = cos(cameraAngle) * cameraZoom;
    double cameraZ = sin(cameraAngle) * cameraZoom;
    gluLookAt(cameraX, cameraY, cameraZ, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0);
    Ejes(0);

    glColor3f(0.52, 0.41, 0.36);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(-10, 0, 10);
    glVertex3f(-10, 0, -10);
    glVertex3f(10, 0, -10);
    glVertex3f(10, 0, 10);
    glEnd();

    glPushMatrix();
    glTranslated(-2, 5.5, 2);
    esfera(0.5, sol);
    glPopMatrix();

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            glPushMatrix();
            glTranslated(x_init + separation * i, 1, y_init + separation * j);
            glScaled(0.05, 0.05, 0.05);
            if (rosas[i][j] == 1)
            {
                Rosa1();
            }
            else
            {
                Rosa2();
            }
            glPopMatrix();
        }
    }

glPushMatrix();
glScaled(0.1,0.1,0.1);
glTranslated(mariposa_x,10,mariposa_y);
glRotated(60,1,0,0);
Mariposa();
glPopMatrix();


    glutSwapBuffers();
}

void Mensaje(){

printf(" =================================================================\n");
printf(" == Campo de flores ==\n");
printf(" =================================================================\n\n ");

printf(" GRUPO 2 : \n");
printf(" \t Balboa Merly, Mirano Mitchell, Vasquez Sebastian\n");

printf("\t FUNCIONALIDADES DE LAS TECLAS Y MOUSE\n\n");

printf("[mouse]\t Movimiento de escena\n");
printf("[Rueda del mouse]\t Acercar o alejar la escena \n");
printf(" [w]\t Mover la mariposa hacia arriba \n");
printf(" [a]\t Mover la mariposa hacia la izquierda \n");
printf(" [s]\t Mover la mariposa hacia abajo \n");
printf(" [d]\t Mover la mariposa hacia la derecha \n");

printf("\n\n");

}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    Mensaje();
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            rosas[i][j] = randomRose();
        }
    };

    glutInitWindowPosition(0, 0);
    glutCreateWindow("Campo de Flores");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key); // control del teclado
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutMainLoop();
    return EXIT_SUCCESS;
}
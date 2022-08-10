//#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<cmath>
#include <stdlib.h>
#include "./src/rosas/rosas.cpp"


float separation = 10;
float x_init=-50;
float y_init=-50;


void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1, 1, -1, 1, 1.5, 20.0);
    glMatrixMode (GL_MODELVIEW);
}



static void key(unsigned char key, int x, int y){
    switch (key) {
    case 27 : // tecla Esc
    case 'q': {
        exit(EXIT_SUCCESS); // Terminar la aplicación
        break;
    }

    }
glutPostRedisplay();
}


void Linea(float *X0, float *X1, float *C, float A , int f = 1, int P=0 )
{
    glColor3fv(C);
    glLineWidth(A);
    glEnable(GL_LINE_STIPPLE);
    switch (P){
        case 1: glLineStipple (f, 0x0101); break;
        case 2: glLineStipple (f, 0xAAAA); break;
        case 3: glLineStipple (f, 0x00FF); break;
        case 4: glLineStipple (f, 0x0c0F); break;
        case 5: glLineStipple (f, 0x1C47); break;
        default: glLineStipple (f, 0xFFFF); break;
    }
    glBegin(GL_LINES);
    glVertex3fv(X0);
    glVertex3fv(X1);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}

void Ejes(int c){
    float P[]={-20.0,0.0,0.0} , P1[]={20.0,0.0,0.0};
    float P2[]={0.0,-20.0,0.0}, P3[]={0.0,20.0,0.0};
    float P4[]={0.0,0.0,-20.0} , P5[]={0.0,0.0,20.0};
    float C1[]={1,0,0}, C2[]={0,0,1}, C3[]={0,1,0};
    switch (c){ // linea punteada
    case 0:{
        Linea(P,P1,C1,2,2,1);
        Linea(P2,P3,C2,2,2,1);
        Linea(P4,P5,C3,2,2,1);
        break;
    }
    default :{ // linea solida de grosor c
        Linea(P,P1,C1,c);
        Linea(P2,P3,C2,c);
        Linea(P4,P5,C3,c);
        }
    }
}





void display(void)
 {
    glClearColor(0,0,0,0);
    glClear (GL_COLOR_BUFFER_BIT);

    glLoadIdentity ();
    gluLookAt (-5, 5.0, 15, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    Ejes(0);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            glPushMatrix();
                glTranslated(x_init+separation*i,0, y_init+separation*j);
                glScaled(0.5,0.5,0.5);
                Rosa1();
            glPopMatrix();
        }
        
    }
    


    glutSwapBuffers ();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1920,1080);

    glutInitWindowPosition(0,0);
    glutCreateWindow("Poliedros en 3d");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key); // control del teclado

    glutMainLoop();
    return EXIT_SUCCESS;
}
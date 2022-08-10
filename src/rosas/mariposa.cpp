#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include <stdlib.h>

void mariposa (float *c, float R )
{
    float x,y,r;


    glBegin(GL_POLYGON);

    for(float i=0; i<7*M_PI/16;i=i+0.001 )
    {
        r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));
            x=sin(i)*r*R;
            y=r*cos(i)*R;
            glColor3fv(c);
            glVertex2f(x+0.0f,y+0.0f-2.0);

    }


    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(c);
    for(float i=7*M_PI/16; i<9.5*M_PI/16;i=i+0.001 )
        {
        r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));
        x=sin(i)*r*R;
        y=r*cos(i)*R;
        glVertex2f(x+0.0f,y+0.0f-2.0);
        }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(c);
    for(float i=9.5*M_PI/16; i<14*M_PI/16;i=i+0.001 ){

        r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));

        x=sin(i)*r*R;
        y=r*cos(i)*R;

        glVertex2f(x+0.0f,y+0.0f-2.0);
        }
        glEnd();


    glBegin(GL_POLYGON);
    glColor3fv(c);
       for(float i=9.5*M_PI/16; i<13.8*M_PI/16;i=i+0.001 ){
        r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));
        x=-sin(i)*r*R;
        y=r*cos(i)*R;
        glVertex2f(x+0.0f,y+0.0f-2.0);
        }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(c);
    for(float i=7*M_PI/16; i<9.5*M_PI/16;i=i+0.001 ){

        r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));

        x=-sin(i)*r*R;
        y=r*cos(i)*R;

        glVertex2f(x+0.0f,y+0.0f-2.0);
        }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3fv(c);


        for(float i=0; i<6.8*M_PI/16;i=i+0.001 ){

        r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));
        x=-sin(i)*r*R;
        y=r*cos(i)*R;

        glVertex2f(x+0.0f,y+0.0f-2.0);
        }

    glEnd();
    glBegin(GL_POLYGON);
    glColor3fv(c);


        for(float i=14.2*M_PI/16; i<17.7*M_PI/16;i=i+0.001 ){

        r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));

        x=sin(i)*r*R;
        y=r*cos(i)*R;

        glVertex2f(x+0.0f,y+0.0f-2.0);
        }

    glEnd();


}

void Mariposa(void)
{

float black[] = {0,0,0}, white[]={1,1,1}, blue[] = {0.70, 0.67, 0.68};
float red[] = {1.00, 0.26, 0.36}, green[]={0,1,0}, yellow[]={1,1,0};
float cyan[]={0,1,1}, pink[]={1,0.5,0.5}, orange[]={0.1, 0.1, 0.04};

    mariposa(orange,1);
    mariposa(red,0.8);
    mariposa(cyan,0.7);
    mariposa(yellow,0.6);
    mariposa(pink,0.5);
    mariposa(blue,0.4);
    mariposa(green,0.3);
    mariposa(red,0.2);

}

//#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>
#include <math.h>

void Circunferencia(float x,float y, float r, float* color, float t, float mode=GL_FILL){

    glColor3fv(color);
    glLineWidth(3);
    glPolygonMode(GL_FRONT_AND_BACK,mode);
    glBegin(GL_POLYGON);
        for (float i = 0; i <= 2*M_PI ; i = i + 0.05)
        glVertex2f(x+r*cos(i+t),y+r*sin(i+t));
    glEnd();

}

void CircunferenciaNormal(float x,float y, float r, float* color){

    glColor3fv(color);
    glLineWidth(3);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_POLYGON);
        for (float i = 0; i <= 2*M_PI ; i = i + 0.05)
        glVertex2f(x+r*cos(i),y+r*sin(i));
    glEnd();
}



void Rosa(float x, float y, float r,int n, float*color, float desface=0,float mode=GL_FILL)
{   

    if (mode == GL_LINE){
        glColor3fv(color);
        glLineWidth(3);
        glPolygonMode(GL_FRONT_AND_BACK,mode);
        glBegin(GL_POLYGON);
            for(float t=-1.5*M_PI; t<0.5*M_PI; t= t+0.01)
            {
                glVertex2d(x+r*sin(n*t)*cos(t+desface),y+r*sin(n*t)*sin(t+desface));
            }
        glEnd();
    }

    if (mode == GL_FILL){
        glColor3fv(color);
        glLineWidth(3);
        glPolygonMode(GL_FRONT_AND_BACK,mode);
        glBegin(GL_POLYGON);
            glVertex2f(x,y);
            for(float t=-1.5*M_PI; t<0.5*M_PI; t= t+0.01)
            {
                glVertex2d(x+r*sin(n*t)*cos(t+desface),y+r*sin(n*t)*sin(t+desface));
            }
        glEnd();
    }
}


void Tallo(float x, float y,float width, float height,float*color,GLenum mode, float width_or_size=0)
{
    glColor3fv(color);

    if (mode == GL_LINES){
        glLineWidth(width_or_size);
    }

    if (mode == GL_POINTS){
        glPointSize(width_or_size);
    }
    glPolygonMode(GL_POINTS,mode); //
    glBegin(GL_POLYGON);
        glVertex2f(x,y);
        glVertex2f(x+width,y);
        glVertex2f(x+width,y-height);
        glVertex2d(x,y-height);
    glEnd();
}


void Hoja(float x, float y, float k,float*color,GLenum mode, float width_or_size=0)
{
    glColor3fv(color);

    if (mode == GL_LINES){
        glLineWidth(width_or_size);
    }

    if (mode == GL_POINTS){
        glPointSize(width_or_size);
    }

    glPolygonMode(GL_FRONT_AND_BACK,mode);
    glBegin(GL_POLYGON);
        glVertex2d(x,y);
        for(float t=-1.5*M_PI; t<0.5*M_PI; t= t+0.01)
        {
            glVertex2d(x+k*sqrt(cos(2*t))*cos(t), y+ k*sqrt(cos(2*t))*sin(t));
        }
    glEnd();
}


void mypetalo(float x, float y, float r1, float r2, float k, float* color) {


    int n_points =20;
    float increment_r =(r2-r1)/n_points;
    float increment_t=(2*M_PI/10)/n_points;

    glColor3fv(color);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glBegin(GL_POLYGON);

    for (int i = 0; i <n_points; i++)
    {   
        float theta=k-2*M_PI/10 +i*increment_t;
        float x_v=x+ (r1+i*increment_r)*sin(theta);float y_v=y+ (r1+i*increment_r)*cos(theta);

       glVertex2f(x_v,y_v);
    }

     for (int i = 0; i <=n_points; i++)
    {   
        float theta=k+i*increment_t;
        float x_v=x+ (r2-i*increment_r)*sin(theta);float y_v=y+ (r2-i*increment_r)*cos(theta);

       glVertex2f(x_v,y_v);
    }
    
    glEnd();

}



void LineasR (float r1, float r2 , float theta,float* color){

    glColor3fv(color);
    glLineWidth(4);
    glBegin(GL_LINES);
        glVertex2f(r1*sin(theta), r1*cos(theta));
        glVertex2f(r2*sin(theta), r2*cos(theta));
    glEnd();
   
}


void LineasRdiagonales(float x,float y,float r1, float r2, float k, float* color) {


    int n_points =10;
    float increment_r =(r2-r1)/n_points;
    float increment_t=(2*M_PI/10)/n_points;

    glColor3fv(color);
    glPointSize(5);

    for (int i = 0; i <n_points; i++)
    {   

        float theta=k-2*M_PI/10 +i*increment_t;
        float x_v=x+(r1+i*increment_r)*sin(theta);float y_v=y+ (r1+i*increment_r)*cos(theta);

        float r=r1+i*increment_r;

        glBegin(GL_LINES);
            glVertex2f(r*sin(k),r*cos(k));
            glVertex2f(x_v,y_v);
        glEnd();
    }


     for (int i = 0; i <n_points; i++)
    {   

         float theta=k+i*increment_t;
        float x_v=x+ (r2-i*increment_r)*sin(theta);float y_v=y+ (r2-i*increment_r)*cos(theta);

        float r=r2-i*increment_r;

        glBegin(GL_LINES);
            glVertex2f(r*sin(k),r*cos(k));
            glVertex2f(x_v,y_v);
        glEnd();
    }
}

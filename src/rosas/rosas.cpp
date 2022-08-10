//#include <windows.h>s
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "../utils/functions.cpp"
#include "../utils/colors.cpp"


void Rosa1(void){
    Tallo(-0.5,0,1,18,green,GL_FILL);
    Hoja(0,-12,5,green,GL_FILL);
    
    for (float t = 0; t<=2*M_PI;t=t+2*M_PI/5)
    {
        for (float i = t+2*M_PI/30; i<=2*M_PI+t+2*M_PI/30;i=i+2*M_PI/3)
        {
            float x = 6*sin(i); float y = 6*cos(i);
            Circunferencia(x,y,1.5,black,t,GL_FILL);
        }

        for (float i = t+2*M_PI/30; i<=2*M_PI+t+2*M_PI/30;i=i+2*M_PI/3)
        {
            float x = 5.9*sin(i); float y = 5.9*cos(i);
            Circunferencia(x,y,1.5,gris,t,GL_FILL);
        }
        
    }


    for (float t = 0; t<=2*M_PI;t=t+2*M_PI/5)
    {
        for (float i = t+2*M_PI/30; i<=2*M_PI+t+2*M_PI/30;i=i+2*M_PI/3)
        {
            float x = 5.6*sin(i); float y = 5.6*cos(i);
            Circunferencia(x,y,1.5,black,t,GL_FILL);
        }

        for (float i = t+2*M_PI/30; i<=2*M_PI+t+2*M_PI/30;i=i+2*M_PI/3)
        {
            float x = 5.5*sin(i); float y = 5.5*cos(i);
            Circunferencia(x,y,1.5,white,t,GL_FILL);
        }
        
    }


    for (float t = 0; t<=2*M_PI;t=t+2*M_PI/5)
    {
        for (float i = t+2*M_PI/30; i<=2*M_PI+t+2*M_PI/30;i=i+2*M_PI/3)
        {   
            float x = 5.8*sin(i); float y =5.8*cos(i);

            for (float b =i-M_PI/2; b <i+M_PI/2; b=b+M_PI/10)
            {
        
                Circunferencia(x+sin(b),y+cos(b),0.15,purple,t,GL_LINE);
            }

        }
        
    }


    for (float t = 0; t<=2*M_PI;t=t+2*M_PI/3)
    {
        for (float i = t+2*M_PI/30; i<=2*M_PI+t+2*M_PI/30;i=i+2*M_PI/3)
        {
             Rosa(0,0,6.5,5,black,i); 
        }
    }

    for (float t = 0; t<=2*M_PI;t=t+2*M_PI/3)
    {
        for (float i = t+2*M_PI/30; i<=2*M_PI+t+2*M_PI/30;i=i+2*M_PI/3)
        {
             Rosa(0,0,6.4,5,green,i); 
        }
    }


    for (float t = 0; t<=2*M_PI;t=t+2*M_PI/3)
    {
        for (float i = t+2*M_PI/30; i<=2*M_PI+t+2*M_PI/30;i=i+2*M_PI/3)
        {
             Rosa(0,0,6.1,5,black,i); 
        }
    }

    for (float t = 0; t<=2*M_PI;t=t+2*M_PI/3)
    {
        for (float i = t+2*M_PI/30; i<=2*M_PI+t+2*M_PI/30;i=i+2*M_PI/3)
        {
             Rosa(0,0,6,5,white,i); 
        }
    }



    for (float t = 0; t<=2*M_PI;t=t+2*M_PI/120)
    {
    
        Rosa(0,0,5,30,yellow,t); 
    
    }

    
    for (float t = 0; t<=2*M_PI;t=t+2*M_PI/5)
    {
        for (float i = t+2*M_PI/30; i<=2*M_PI+t+2*M_PI/30;i=i+2*M_PI/5)
        {
             Rosa(0,0,4.5,3,black,i); 
        }
    }

     for (float t = 0; t<=2*M_PI;t=t+2*M_PI/5)
    {
        for (float i = t+2*M_PI/30; i<=2*M_PI+t+2*M_PI/30;i=i+2*M_PI/5)
        {
             Rosa(0,0,4.4,3,morado,i); 
        }
    }

    Circunferencia(0,0,1.8,yellow,0);
    Circunferencia(0,0,1.8,black,0,GL_LINE);

    for (float t = 0; t<=2*M_PI;t=t+2*M_PI/5)
    {
        for (float i = t+2*M_PI/30; i<=2*M_PI+t+2*M_PI/30;i=i+2*M_PI/5)
        {
             Rosa(0,0,4.2,3,black,i,GL_LINE); 
        }
    }

    for (float t = 0; t<=2*M_PI;t=t+2*M_PI/15)
    {
        float x = 3.6*sin(t); float y = 3.6*cos(t);
        Circunferencia(x,y,0.2,purple,t,GL_LINE);
    
    }


     for (float t = 0; t<=2*M_PI;t=t+2*M_PI/5)
    {
        for (float i = t+2*M_PI/30; i<=2*M_PI+t+2*M_PI/30;i=i+2*M_PI/5)
        {
             Rosa(0,0,1.8,3,black,i,GL_LINE); 
        }
    }
}



void Rosa2(void){

    Tallo(-0.5,0,1,18,green,GL_FILL);
    Hoja(0,-12,5,green,GL_FILL);
    //circuferencias de afuera

        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            float x=4*sin(i); float y=4*cos(i);
            CircunferenciaNormal(x,y,2,black);
        }

        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            float x=3.9*sin(i); float y=3.9*cos(i);
            CircunferenciaNormal(x,y,2,gris);
        }


        for (float i =3*M_PI/5; i <=2*M_PI+3*M_PI/5; i=i+2*M_PI/5)
        {
            float x=4*sin(i); float y=4*cos(i);
            CircunferenciaNormal(x,y,2,black);
        }

        for (float i =3*M_PI/5; i <=2*M_PI+3*M_PI/5; i=i+2*M_PI/5)
        {
            float x=3.9*sin(i); float y=3.9*cos(i);
            CircunferenciaNormal(x,y,2,gris);
        }


    //petalos grandes normales

        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            mypetalo(0,0,1,6,i,black);

        }


        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            mypetalo(0,0,1,5.9,i,green);

        }


        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            mypetalo(0,0,1,5.4,i,black);

        }


        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            mypetalo(0,0,1,5.3,i,green);

        }

         for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
           
            LineasRdiagonales(0,0,1.5,5.3,i,black);
        }

    //petalos grandes invertidos

        for (float i =3*M_PI/5; i <=2*M_PI+3*M_PI/5; i=i+2*M_PI/5)
        {
            mypetalo(0,0,2,5.5,i,black);

        }

        for (float i =3*M_PI/5; i <=2*M_PI+3*M_PI/5; i=i+2*M_PI/5)
        {
            mypetalo(0,0,2,5.4,i,green);

        }

        //
        for (float i =3*M_PI/5; i <=2*M_PI+3*M_PI/5; i=i+2*M_PI/5)
        {
            mypetalo(0,0,3,4.8,i,black);

        }

        for (float i =3*M_PI/5; i <=2*M_PI+3*M_PI/5; i=i+2*M_PI/5)
        {
            mypetalo(0,0,3,4.7,i,pink);

        }


        //
         for (float i =3*M_PI/5; i <=2*M_PI+3*M_PI/5; i=i+2*M_PI/5)
        {
            mypetalo(0,0,2,4.2,i,black);

        }

        for (float i =3*M_PI/5; i <=2*M_PI+3*M_PI/5; i=i+2*M_PI/5)
        {
            mypetalo(0,0,2,4.1,i,pink);

        }

        //

         for (float i =3*M_PI/5; i <=2*M_PI+3*M_PI/5; i=i+2*M_PI/5)
        {
            mypetalo(0,0,1,3.6,i,black);

        }

        for (float i =3*M_PI/5; i <=2*M_PI+3*M_PI/5; i=i+2*M_PI/5)
        {
            mypetalo(0,0,1,3.5,i,pink);

        }


        // directas intermedias

        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            mypetalo(0,0,1,3.2,i,black);

        }


        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            mypetalo(0,0,1,3.1,i,purple);

        }

        //

        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            mypetalo(0,0,1.6,2.5,i,black);

        }

        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            mypetalo(0,0,1.6,2.4,i,white);

        }

        //

         for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            mypetalo(0,0,1.5,2.2,i,black);

        }

        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            mypetalo(0,0,1.5,2.1,i,white);

        }


        //

        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            mypetalo(0,0,0.5,1.5,i,black);

        }

        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
            mypetalo(0,0,0.5,1.3,i,yellow);

        }

        CircunferenciaNormal(0,0,0.5,yellow);


         //LineasR
        for (float i =3*M_PI/5; i <=2*M_PI+3*M_PI/5; i=i+2*M_PI/5)
        {
           LineasR(4.7,5.5,i,black);

        }


        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
           
            LineasR(3.2,5.3,i,black);
        }


        for (float i = 0; i <=2*M_PI; i=i+2*M_PI/5)
        {
           
            LineasR(1.3,2.1,i,black);
        }

}


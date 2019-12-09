#include "header.h"

void bullet_hell_1(){

    //prava linija

    glColor3f(1, 1, 1);
	glLineWidth(12.7);
    glBegin(GL_LINES);
        glVertex2f(0.5-t,-0.6);
        glVertex2f(0.5-t, 0);
    glEnd();
    
    for (float i=-0.6;i<=0;i+=0.01)
        check_collision(0.5-t,i);
}

void bullet_hell_2(){

    //spirala vudjava

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<15;te+=0.01){
            x=3*t*pow(2.73,-0.3*te)*sin(te);
            y=3*t*pow(2.73,-0.3*te)*cos(te)-0.4;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_3(){

    //8

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<t*2*3.14;te+=0.01){
            x=t*cos(te)*sin(te);
            y=t*sin(te)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_4(){

    //butterfly hard

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<t*2*3.14;te+=0.01){
            x=t*sin(te)*(pow(2.71,cos(te))-2*cos(4*te)-(pow(sin(te/12),5)));
            y=t*cos(te)*(pow(2.71,cos(te))-2*cos(4*te)-(pow(sin(te/12),5)))-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_5(){

    //butterfly

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<t*2*3.14;te+=0.01){
            x=0.2*t*sin(te)*(pow(2.71,cos(te))-2*cos(4*te)-(pow(sin(te/12),5)));
            y=0.2*t*cos(te)*(pow(2.71,cos(te))-2*cos(4*te)-(pow(sin(te/12),5)))-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_6(){

    //Lisajous - undodgable

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<t*50*3.14;te+=0.01){
            x=0.25*4*sin((12/13.0)*te);
            y=0.25*3*sin(te)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_7(){

    //spirala

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<t*6*3.14;te+=0.01){
            x=0.1*t*te*cos(te);
            y=0.1*t*te*sin(te)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_8(){

    //zvezda

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<t*3*3.14;te+=0.01){
            x=t*pow(cos(te),3);
            y=t*pow(sin(te),3)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_9(){

    //nesto 1 6 14

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<t*4*3.14;te+=0.001){
            x=t*(cos(te)+cos(6*te)/2+sin(14*te)/3);
            y=t*(sin(te)+sin(6*te)/2+cos(14*te)/3)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_10(){

    //nesto 1 10 14

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<t*2*3.14;te+=0.001){
            x=0.7*t*(cos(te)+cos(10*te)/2+sin(14*te)/3);
            y=0.7*t*(sin(te)+sin(10*te)/2+cos(14*te)/3)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_11(){

    //nesto 1 11 14

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<t*2*3.14;te+=0.001){
            x=0.5*t*(cos(te)+cos(11*te)/2+sin(14*te)/3);
            y=0.5*t*(sin(te)+sin(11*te)/2+cos(14*te)/3)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_12(){

    //nesto 1 12 14

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<t*2*3.14;te+=0.001){
            x=0.5*(cos(te)+cos(12*te)/2+sin(14*te)/3);
            y=0.5*(sin(te)+sin(12*te)/2+cos(14*te)/3)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_13(){

    //nesto 1 11 19

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<t*3*3.14;te+=0.001){
            x=0.5*(cos(te)+cos(11*te)/2+sin(19*te)/3);
            y=0.5*(sin(te)+sin(11*te)/2+cos(19*te)/3)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_14(){

    //nesto 11 12 0

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<t*3*3.14;te+=0.001){
            x=0.3*(cos(11*te)+cos(12*te)/2+sin(0*te)/3);
            y=0.3*(sin(11*te)+sin(12*te)/2+cos(0*te)/3)-0.2-t*0.5;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_15(){

    //nesto 1 11 t

    float x=0,y=0;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<t*3*3.14;te+=0.001){
            x=0.6*(cos(11*te)+cos(12*te)/2+sin(20*t*te)/3);
            y=0.6*(sin(11*te)+sin(12*te)/2+cos(20*t*te)/3)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}
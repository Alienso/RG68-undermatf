#include "header.h"

void bullet_hell_1(){

    glColor3f(1, 1, 1);
	glLineWidth(12.7);
    glBegin(GL_LINES);
        glVertex2f(0.5-t,-0.6);
        glVertex2f(0.5-t, 0);
    glEnd();
    
    for (float i=-0.6;i<=0;i+=0.01)
        check_collision(0.5-t,i);
}

VOID bullet_hell_2(){

    float x=0,x2=0;
    float y=0,y2=0;

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
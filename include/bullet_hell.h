#include "header.h"

void bullet_hell_0(){

    //prava linija
    if (maxt<t && cm==1)
        maxt=t;

    if (maxt<0.7)
        cm=1.7;
    
    float T=t*cm;

    glColor3f(1, 1, 1);
	glLineWidth(12.7);
    glBegin(GL_LINES);
        glVertex2f(0.5-T,-0.6);
        glVertex2f(0.5-T, 0);
    glEnd();
    
    for (float i=-0.6;i<=0;i+=0.01)
        check_collision(0.5-T,i);
}

void bullet_hell_1(){

    float x=0,y=0;
    float T=t*cm;
    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<T*2*3.14;te+=0.001){
            x=0.3*(2*cos(te)+sin(2*te)*cos(60*te));
            y=0.3*(sin(2*te)+sin(60*te));
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_2(){

    float x=0,y=0;
    float T=t*cm;
    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<T*7*3.14;te+=0.001){
            x=0.1*(te-1.6*cos(24*te))-0.5;
            y=0.1*(te-1.6*sin(25*te))-0.5;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_3(){

    //8

    float x=0,y=0;
    float T=t*cm;
    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=T*2*3.14-0.3;te<T*2*3.14;te+=0.01){
            x=T*cos(te)*sin(te);
            y=T*sin(te)-0.4;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_4(){

    //butterfly hard

    float x=0,y=0;
    float T=t*cm;
    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<T*2*3.14;te+=0.01){
            x=T*sin(te)*(pow(2.71,cos(te))-2*cos(4*te)-(pow(sin(te/12),5)));
            y=T*cos(te)*(pow(2.71,cos(te))-2*cos(4*te)-(pow(sin(te/12),5)))-0.4;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_5(){

    //butterfly

    float x=0,y=0;
    float T=t*cm;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<T*2*3.14;te+=0.01){
            x=0.2*T*sin(te)*(pow(2.71,cos(te))-2*cos(4*te)-(pow(sin(te/12),5)));
            y=0.2*T*cos(te)*(pow(2.71,cos(te))-2*cos(4*te)-(pow(sin(te/12),5)))-0.4;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_6(){

    //Lisajous - undodgable

    float x=0,y=0;
    float T=t*cm;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=T*50*3.14-10;te<T*50*3.14;te+=0.01){
            x=0.25*4*sin((12/13.0)*te);
            y=0.25*3*sin(te)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_7(){

    //spirala ez

    float x=0,y=0;
    float T=t*cm;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<T*6*3.14;te+=0.01){
            x=0.1*t*te*cos(te);
            y=0.1*t*te*sin(te)-0.4;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_8(){

    //zvezda ez

    float x=0,y=0;
    float T=t*cm;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<T*3*3.14;te+=0.01){
            x=T*pow(cos(te),3);
            y=T*pow(sin(te),3)-0.4;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_9(){

    //nesto 1 6 14 hard

    float x=0,y=0;
    float T=t*cm;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=T*4*3.14-1;te<T*4*3.14;te+=0.001){
            x=T*(cos(te)+cos(6*te)/2+sin(14*te)/3);
            y=T*(sin(te)+sin(6*te)/2+cos(14*te)/3)-0.4;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_10(){

    //nesto 1 10 14 med

    float x=0,y=0;
    float T=t*cm;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=T*2*3.14-3;te<T*2*3.14;te+=0.001){
            x=0.7*T*(cos(te)+cos(10*te)/2+sin(14*te)/3);
            y=0.7*T*(sin(te)+sin(10*te)/2+cos(14*te)/3)-0.4;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_11(){

    //nesto 1 11 14 ez-med

    float x=0,y=0;
    float T=t*cm;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<T*2*3.14;te+=0.001){
            x=0.5*T*(cos(te)+cos(11*te)/2+sin(14*te)/3);
            y=0.5*T*(sin(te)+sin(11*te)/2+cos(14*te)/3)-0.4;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_12(){

    //nesto 1 12 14 ez
    
    float x=0,y=0;
    float T=t*cm;
    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=T*2*3.14-1;te<T*2*3.14;te+=0.001){
            if (te<0)
                te=0;
            x=0.5*(cos(te)+cos(12*te)/2+sin(14*te)/3);
            y=0.5*(sin(te)+sin(12*te)/2+cos(14*te)/3)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_13(){

    //nesto 1 11 19 ez-med

    float x=0,y=0;
    float T=t*cm;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=T*3*3.14-1;te<T*3*3.14;te+=0.001){
            x=0.5*(cos(te)+cos(11*te)/2+sin(19*te)/3)+T/2;
            y=0.5*(sin(te)+sin(11*te)/2+cos(19*te)/3)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_14(){

    //nesto 11 12 0 ez

    float x=0,y=0;
    float T=t*cm;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<T*3*3.14;te+=0.001){
            x=0.3*(cos(11*te)+cos(12*te)/2+sin(0*te)/3);
            y=0.3*(sin(11*te)+sin(12*te)/2+cos(0*te)/3)-0.2-T*0.5;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_15(){

    //nesto 1 11 t ez

    float x=0,y=0;
    float T=t*cm;

    glColor3f(1, 1, 1);
	glPointSize(2);
    glBegin(GL_POINTS);
        for (float te=0;te<T*3*3.14;te+=0.001){
            x=0.6*(cos(11*te)+cos(12*te)/2+sin(20*T*te)/3);
            y=0.6*(sin(11*te)+sin(12*te)/2+cos(20*T*te)/3)-0.2;
            glVertex2f(x,y);
            check_collision(x,y);
        }
    glEnd();

}

void bullet_hell_16(){}
void bullet_hell_17(){}
void bullet_hell_18(){}
void bullet_hell_19(){}
void bullet_hell_20(){}

void bullet_hell_21(){

    glColor3f(1,1,1);
    glLineWidth(2);

    if (hp<0)
        hp=0;

    switch (shield_side){
        case 0:
            glBegin(GL_LINE_STRIP);
                glVertex2f(x_hearth,y_hearth+0.07);
                glVertex2f(x_hearth+0.05,y_hearth+0.1);
                glVertex2f(x_hearth-0.05,y_hearth+0.1);
            glEnd();
            break;
        case 1:
            glBegin(GL_LINE_STRIP);
                glVertex2f(x_hearth,y_hearth-0.01);
                glVertex2f(x_hearth+0.05,y_hearth-0.04);
                glVertex2f(x_hearth-0.05,y_hearth-0.04);
            glEnd();
            break;
        case 2:
            glBegin(GL_LINE_STRIP);
                glVertex2f(x_hearth-0.04,y_hearth+0.03);
                glVertex2f(x_hearth-0.07,y_hearth+0.08);
                glVertex2f(x_hearth-0.07,y_hearth-0.02);
            glEnd();
            break;
        case 3:
            glBegin(GL_LINE_STRIP);
                glVertex2f(x_hearth+0.04,y_hearth+0.03);
                glVertex2f(x_hearth+0.07,y_hearth-0.02);
                glVertex2f(x_hearth+0.07,y_hearth+0.08);
            glEnd();
            break;
    
        default:
            break;
    }

    int i,j;
    for (i=0;i<50;i++)
        if (boss_field[i][50]==1)
            draw_spike(2,i,50);
    for (i=99;i>50;i--)
        if (boss_field[i][50]==1)
            draw_spike(3,i,50);
    for (i=0;i<50;i++)
        if (boss_field[50][i]==1)
            draw_spike(0,50,i);
    for (i=99;i>50;i--)
        if (boss_field[50][i]==1)
            draw_spike(1,50,i);

    glutPostRedisplay();
    return;
}
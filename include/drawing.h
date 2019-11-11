#ifndef _DRAWING_
#define _DRAWING_

#include <GL/glut.h>
#include "header.h"
#include "inventory.h"

static void on_display_encounter(void){

    draw_base();
    draw_hearth();
    highlight_current();
    if (in_menu_menu)
        draw_menu();
    if (mercy)
        draw_mercy();

    glutSwapBuffers();
}

static void on_display_walking(void){
    return;
}

static void on_display_combat(void){

    draw_base();
    draw_hearth();

    glutSwapBuffers();
}

void draw_base(){

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);
	glLineWidth(12.7);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.4,-0.6);
        glVertex2f(0.4,-0.6);
        glVertex2f(0.4, 0.2);
        glVertex2f(-0.4, 0.2);
    glEnd();

	glLineWidth(5);

	int i=0;
	for(i=0;i<4;i++){

		glBegin(GL_LINE_LOOP);
	        glVertex2f(-0.9+i*0.5,-0.9);
	        glVertex2f(-0.55+i*0.5,-0.9);
	        glVertex2f(-0.55+i*0.5,-0.7);
	        glVertex2f(-0.9+i*0.5,-0.7);
	    glEnd();

	switch (i){
		case 0:
			strcpy(wtp,"Attack\0");
			break;
		case 1:
			strcpy(wtp,"Talk\0");
			break;
		case 2:
			strcpy(wtp,"Item\0");
			break;
		case 3:
			strcpy(wtp,"Mercy\0");
			break;
	}	

	draw_text(wtp,-0.8+i*0.5,-0.8,1,1,1);
	}

    glColor3f(1,0,0);
    glLineWidth(20);

    glBegin(GL_LINES);
	    glVertex2f(-0.6,0.925);
	    glVertex2f(1-0.6,0.925);
    glEnd();

    glBegin(GL_LINES);
	    glVertex2f(-0.6,0.825);
	    glVertex2f(1-0.6,0.825);
	glEnd();

    draw_text("HP:\0",-0.9,0.9,1,0,0);

        glColor3f(0,1,0);
        glLineWidth(20);

    	glBegin(GL_LINES);
	        glVertex2f(-0.6,0.925);
	        glVertex2f((float)(hp/20.0)-0.6,0.925);
	    glEnd();

    draw_text("ENEMY:\0",-0.9,0.8,1,0,0);

        glColor3f(0,1,0);
        glBegin(GL_LINES);
	        glVertex2f(-0.6,0.825);
	        glVertex2f((float)(enemy_hp/20.0)-0.6,0.825);
	    glEnd();


}

void draw_hearth(){


    glLineWidth(1);
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(0+x_hearth,0+y_hearth);
        glVertex2f(-0.033+x_hearth,0.033+y_hearth);
        glVertex2f(-0.022+x_hearth, 0.06+y_hearth);
        glVertex2f(-0.011+x_hearth, 0.06+y_hearth);
        glVertex2f(0+x_hearth, 0.05+y_hearth);
        glVertex2f(0.011+x_hearth, 0.06+y_hearth);
        glVertex2f(0.022+x_hearth, 0.06+y_hearth);
		glVertex2f(0.033+x_hearth, 0.033+y_hearth);

    glEnd();

    return;
}


void draw_spike(float x,float y){

    glLineWidth(1);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        glVertex2f(x,y);
        glVertex2f(x-0.01,y);
        glVertex2f(x-0.01,y-0.005);
        glVertex2f(x,y);


    glEnd();
	return;
}	

void highlight_current(){

    switch(action_highlited){
        case 0:

            glColor3f(1,0.5,0);
            glLineWidth(5);

            glBegin(GL_LINE_LOOP);
                glVertex2f(-0.9,-0.9);
	            glVertex2f(-0.55,-0.9);
	            glVertex2f(-0.55,-0.7);
	            glVertex2f(-0.9,-0.7);
             glEnd();

             draw_text("Attack\0",-0.8,-0.8,1,0,0);
             break;

         case 1:

            glColor3f(1,0.5,0);
            glLineWidth(5);

            glBegin(GL_LINE_LOOP);
                glVertex2f(-0.4,-0.9);
	            glVertex2f(-0.05,-0.9);
	            glVertex2f(-0.05,-0.7);
	            glVertex2f(-0.4,-0.7);
             glEnd();

             draw_text("Talk\0",-0.3,-0.8,1,0,0);
             break;

         case 2:

            glColor3f(1,0.5,0);
            glLineWidth(5);

            glBegin(GL_LINE_LOOP);
                glVertex2f(0.1,-0.9);
	            glVertex2f(0.45,-0.9);
	            glVertex2f(0.45,-0.7);
	            glVertex2f(0.1,-0.7);
             glEnd();

             draw_text("Item\0",0.2,-0.8,1,0,0);
             break;

        case 3:

            glColor3f(1,0.5,0);
            glLineWidth(5);

            glBegin(GL_LINE_LOOP);
                glVertex2f(0.6,-0.9);
	            glVertex2f(0.95,-0.9);
	            glVertex2f(0.95,-0.7);
	            glVertex2f(0.6,-0.7);
             glEnd();

             draw_text("Mercy\0",0.7,-0.8,1,0,0);
             break;
    }

}

void draw_menu(){

    switch (action_selected){

        case 0:
        in_menu_menu=0;
        break;

        case 1:
        strcpy(wtp,"You Talk to a Dummy..... Doesnt seem much of a conversation\0");
        draw_conversation(); //TODO TMP
        action_selected=0;
        glutKeyboardFunc(on_keyboard_to_combat);
        selecting_talk=1;
        break;

        case 2:
        draw_inventory();
        glutKeyboardFunc(on_keyboard_inventory);
        break;

        case 3:
        glutKeyboardFunc(on_keyboard_mercy);
        mercy=1;
        
    }

}

void draw_mercy(){

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
        glVertex2f(1, -0.6);
        glVertex2f(-1, -0.6);
    glEnd();

    glColor3f(1, 1, 1);
	glLineWidth(12.7);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.4,-0.6);
        glVertex2f(0.4,-0.6);
        glVertex2f(0.4, 0.2);
        glVertex2f(-0.4, 0.2);
    glEnd();

    if (mercy_action_highlited==0)
        glColor3f(1, 0.5, 0);
    else glColor3f(1, 1, 1);

    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
	        glVertex2f(-0.5,-0.9);
	        glVertex2f(-0.1,-0.9);
	        glVertex2f(-0.1,-0.7);
	        glVertex2f(-0.5,-0.7);
	glEnd();

    if (mercy_action_highlited==1)
        glColor3f(1, 0.5, 0);
    else glColor3f(1, 1, 1);

    glBegin(GL_LINE_LOOP);
	        glVertex2f(0.5,-0.9);
	        glVertex2f(0.1,-0.9);
	        glVertex2f(0.1,-0.7);
	        glVertex2f(0.5,-0.7);
	glEnd();

    if (mercy_action_highlited==0)
        draw_text("Spare\n",-0.4,-0.8,1,0.5,0);
    else draw_text("Spare\n",-0.4,-0.8,1,0.5,0);

    if (mercy_action_highlited==1)
        draw_text("Run\n",0.2,-0.8,1,0.5,0);
    else draw_text("Run\n",0.2,-0.8,1,1,1);
}

void draw_conversation(){

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
        glVertex2f(1, -0.6);
        glVertex2f(-1, -0.6);
    glEnd();

    glLineWidth(10);
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
        glVertex2f(1, -0.6);
        glVertex2f(-1, -0.6);
    glEnd();

    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.993,-0.993);
        glVertex2f(0.993,-0.993);
        glVertex2f(0.993, -0.6);
        glVertex2f(-0.993, -0.6);
    glEnd();


    //strcpy(wtp,s);
    //glutKeyboardFunc(on_keyboard_to_walking);
    //glutTimerFunc(100,on_timer_text,TIMER_TEXT);

    draw_text(wtp,-0.9,-0.7,1,1,1);

}

void draw_win(){

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
        glVertex2f(1, -0.6);
        glVertex2f(-1, -0.6);
    glEnd();

    glLineWidth(10);
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
        glVertex2f(1, -0.6);
        glVertex2f(-1, -0.6);
    glEnd();

    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.993,-0.993);
        glVertex2f(0.993,-0.993);
        glVertex2f(0.993, -0.6);
        glVertex2f(-0.993, -0.6);
    glEnd();


    draw_text("Congratulations!\0",-0.8,-0.5,1,1,1);
    draw_text("You Won 15g and 20XP\0",-0.9,-0.5,1,1,1);
}

void draw_escape(){

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
        glVertex2f(1, -0.6);
        glVertex2f(-1, -0.6);
    glEnd();

    glLineWidth(10);
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
        glVertex2f(1, -0.6);
        glVertex2f(-1, -0.6);
    glEnd();

    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.993,-0.993);
        glVertex2f(0.993,-0.993);
        glVertex2f(0.993, -0.6);
        glVertex2f(-0.993, -0.6);
    glEnd();


    draw_text("You Lose!\0",-0.8,-0.5,1,1,1);
    draw_text("You Earned 0g and 0XP\0",-0.9,-0.5,1,1,1);
}

void draw_inventory(){

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
        glVertex2f(1, -0.6);
        glVertex2f(-1, -0.6);
    glEnd();

    glLineWidth(10);
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
        glVertex2f(1, -0.6);
        glVertex2f(-1, -0.6);
    glEnd();

    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.993,-0.993);
        glVertex2f(0.993,-0.993);
        glVertex2f(0.993, -0.6);
        glVertex2f(-0.993, -0.6);
    glEnd();

    CVOR* tekuci_cvor=inv;
	
	for(int i=0;tekuci_cvor!=NULL;i++){
        char* tmp = malloc(30*sizeof(char));
        if (tmp==NULL)
            continue;
        strcpy(tmp,tekuci_cvor->Items->name);
        if (tekuci_cvor->Items->consumable==1){
		    draw_text("* ",-0.9+i*0.5,-0.7-i/4*0.3,1,1,1);
            draw_text(tmp,-0.85+i*0.5,-0.7-i/4*0.3,1,1,1);
            if (i==item_selected){
                draw_text("* ",-0.9+i*0.5,-0.7-i/4*0.3,1,0.5,0);
                draw_text(tmp,-0.85+i*0.5,-0.7-i/4*0.3,1,0.5,0);
            }
        }
		tekuci_cvor=tekuci_cvor->sledeci;
        free (tmp);
	}

}


#endif
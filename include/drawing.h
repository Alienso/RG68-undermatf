#ifndef _DRAWING_
#define _DRAWING_

#include "header.h"

static void on_display_encounter(void){

    draw_base();
    draw_hearth();
    highlight_current();
    if (in_menu_menu)
        draw_menu();
    if (mercy)
        draw_mercy();

    if (gradient!=-1){
        glEnable(GL_BLEND);
        glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
        glColor4f(0,0,0,fabs(fabs(gradient)-1));
        glBegin(GL_QUADS);
            glVertex2f(-1, -1);
            glVertex2f(1, -1);
            glVertex2f(1, 1);
            glVertex2f(-1, 1);
        glEnd();

        glDisable(GL_BLEND);
    }

    glutPostRedisplay();
    glutSwapBuffers();
}

static void on_display_walking(void){

    glClear(GL_COLOR_BUFFER_BIT);

    //Crta se pozadina
    glBindTexture(GL_TEXTURE_2D, names[current_map]);

    int miplevel = 0;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_WIDTH, &current_texture_w);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_HEIGHT, &current_texture_h);

    glBegin(GL_QUADS);

        glTexCoord2f((float)(absolute_position_x-FOV)/current_texture_w, (float)(absolute_position_y-FOV)/current_texture_h);
        glVertex2f(-1, -1);

        glTexCoord2f((float)(absolute_position_x+FOV)/current_texture_w, (float)(absolute_position_y-FOV)/current_texture_h);
        glVertex2f(1, -1);

        glTexCoord2f((float)(absolute_position_x+FOV)/current_texture_w, (float)(absolute_position_y+FOV)/current_texture_h);
        glVertex2f(1, 1);

        glTexCoord2f((float)(absolute_position_x-FOV)/current_texture_w, (float)(absolute_position_y+FOV)/current_texture_h);
        glVertex2f(-1, 1);
    glEnd();

    //crta se karakter
    glBindTexture(GL_TEXTURE_2D, names[player_side]);
    glEnable(GL_BLEND);
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glBegin(GL_QUADS);

        glTexCoord2f(0, 0);
        glVertex2f(-0.1, -0.1);

        glTexCoord2f(1, 0);
        glVertex2f(0.1, -0.1);

        glTexCoord2f(1, 1);
        glVertex2f(0.1, 0.1);

        glTexCoord2f(0, 1);
        glVertex2f(-0.1, 0.1);
    glEnd();

    //glDisable(GL_BLEND);

    glBindTexture(GL_TEXTURE_2D, 0);

    if (gradient!=-1){
        //crta se zatamljenje
        glColor4f(0,0,0,fabs(fabs(gradient)-1));
        glBegin(GL_QUADS);
            glVertex2f(-1, -1);
            glVertex2f(1, -1);
            glVertex2f(1, 1);
            glVertex2f(-1, 1);
        glEnd();
    }
    
    glDisable(GL_BLEND);


    if (exclamation_mark)
        draw_exclamation_mark();

    glColor3f(1,1,1);
    if (conversation_happening)
        draw_conversation();
    //sprintf(wtp,"%d %d %d",absolute_position_x,absolute_position_y,exclamation_mark);
    //draw_text(wtp,-0.8,-0.8,1,1,1);

    if (encounter_start_animation)
        draw_hearth();

    glutPostRedisplay();
    glutSwapBuffers();
    return;
}

static void on_display_combat(void){

    draw_base();
    draw_hearth();

    glPointSize(20);
    float r = (rand()%100)/100.0;
    float g = (rand()%100)/100.0;
    float b = (rand()%100)/100.0;
    glColor3f(r,g,b);
    glBegin(GL_POINTS);
        glVertex2f(0.9,0.9);
    glEnd();

    current_time=time(NULL);
    if (current_time-start_time==1){
        fps=fps_counter;
        fps_counter=0;
        start_time=current_time;
    }
    fps_counter++;
    sprintf(wtp,"%f",gradient);
    draw_text(wtp,0.8,0.8,1,1,1);

    (*att_ptrs[curr_enemy->attacks[random_attack]])();
    
    glutPostRedisplay();
    glutSwapBuffers();
}

static void on_display_chemist(void){

 glClear(GL_COLOR_BUFFER_BIT);

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


    //crta se HUD
    char goldstr[8];
    sprintf(goldstr,"%d",gold);
    strcpy(wtp,"Gold:\0");
    draw_text(wtp,-0.9,-0.5,1,1,1);
    strcpy(wtp,goldstr);
    draw_text(wtp,-0.7,-0.5,1,1,1);

    strcpy(wtp,"Price: \0");
    draw_text(wtp,0.6,-0.5,1,1,1);
    sprintf(goldstr,"%d",Chemist_items[shop_item_selected]->price);
    draw_text(goldstr,0.8,-0.5,1,1,1);

    strcpy(wtp,Chemist_items[shop_item_selected]->description);
    draw_text(wtp,-0.1,-0.5,1,1,1);

    //Crtaju se itemi
    for (int i=0;i<items_in_shop;i++){
        strcpy(wtp,Chemist_items[i]->name);
        draw_text("* \0",-0.9+i*0.58-i/2,-0.7-i/2*0.1,1,1,1);
        draw_text(wtp,-0.85+i*0.58-i/2,-0.7-i/2*0.1,1,1,1);
            if (i==shop_item_selected){
                draw_text("* \0",-0.9+i*0.58-i/2,-0.7-i/2*0.1,1,0.5,0);
                draw_text(wtp,-0.85+i*0.58-i/2,-0.7-i/2*0.1,1,0.5,0);
            }
    }

    glutPostRedisplay();
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
            if (enemy_hp>0)
	            glVertex2f((float)(1.0*enemy_hp/curr_enemy->hp)-0.6,0.825);
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
        draw_text("Spare\0",-0.4,-0.8,1,0.5,0);
    else draw_text("Spare\0",-0.4,-0.8,1,0.5,0);

    if (mercy_action_highlited==1)
        draw_text("Run\0",0.2,-0.8,1,0.5,0);
    else draw_text("Run\0",0.2,-0.8,1,1,1);
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

    draw_text(wtp,-0.9,-0.8,1,1,1);

}

void draw_win(){

    glClear(GL_COLOR_BUFFER_BIT);
    draw_base();
    draw_hearth();
    
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


    draw_text("Congratulations!\0",-0.25,-0.8,1,1,1);
    draw_text("You Won 15g and 20XP\0",-0.45,-0.9,1,1,1);

    glutSwapBuffers();
}

void draw_escape(){

    glClear(GL_COLOR_BUFFER_BIT);
    draw_base();
    draw_hearth();

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


    draw_text("You Lose\0",-0.25,-0.8,1,1,1);
    draw_text("You Won 0g and 0XP\0",-0.45,-0.9,1,1,1);

    glutSwapBuffers();
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
		    draw_text("* \0",-0.9+i*0.5,-0.7-i/4*0.3,1,1,1);
            draw_text(tmp,-0.85+i*0.5,-0.7-i/4*0.3,1,1,1);
            if (i==item_selected){
                draw_text("* \0",-0.9+i*0.5,-0.7-i/4*0.3,1,0.5,0);
                draw_text(tmp,-0.85+i*0.5,-0.7-i/4*0.3,1,0.5,0);
            }
        }
        else i--;
		tekuci_cvor=tekuci_cvor->sledeci;
        free (tmp);
	}

}

void draw_exclamation_mark(){

    glColor3f(1,1,0);
        
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex2f(0,0.2);
        glVertex2f(0,0.275);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
        glVertex2f(0,0.15);
    glEnd();


    return;
}

#endif
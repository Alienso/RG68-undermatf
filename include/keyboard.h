#ifndef _KEYBOARD_
#define _KEYBOARD_

#include <GL/glut.h>
#include "header.h"

static void on_keyboard_combat(unsigned char key, int x, int y){
	
    switch (key) {
    case 27:
        exit(0);
        break;

    case 'w':
		if (y_hearth>=0.11)
			break;
       	y_hearth+=0.01;
        break;

    case 's':
		if (y_hearth<=-0.575)
			break;
		y_hearth-=0.01;
        break;

    case 'a':
		if (x_hearth<=-0.34)
			break;
		x_hearth-=0.01;
        break;

    case 'd':
		if (x_hearth>=0.34)
			break;
		x_hearth+=0.01;
        break;
    }

   glutPostRedisplay();
}

static void on_keyboard_encounter(unsigned char key, int x, int y){

    switch (key) {
    case 'a':   
		action_highlited-=1;
        if (action_highlited==-1)
            action_highlited=3;
        break;

    case 'd':
        action_highlited+=1;
        action_highlited=action_highlited%4;
        break;
    

    case ' ':
        action_selected=action_highlited;
        in_menu_menu=1;

        if (action_selected==0){
            enemy_hp-=my_damage;
            if (enemy_hp<=0){
                glutDisplayFunc(draw_win);
                glutKeyboardFunc(on_keyboard_to_walking);
            }
            else if (enemy_hp>0) {
                switch_to_combat();
            }
        }
        break;
    }

   glutPostRedisplay();


}

static void on_keyboard_mercy(unsigned char key, int x, int y){

    switch (key) {
    case 'a':   
		mercy_action_highlited=0;
        break;

    case 'd':
        mercy_action_highlited=1;
        break;

    case ' ':
        if (mercy_action_highlited==0 && can_spare){
            glutKeyboardFunc(on_keyboard_to_walking);
            glutDisplayFunc(draw_win);
        }
        if (mercy_action_highlited==0 && !can_spare){
            switch_to_combat();

        }
        if (mercy_action_highlited==1){
            if (rand()%2==0){
                glutKeyboardFunc(on_keyboard_to_walking);
                glutDisplayFunc(draw_escape);
            }
            else {
                switch_to_combat();
            }
        }
        in_menu_menu=0;
        mercy=0;
        break;
    
    case 27:
        in_menu_menu=0;
        mercy=0;
        glutKeyboardFunc(on_keyboard_encounter);
        break;
    }

   glutPostRedisplay();


}

static void on_keyboard_to_encounter(unsigned char key, int x, int y){
    if (key==' '){
        in_menu_menu=0;
        glutKeyboardFunc(on_keyboard_encounter);
    }
    glutPostRedisplay();
}

static void on_keyboard_to_combat(unsigned char key, int x, int y){
    if (key==' '){
        in_menu_menu=0;
        glutDisplayFunc(on_display_combat);
        glutTimerFunc(5000,on_timer_combat,TIMER_COMBAT);
        glutKeyboardFunc(on_keyboard_combat);
    }
    glutPostRedisplay();
}

static void on_keyboard_to_walking(unsigned char key, int x, int y){
    if (key==' '){
        glutKeyboardFunc(on_keyboard_walking);
    }
    glutPostRedisplay();
}

static void on_keyboard_inventory(unsigned char key, int x, int y){
    
    switch (key){

        case ' ':
            in_menu_menu=0;
            remove_from_inv(item_selected,&inv);
                switch_to_combat();
            break;

        case 'a':
            if (item_selected==0){
                item_selected=items_in_inv-1;
                break;
            }
            item_selected-=1;
            break;
        
        case 'd':
            item_selected+=1;
            item_selected=item_selected%items_in_inv;
            break;
            
        case 27:
            in_menu_menu=0;
            glutKeyboardFunc(on_keyboard_encounter);
            break;
    }
    glutPostRedisplay();
}

static void on_keyboard_none(unsigned char key, int x, int y){}

static void on_keyboard_walking(unsigned char key, int x, int y){}

static void on_keyboard_talk(unsigned char key, int x, int y){}
#endif
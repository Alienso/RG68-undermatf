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
            if (enemy_hp<=0);
            draw_win();
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
            win_screen=1;
            glutKeyboardFunc(on_keyboard_walking);
            glutDisplayFunc(on_display_walking);
        }
        if (mercy_action_highlited==0 && !can_spare){
            glutKeyboardFunc(on_keyboard_encounter);
        }
        if (mercy_action_highlited==1){
            if (rand()%2==0){
            escape_screen=1;
            glutKeyboardFunc(on_keyboard_next);
            glutDisplayFunc(on_display_encounter);
            }
            else {
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

static void on_keyboard_next(unsigned char key, int x, int y){
    if (key==' '){
        in_menu_menu=0;
        glutKeyboardFunc(on_keyboard_encounter);
    }
    glutPostRedisplay();
}

static void on_keyboard_inventory(unsigned char key, int x, int y){
    
    switch (key){

        case ' ':
            in_menu_menu=0;
            remove_from_inv(item_selected,&inv);
            glutKeyboardFunc(on_keyboard_encounter);
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
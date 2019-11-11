#ifndef _TIMERS_
#define _TIMERS_

#include "header.h"

int text_head=0;
float text_x=-0.9;
float text_y=-0.7;
int chars_written=0;
int rows_written=0;
char* s;


static void on_timer_next(int value){
    
    if (value != TIMER_NEXT)
        return;
    glutKeyboardFunc(on_keyboard_encounter);
}


/*static void on_timer_text(int value){

    if (value != TIMER_TEXT)
        return;

    if (wtp[text_head]=='\0'){
        rows_written=0;
        chars_written=0;
        text_head=0;
        glutKeyboardFunc(on_keyboard_next);
        return;
    }
    
    //s=(char*)malloc(2*sizeof(char));
    //s[0]=wtp[text_head];
   // s[1]='\0';
    
    chars_written+=1;
    text_head+=1;
    if (chars_written==20){
        rows_written+=1;
        chars_written=0;
    }

    glutTimerFunc(20,on_timer_text,TIMER_TEXT);

}*/

static void on_timer_combat(int value){
    
    if (value != TIMER_COMBAT)
        return;

    glutDisplayFunc(on_display_encounter);
    glutKeyboardFunc(on_keyboard_encounter);
}




#endif
#ifndef _TIMERS_
#define _TIMERS_

#include "header.h"

static void on_timer_next(int value){
    
    if (value != TIMER_NEXT)
        return;
    glutKeyboardFunc(on_keyboard_encounter);
}


static void on_timer_combat(int value){
    
    if (value != TIMER_COMBAT)
        return;

    t=0;
    enemy_turn=0;
    vec.x=0;
    vec.y=0;
    x_hearth=0;
    y_hearth=0;
    glutDisplayFunc(on_display_encounter);
    glutKeyboardFunc(on_keyboard_encounter);
}

static void on_timer_move_combat(int value){

    if (value != TIMER_MOVE_COMBAT)
        return;

	if (vec.y==1 && y_hearth>=0.11){
        x_hearth-=vec.x*0.01;
        y_hearth-=vec.y*0.01;
    }

	if (vec.y==-1 && y_hearth<=-0.575){
        x_hearth-=vec.x*0.01;
        y_hearth-=vec.y*0.01;
    }

	if (vec.x==-1 && x_hearth<=-0.34){
        x_hearth-=vec.x*0.01;
        y_hearth-=vec.y*0.01;
    }

	if (vec.x==1 && x_hearth>=0.34){
        x_hearth-=vec.x*0.01;
        y_hearth-=vec.y*0.01;
    }

    x_hearth+=vec.x*0.01;
    y_hearth+=vec.y*0.01;
    
    t+=20/5000.0;
    if (enemy_turn)
        glutTimerFunc(20,on_timer_move_combat,TIMER_MOVE_COMBAT);

    return;
}

static void on_timer_invulnerable(int value){

    if (value!=TIMER_INVULNERABLE)
        return;

    invulnerable=0;
    return;
}



#endif
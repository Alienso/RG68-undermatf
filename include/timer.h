#ifndef _TIMERS_
#define _TIMERS_

#include "header.h"

int pom=0;

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

    if (value != TIMER_MOVE_COMBAT){
        return;
    }

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

static void on_timer_move_walking(int value){

    if (value != TIMER_MOVE_WALKING){
        return;
    }

	if (walking_vec.y==1 && absolute_position_y>=current_texture_h){
        absolute_position_x-=walking_vec.x;
        absolute_position_y-=walking_vec.y;
    }

	if (walking_vec.y==-1 && absolute_position_y<=1){
        absolute_position_x-=walking_vec.x;
        absolute_position_y-=walking_vec.y;
    }

	if (walking_vec.x==-1 && absolute_position_x<=1){
        absolute_position_x-=walking_vec.x;
        absolute_position_y-=walking_vec.y;
    }

	if (walking_vec.x==1 && absolute_position_x>=current_texture_w){
        absolute_position_x-=walking_vec.x;
        absolute_position_y-=walking_vec.y;
    }

    absolute_position_x+=walking_vec.x;
    absolute_position_y+=walking_vec.y;
    
    if (walking)
        glutTimerFunc(20,on_timer_move_walking,TIMER_MOVE_WALKING);

    return;
}

static void on_timer_invulnerable(int value){

    if (value!=TIMER_INVULNERABLE)
        return;

    invulnerable=0;
    return;
}

static void on_timer_animation_move(int value){

    if (value!=TIMER_ANIMATION_MOVE)
        return;

    if (walking_vec.x==0 && walking_vec.y==0){
        really_walking=0;
        animation_phase=0;
    }
        
    if (!really_walking)
        return;

    animation_phase=!animation_phase;

    if (walking && (walking_vec.x!=0 || walking_vec.y!=0))
        glutTimerFunc(250,on_timer_animation_move,TIMER_ANIMATION_MOVE);

}



#endif
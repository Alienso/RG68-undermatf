#ifndef _TIMERS_
#define _TIMERS_

#include "header.h"
#include "Items_Enemies.h"

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
    y_hearth=-0.2;
    glutDisplayFunc(on_display_encounter);
    glutKeyboardFunc(on_keyboard_encounter);
}

static void on_timer_move_combat(int value){ //allows movement

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

static void on_timer_move_walking(int value){ //allows movement

    if (value != TIMER_MOVE_WALKING){
        return;
    }

    #ifndef AUDIO
    if (current_map!=0){
        alGetSourcei(source[0], AL_SOURCE_STATE, &state);
        if (state != AL_PLAYING)
            alSourcePlay(source[0]);
    }
    #endif

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

    if(check_events())
        return;
    
    absolute_position_x+=walking_vec.x;
    absolute_position_y+=walking_vec.y;
    if (!can_walk()){
        absolute_position_x-=walking_vec.x;
        absolute_position_y-=walking_vec.y;
    }
    
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

    int x=rand()%100000;
    if (x/1000.0<=0.6){
        gradient=-1;
        switch (rand()%6)
        {
        case 0:
        case 1:
        case 2:
            curr_enemy=Programer;
            break;
        case 3:
        case 4:
            curr_enemy=Menadzer;
            break;
        case 5:
            curr_enemy=OperacioniMenadzer;
            break;
        }
        glutKeyboardFunc(NULL);
        walking_vec.x=0;
        walking_vec.y=0;
        x_hearth=0;
        y_hearth=0;
        encounter_start_animation=1;
        glutTimerFunc(1,on_timer_gradient_to_encounter,TIMER_GRADIENT_TO_ENCOUNTER);
        return;
    }

    if (walking && (walking_vec.x!=0 || walking_vec.y!=0))
        glutTimerFunc(250,on_timer_animation_move,TIMER_ANIMATION_MOVE);

}

static void on_timer_no_choice(int value){

    if (value!=TIMER_NO_CHOICE)
        return;

    talk_phase++;
    glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);

    return;
}

static void on_timer_gradient_to_encounter(int value){

    if(value!=TIMER_GRADIENT_TO_ENCOUNTER)
        return;

    gradient+=20.0/1000;
    if (gradient<0)
        y_hearth-=0.2/50;

    if (gradient>=0 && gradient<=0.04)
        switch_to_encounter();

    if (gradient>=1)
        return;
    
    glutPostRedisplay();
    glutTimerFunc(20,on_timer_gradient_to_encounter,TIMER_GRADIENT_TO_ENCOUNTER);
    return; 
}

static void on_timer_gradient_to_walking(int value){

    if(value!=TIMER_GRADIENT_TO_WALKING)
        return;

    gradient+=40.0/1000;

    if (gradient>=0 && gradient<=0.04)
        switch_to_walking();

    if (gradient>=1)
        return;
    
    glutPostRedisplay();
    glutTimerFunc(20,on_timer_gradient_to_walking,TIMER_GRADIENT_TO_WALKING);
    return; 
}

static void on_timer_mini_game(int value){ //boss fight attacks logic

    if(value!=TIMER_MINI_GAME)
        return;

    int i,j;
    if (mini_game_counter>=40){
        mini_game_counter=0;
        if (mini_game_speed>=7)
            mini_game_speed=7;
        switch (rand()%4){
        case 0:
            boss_field[50][0]=1;
            break;
        case 1:
            boss_field[50][99]=1;
            break;
        case 2:
            boss_field[0][50]=1;
            break;
        case 3:
            boss_field[99][50]=1;
            break;
        }
    }

    for (i=0;i<50;i++){ //levo
        if (boss_field[i][50]==1 && i==43){
            if (shield_side!=2)
                hp-=curr_enemy->att;
            boss_field[43][50]=0;
        }
        if (boss_field[i][50]==1){
            boss_field[i][50]=0;
            boss_field[i+1][50]=1;
            i++;
        }
    }

    for (i=99;i>50;i--){ //desno
        if (boss_field[i][50]==1 && i==57){
            if (shield_side!=3)
                hp-=curr_enemy->att;
            boss_field[57][50]=0;
        }
        if (boss_field[i][50]==1){
            boss_field[i][50]=0;
            boss_field[i-1][50]=1;
            i--;
        }
    }

    for (i=0;i<50;i++){ //gore
        if (boss_field[50][i]==1 && i==45){
            if (shield_side!=1)
                hp-=curr_enemy->att;
            boss_field[50][45]=0;
        }
        if (boss_field[50][i]==1){
            boss_field[50][i]=0;
            boss_field[50][i+1]=1;
            i++;
        }
    }

    for (i=99;i>50;i--){ //dole
        if (boss_field[50][i]==1 && i==58){
            if (shield_side!=0)
                hp-=curr_enemy->att;
            boss_field[50][58]=0;
        }
        if (boss_field[50][i]==1){
            boss_field[50][i]=0;
            boss_field[50][i-1]=1;
            i--;
        }
    }

    mini_game_counter++;

    if (enemy_turn)
        glutTimerFunc(20-mini_game_speed,on_timer_mini_game,TIMER_MINI_GAME);


}


#endif
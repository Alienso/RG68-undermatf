#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "./include/header.h"
#include "./include/events.h"
#include "./include/text.h"
#include "./include/drawing.h"
#include "./include/bullet_hell.h"
#include "./include/keyboard.h"
#include "./include/timer.h"
#include "./include/inventory.h"
#include "./include/Items_Enemies.h"
#include "./include/image.h"
#include "./include/inits.h"
#include "./include/walking_collisions.h"


int main(int argc, char **argv){

    #ifndef AUDIO
    alutInit(0, NULL);
    #endif
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glEnable(GL_TEXTURE_2D);

    glutInitWindowSize(700, 700);
    glutInitWindowPosition(300, 0);
    glutCreateWindow(argv[0]);
    glutReshapeFunc(resize);

    glutKeyboardFunc(on_keyboard_menu);
    glutDisplayFunc(on_display_menu);

    glClearColor(0, 0, 0, 0);

    init();
    glutMainLoop();

    return 0;
}

void switch_to_combat(){
    enemy_turn=1;
    maxt=0;
    glutDisplayFunc(on_display_combat);

    x_hearth=0;
    y_hearth=-0.2;
    if (curr_enemy==Boss){
        mini_game_speed++;
        mini_game_counter=40;
        clear_boss_field();
        glutKeyboardFunc(on_keyboard_boss);
        glutTimerFunc(10000,on_timer_combat,TIMER_COMBAT);
        glutTimerFunc(20,on_timer_move_combat,TIMER_MOVE_COMBAT);
        glutKeyboardUpFunc(on_keyboard_none);
        glutTimerFunc(1,on_timer_mini_game,TIMER_MINI_GAME);
    }
    else {
    glutKeyboardFunc(on_keyboard_combat);
    glutTimerFunc(5000,on_timer_combat,TIMER_COMBAT);
    glutTimerFunc(20,on_timer_move_combat,TIMER_MOVE_COMBAT);
    glutKeyboardUpFunc(on_keyboard_up_combat);
    }

    start_time=time(NULL);

    vec.x=0;
    vec.y=0;
}

void switch_to_encounter(){

    #ifndef AUDIO
    alSourcePause(source[0]);
    if (curr_enemy==Boss)
        alSourcePlay(source[1]);
    else
        alSourcePlay(source[2]);
    #endif

    x_hearth=0;
    y_hearth=-0.2;
    attack_counter=0;
    enemy_hp=curr_enemy->hp;
    walking=0;
    really_walking=0;
    encounter_start_animation=0;
    glutKeyboardFunc(on_keyboard_encounter);
    glutDisplayFunc(on_display_encounter);

    return;
}

void switch_to_walking(){

    #ifndef AUDIO
    alSourceStop(source[1]);
    alSourceStop(source[2]);
    if (current_map!=0)
        alSourcePlay(source[0]);
    #endif
    walking=1;
    last_key_pressed=0;
    glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
    glutKeyboardFunc(on_keyboard_walking);
    glutKeyboardUpFunc(on_keyboard_up_walking);
    glutDisplayFunc(on_display_walking);
    return;
}

void check_collision(float x,float y){ //collisions in combat

    if (!invulnerable && (x_hearth>x-0.02 && x_hearth<x+0.02) && (y_hearth>y-0.02 && y_hearth<y+0.02)){
        hp-=curr_enemy->att;
        invulnerable=1;
        glutTimerFunc(1250,on_timer_invulnerable,TIMER_INVULNERABLE);
    }
    if (hp<0)
        hp=0;

    return;
}

void resize(int width, int height) {
    glutReshapeWindow( 700, 700);
}

void clear_boss_field(){ //clear matrix
    int i;
    for (i=0;i<50;i++)
        boss_field[i][50]=0;
    for (i=99;i>50;i--)
        boss_field[i][50]=0;
    for (i=0;i<50;i++)
        boss_field[50][i]=0;
    for (i=99;i>50;i--)
        boss_field[50][i]=0;

    return;
}
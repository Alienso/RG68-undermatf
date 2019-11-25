#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "./include/header.h"
#include "./include/text.h"
#include "./include/drawing.h"
#include "./include/bullet_hell.h"
#include "./include/keyboard.h"
#include "./include/timer.h"
#include "./include/inventory.h"
#include "./include/Items_Enemies.h"

void init(){

    wtp=(char*)calloc(200,sizeof(char));
    if (wtp==NULL){
        fprintf(stderr,"WTP");
        exit(1);
    }

    srand(time(NULL));
    init_Items_Enemies();
    init_inv();
    
    weapon_equiped=Olovka;
    curr_enemy=Programer;

    int hp=max_hp;
    int my_damage = weapon_equiped->att;
    int enemy_hp=curr_enemy->hp;

    vec.x=0;
    vec.y=0;
}

int main(int argc, char **argv){

    init();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(700, 700);
    glutInitWindowPosition(300, 0);
    glutCreateWindow(argv[0]);

    glutKeyboardFunc(on_keyboard_encounter);
    glutDisplayFunc(on_display_encounter);

    glClearColor(0, 0, 0, 0);
    /*glPointSize(6);*/ 

    glutMainLoop();

    return 0;
}

void switch_to_combat(){
    enemy_turn=1;
    glutDisplayFunc(on_display_combat);
    glutKeyboardFunc(on_keyboard_combat);
    glutTimerFunc(5000,on_timer_combat,TIMER_COMBAT);
    glutTimerFunc(20,on_timer_move_combat,TIMER_MOVE_COMBAT);
    glutKeyboardUpFunc(on_keyboard_up_combat);

    start_time=time(NULL);

    vec.x=0;
    vec.y=0;
}

void check_collision(float x,float y){

    if (!invulnerable && (x_hearth>x-0.02 && x_hearth<x+0.02) && (y_hearth>y-0.02 && y_hearth<y+0.02)){
        hp-=5;
        invulnerable=1;
        glutTimerFunc(1250,on_timer_invulnerable,TIMER_INVULNERABLE);
    }
    return;
}
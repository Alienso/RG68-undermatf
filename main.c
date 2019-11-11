#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "./include/header.h"
#include "./include/text.h"
#include "./include/drawing.h"
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

    init_inv();
    init_Items_Enemies();
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
    glutDisplayFunc(on_display_combat);
    glutKeyboardFunc(on_keyboard_combat);
    glutTimerFunc(5000,on_timer_combat,TIMER_COMBAT);
}
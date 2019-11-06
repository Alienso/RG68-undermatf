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


/*void bullet_hell(){
		
	float x=0,y=0;	

	switch (num) {

		case 0:
			x=1-t/2.5;
			y=-0.6;
			break;
	}




	draw_spike(x,y);
}*/
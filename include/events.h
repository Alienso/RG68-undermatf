#ifndef _EVENTS_
#define _EVENTS_

#include "header.h"

void add_event(int x1,int x2,int y1,int y2){

    int x=events[current_map].size;
    events[current_map].quads[x].x1=x1;
    events[current_map].quads[x].x2=x2;
    events[current_map].quads[x].y1=y1;
    events[current_map].quads[x].y2=y2;

    events[current_map].size++;
    return;
}

void remove_event(int j){ //Brise j-ti dogadjaj iz niza events

    events[current_map].quads[j].x1=-1;
    events[current_map].quads[j].x2=-1;
    events[current_map].quads[j].y1=-1;
    events[current_map].quads[j].y2=-1;
    return;
}

void end_talk(int i){

    remove_event(i);
    glutKeyboardFunc(on_keyboard_walking);
    glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
    conversation_happening=0;
    talk_phase=0;
    return;
}

int check_events(){

    for (int i=0;i<events[current_map].size;i++)
        if (check_quad(events[current_map].quads[i].x1,events[current_map].quads[i].x2,events[current_map].quads[i].y1,events[current_map].quads[i].y2)){
            events_ptr[i]();
            return 1;
        }
    return 0;
}

void switch_to_entrance(){
    current_map=0;
    absolute_position_x=50;
    absolute_position_y=75;
    glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
}

void switch_to_hall(){
    current_map=1;
    absolute_position_x=400;
    absolute_position_y=10;
    glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
    
}

void first_talk(){
    
    glutKeyboardFunc(on_keyboard_talk);
    conversation_happening=1;
    switch(talk_phase){

        case 0:
            strcpy(wtp,"Hello There\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 1:
            strcpy(wtp,"Hello\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 2:
            end_talk(1);

    }

    return;
}

#endif
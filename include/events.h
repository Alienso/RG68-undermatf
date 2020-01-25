#ifndef _EVENTS_
#define _EVENTS_

#include "header.h"
#include "Items_Enemies.h"

void add_event(int x1,int x2,int y1,int y2,int i){

    int x=events[current_map].size;
    events[current_map].quads[x].x1=x1;
    events[current_map].quads[x].x2=x2;
    events[current_map].quads[x].y1=y1;
    events[current_map].quads[x].y2=y2;
    events[current_map].no[x]=i;
    events[current_map].key[x]=0;


    events[current_map].size++;
    return;
}

void add_key_event(int x1,int x2,int y1,int y2,int i){ //event that needs keypress

    int x=events[current_map].size;
    events[current_map].quads[x].x1=x1;
    events[current_map].quads[x].x2=x2;
    events[current_map].quads[x].y1=y1;
    events[current_map].quads[x].y2=y2;
    events[current_map].no[x]=i;
    events[current_map].key[x]=1;

    events[current_map].size++;
    return;
}

void remove_event(int j){ //Brise j-ti dogadjaj iz niza events

    events[current_map].quads[j].x1=-1;
    events[current_map].quads[j].x2=-1;
    events[current_map].quads[j].y1=-1;
    events[current_map].quads[j].y2=-1;
    //events[current_map].no[j]=NULL;
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

int check_events(){ //checks if event happended

    exclamation_mark=0;
    
    for (int i=0;i<events[current_map].size;i++){
        if (events[current_map].key[i]==0)
            if (check_quad(events[current_map].quads[i].x1,events[current_map].quads[i].x2,events[current_map].quads[i].y1,events[current_map].quads[i].y2)){
                events_ptr[events[current_map].no[i]]();
                return 1;
            }
        if (events[current_map].key[i]==1 && last_key_pressed==' ' && check_quad(events[current_map].quads[i].x1,events[current_map].quads[i].x2,events[current_map].quads[i].y1,events[current_map].quads[i].y2)){
            events_ptr[events[current_map].no[i]]();
            return 1;
        }
        else if (events[current_map].key[i]==1 && check_quad(events[current_map].quads[i].x1,events[current_map].quads[i].x2,events[current_map].quads[i].y1,events[current_map].quads[i].y2))
            exclamation_mark=1;
    }
        return 0;
}

void switch_to_entrance(){
    current_map=0;
    absolute_position_x=76;
    absolute_position_y=90;
    glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
}

void switch_to_4(){
    current_map=2;
    if (absolute_position_x>500){
        absolute_position_x=726;
        absolute_position_y=120;
    }
    else {
        absolute_position_x=357;
        absolute_position_y=83;
        player_side=14;
    }
    glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
}

void switch_to_hall(){
    current_map=1;
    invisible=0;
    absolute_position_x=897;
    absolute_position_y=55;
    glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
    
}

void first_talk(){
    
    glutKeyboardFunc(on_keyboard_talk);
    conversation_happening=1;
    switch(talk_phase){

        case 0:
            strcpy(wtp,"Hey!!!\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 1:
            strcpy(wtp,"Its risky in there, Havent you heard\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 2:
            strcpy(wtp,"Fonovci have invaded our Fax\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 3:
            strcpy(wtp,"I see you are very determined to go in there\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 4:
            strcpy(wtp,"I would recommend you fight this dummy first\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 5:
            strcpy(wtp,"Yes       No\0");
            glutTimerFunc(300,on_timer_no_choice,TIMER_NO_CHOICE);
            break;
        case 6:
            strcpy(wtp,"Great Im glad that you agree!\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 7:
            curr_enemy=Dummy;
            talk_phase++;
            gradient=-1;
            glutTimerFunc(1,on_timer_gradient_to_encounter,TIMER_GRADIENT_TO_ENCOUNTER);
            break;
        case 8:
            strcpy(wtp,"Nice moves, good luck in there!\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 9:
            strcpy(wtp,"I was planing to do a story here, but the time was short");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 10:
            strcpy(wtp,"So what you got here is a demo\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 11:
            strcpy(wtp,"Explore the first floor,the 4th one isn't finished yet\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 12:
            strcpy(wtp,"You CAN climb up, but when you do, you'll be stuck there\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 13:
            strcpy(wtp,"Search for X-s on the floor, they will be like a.... trining dummies for difffrent enemies\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 14:
            add_key_event(60,73,52,58,4);
            end_talk(0);
        }

    return;
}

void tutorial_guy_talk(){   
    glutKeyboardFunc(on_keyboard_talk);
    conversation_happening=1;
    switch(talk_phase){
        case 0:
            strcpy(wtp,"Go on, nothing to see here\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 1:
            conversation_happening=0;
            talk_phase=0;
            last_key_pressed=0;
            glutKeyboardFunc(on_keyboard_walking);
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
    }
    return;
}

void open_chemist_shop(){

    glutKeyboardFunc(on_keyboard_talk);
    conversation_happening=1;
    switch(talk_phase){

        case 0:
            strcpy(wtp,"Pssst Kid!!!\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;

        case 1:
            strcpy(wtp,"I can brew you some potions if you have the coin\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 2:
            talk_phase++;
            items_in_shop=4;
            last_key_pressed=0;
            conversation_happening=0;
            glutDisplayFunc(on_display_chemist);
            glutKeyboardFunc(on_keyboard_chemist);
        case 3:
            conversation_happening=1;
            strcpy(wtp,"Glad doin' buisness with yaáa'\0");
            glutTimerFunc(1,on_timer_move_walking,TIMER_MOVE_WALKING);
            break;
        case 4:
            glutKeyboardFunc(on_keyboard_walking);
            glutKeyboardUpFunc(on_keyboard_up_walking);
            conversation_happening=0;
            talk_phase=0;
            last_key_pressed=0;
            break;

    }
    return;

}

void npc_test(){

    int x=absolute_position_x;
    if (x>=936 && x<=946)
        curr_enemy=Boss;
    if (x>=948 && x<=958)
        curr_enemy=OperacioniMenadzer;
    if (x>=960 && x<=969)
        curr_enemy=Menadzer;
    if (x>=973 && x<=983)
        curr_enemy=Programer;

    gradient=-1;
    glutTimerFunc(1,on_timer_gradient_to_encounter,TIMER_GRADIENT_TO_ENCOUNTER);
    return;
    
}

#endif
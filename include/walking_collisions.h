#ifndef _WALKING_COLLISIONS
#define _WALKING_COLLISIONS

#include "header.h"

int can_walk(){


    for (int i=0;i<walking_collision_array[current_map].size;i++)
        if(check_quad(walking_collision_array[current_map].quads[i].x1,walking_collision_array[current_map].quads[i].x2,walking_collision_array[current_map].quads[i].y1,walking_collision_array[current_map].quads[i].y2))
            return 0;
    return 1;
}

int check_quad(int x1,int x2,int y1,int y2){

    if (absolute_position_x>x1 && absolute_position_x<x2 && absolute_position_y>y1 && absolute_position_y<y2)
        return 1;

    return 0;
}

void add_to_wca(int x1,int x2,int y1,int y2){

    int n=walking_collision_array[current_map].size;
    walking_collision_array[current_map].quads[n].x1=x1;
    walking_collision_array[current_map].quads[n].x2=x2;
    walking_collision_array[current_map].quads[n].y1=y1;
    walking_collision_array[current_map].quads[n].y2=y2;

    walking_collision_array[current_map].size++;
    return;
}

#endif
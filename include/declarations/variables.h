#ifndef __VARIABLES_H
#define __VARIABLES_H

#include "functions.h"
#include "struct_and_define.h"
#include <GL/glut.h>
#include <time.h>

GLuint names[20];
float x_hearth=0;
float y_hearth=0;
int absolute_position_x;
int absolute_position_y;
float t=0;
float gradient;
time_t start_time;
time_t current_time;
int fps=0;
int fps_counter=0;
int random_attack;
int hp=20;
int my_damage;
int enemy_hp=20;
int current_texture_w;
int current_texture_h;
int player_side=1;
int current_map;
int talk_phase=0;
int previous_player_side;

//STRUCT-------------------------------------------------------
char* wtp;
CVOR* inv;
Enemy* curr_enemy;
Item* weapon_equiped;
Vector vec;
Vector walking_vec;
Quad walking_collision_array[4];
Quad events[4];


//FLAGS---------------------------------------------------------
int game_state=1; // TODO GAME STATE
int action_highlited=0;
int action_selected=0;
int mercy_action_highlited=0;
int mercy_action_selected=0;
int in_menu_menu=0;
int selecting_talk=0;
int mercy=0;
int can_spare=0;
int item_selected=0;
int items_in_inv=0;
int enemy_turn=0;
int invulnerable=0;
int walking=0;
int really_walking=0;
int animation_phase=0;
int conversation_happening;

int win_screen=0;
int escape_screen=0;

void (*att_ptrs[])() = {bullet_hell_1,bullet_hell_2,bullet_hell_3,bullet_hell_4,bullet_hell_5};
void (*events_ptr[])() = {switch_to_hall,first_talk,switch_to_entrance};

#endif
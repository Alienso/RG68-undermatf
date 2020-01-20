#ifndef __VARIABLES_H
#define __VARIABLES_H

#include "functions.h"
#include "struct_and_define.h"
#include <GL/glut.h>
#include <time.h>

GLuint names[20];
float x_hearth=0;
float y_hearth=-0.2;
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
int enemy_hp;
int current_texture_w;
int current_texture_h;
int player_side=1;
int current_map;
int talk_phase=0;
int previous_player_side;
int last_key_pressed;
int shop_item_selected=0;
int items_in_shop=0;
int gold=100;
int shield_side=0;
int mini_game_counter=0;
int mini_game_speed=0;

#ifndef AUDIO
ALuint buffer1, buffer2, buffer3, source[3];
ALuint state;
#endif

//STRUCT-------------------------------------------------------
char* wtp;
int boss_field[100][100];
CVOR* inv;
Enemy* curr_enemy;
Item* weapon_equiped;
Vector vec;
Vector walking_vec;
Quad walking_collision_array[4];
Event events[4];
Spear spears[20];

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
int encounter_start_animation=0;
int exclamation_mark=0;

int win_screen=0;
int escape_screen=0;

void (*att_ptrs[])() = {bullet_hell_0,
                        bullet_hell_1,bullet_hell_2,bullet_hell_3,bullet_hell_4,bullet_hell_5,
                        bullet_hell_6,bullet_hell_7,bullet_hell_8,bullet_hell_9,bullet_hell_10,
                        bullet_hell_11,bullet_hell_12,bullet_hell_13,bullet_hell_14,bullet_hell_15,
                        bullet_hell_16,bullet_hell_17,bullet_hell_18,bullet_hell_19,bullet_hell_20,
                        bullet_hell_21};
void (*events_ptr[])() = {first_talk,switch_to_hall,switch_to_entrance,open_chemist_shop,tutorial_guy_talk,switch_to_4,npc_test};
Item* Chemist_items[4];

#endif
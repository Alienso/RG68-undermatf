#ifndef _FJE_
#define _FJE_

#include "struct_and_define.h"
#include <GL/glut.h>

static void on_keyboard_encounter(unsigned char key, int x, int y);
static void on_keyboard_walking(unsigned char key, int x, int y);
static void on_keyboard_combat(unsigned char key, int x, int y);
static void on_keyboard_talk(unsigned char key, int x, int y);
static void on_keyboard_mercy(unsigned char key, int x, int y);
static void on_keyboard_none(unsigned char key, int x, int y);

static void on_keyboard_inventory(unsigned char key, int x, int y);
static void on_keyboard_to_encouter(unsigned char key, int x, int y);
static void on_keyboard_to_combat(unsigned char key, int x, int y);
static void on_keyboard_to_walking(unsigned char key, int x, int y);

static void on_keyboard_up_combat(unsigned char key, int x,int y);
static void on_keyboard_up_walking(unsigned char key, int x,int y);


static void on_timer_encounter(int value);
static void on_timer_walking(int value);
static void on_timer_combat(int value);
static void on_timer_next(int value);
static void on_timer_text(int value);
static void on_timer_move_combat(int value);
static void on_timer_move_walking(int value);
static void on_timer_invulnerable(int value);
static void on_timer_animation_move(int value);

static void on_display_encounter(void);
static void on_display_combat(void);
static void on_display_walking(void);

void resize(int x,int y);

void draw_text(char niska[], GLfloat x_val, GLfloat y_val,float r_,float g_,float b_);
void draw_hearth();
void draw_base();
void draw_menu();
void draw_inventory();
void draw_win();
void draw_escape();
void draw_mercy();
void draw_conversation();

void check_collision(float x,float y);
void switch_to_combat();
void highlight_current();
void init();
void initTextures();
void init_inv();
void init_Items_Enemies();
void init_walking_collisions();
void init_events();


int can_walk();
int check_quad(int x1,int x2,int y1,int y2);
int check_events();
void add_to_wca(int x1,int x2,int y1,int y2);
void add_event(int x1,int x2,int y1,int y2);
void remove_event(int i);


void remove_from_inv(int item_selected,CVOR** inv);
void add_to_inv(Item* item,CVOR** inv);

Item* new_Item(char* name,char* desc,int att,int def,int hp,int consumable);
Enemy* new_Enemy(char* name,char* quote1,char* quote2,int hp,int att,int def,int attacks[5]);

void bullet_hell_1();
void bullet_hell_2();
void bullet_hell_3();
void bullet_hell_4();
void bullet_hell_5();
void bullet_hell_6();
void bullet_hell_7();
void bullet_hell_8();
void bullet_hell_9();
void bullet_hell_10();
void bullet_hell_11();
void bullet_hell_12();
void bullet_hell_13();
void bullet_hell_14();
void bullet_hell_15();
void bullet_hell_16();
void bullet_hell_17();
void bullet_hell_18();
void bullet_hell_19();
void bullet_hell_20();


void first_talk();
void switch_to_hall();
void switch_to_entrance();



#endif
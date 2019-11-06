#ifndef _HEADER_
#define _HEADER_

#define TIMER_NEXT 0
#define TIMER_TEXT 1

#define WALKING 0
#define ENCOUNTER 1
#define COMBAT 2
#define MENU 3

typedef struct ITEM{
    char name[30];
    char description[200];
    int att;
    int def;
    int hp;
    int consumable;
}Item;

typedef struct INVENTORY{
    Item Items[24];

}Inventory;

typedef struct cvor{
	Item* Items;
	struct cvor* sledeci;
}CVOR;

typedef struct ENEMY{
    char name[30];
    char quote[2][50];
    int hp;
    int att;
    int def;
}Enemy;

static void on_keyboard_encounter(unsigned char key, int x, int y);
static void on_keyboard_walking(unsigned char key, int x, int y);
static void on_keyboard_combat(unsigned char key, int x, int y);
static void on_keyboard_talk(unsigned char key, int x, int y);
static void on_keyboard_mercy(unsigned char key, int x, int y);
static void on_keyboard_next(unsigned char key, int x, int y);
static void on_keyboard_none(unsigned char key, int x, int y);
static void on_keyboard_inventory(unsigned char key, int x, int y);

static void on_timer_encounter(int value);
static void on_timer_walking(int value);
static void on_timer_combat(int value);
static void on_timer_next(int value);
static void on_timer_text(int value);

static void on_display_encounter(void);
static void on_display_combat(void);
static void on_display_walking(void);

void draw_hearth();
void draw_base();
void draw_menu();
void draw_inventory();
void draw_win();
void draw_escape();
void draw_mercy();
void draw_conversation(char* s);

void highlight_current();
//void bullet_hell();
void init();
Item* new_Item(char* name,char* desc,int att,int def,int hp,int consumable);
Enemy* new_Enemy(char* name,char* quote1,char* quote2,int hp,int att,int def);


float x_hearth=0;
float y_hearth=0;
float t=0;

char* wtp;
CVOR* inv;

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

int win_screen=0;
int escape_screen=0;

int hp=20;
int my_damage = 5;
int enemy_hp=20;

#endif
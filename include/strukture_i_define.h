#ifndef _STRUKTURE_I_DEFINE
#define _STRUKTURE_I_DEFINE

#define TIMER_NEXT 0
#define TIMER_TEXT 1
#define TIMER_COMBAT 2
#define TIMER_MOVE_COMBAT 3
#define TIMER_INVULNERABLE 4

#define WALKING 0
#define ENCOUNTER 1
#define COMBAT 2
#define MENU 3

#define max_hp 20

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
    int attacks[5];
}Enemy;

typedef struct VECTOR{
    int x;
    int y;
}Vector;

#endif
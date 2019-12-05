#ifndef _ITEMS_ENEMIES_
#define _ITEMS_ENEMIES_

#include "header.h"

Item* Pizza;
Item* RolVirsla;
Item* Kafa;
Item* CheezeCake;

Item* H2SO4;
Item* InvisibilityPotion;
Item* MysteriousPotion;
Item* HPPotion;

Item* Spoon;
Item* Knjiga;
Item* Olovka;

Enemy* Programer;
Enemy* Menadzer;
Enemy* OperacioniMenadzer;
Enemy* MenadzerKvaliteta;
Enemy* Boss;

Enemy* new_Enemy(char* name,char* quote1,char* quote2,int hp,int att,int def){

    Enemy* new_Enemy;
    new_Enemy=(Enemy*) calloc(1,sizeof(Enemy));
    if (new_Enemy==NULL){
        fprintf(stderr,"Enemy");
        exit(1);
    }

    new_Enemy->att=att;
    new_Enemy->def=def;
    strcpy(new_Enemy->name,name);
    strcpy(new_Enemy->quote[0],quote1);
    strcpy(new_Enemy->quote[1],quote2);

    return new_Enemy;

}
#endif
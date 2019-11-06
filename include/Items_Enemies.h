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

void init_Items_Enemies(){

    /*Pizza = new_Item("Pizza\0","Capricciosa\0",0,0,10,1);
    RolVirsla= new_Item("RolVirsla\0","...\0",0,0,10,1);
    Kafa= new_Item("Kafa\0","Nescafe\0",1,0,5,1);
    CheezeCake= new_Item("CheezeCake\0","...\0",0,2,20,1);

    H2SO4= new_Item("H2SO4\0","Smells Bad\0",10,0,0,1);
    InvisibilityPotion= new_Item("Invisibilty Potion\0","Smells Delicious\0",0,0,0,1);
    //MysteriousPotion= new_Item();
    HPPotion= new_Item("HP Potion\0","Restores Health\0",0,0,10,1);

    Spoon= new_Item("Spoon\0","Its a small spoon\0",10,0,0,0);

    Programer = new_Enemy("Programer sa FON-a\0","Java is Supreme Programing Language\0","Who needs Math anyway\0",10,2,0);
    Menadzer = new_Enemy("Menadzer sa FON-a\0","smth\0","smthh\0",20,5,5);
    OperacioniMenadzer = new_Enemy("Operacioni Menadzer\0","ssda\0","sdqweq\0",30,7,5);
    MenadzerKvaliteta = new_Enemy("Menadzer Kvaliteta\0","dsad\0","dasew\0",30,4,8);
    Boss = new_Enemy("Final Boss","sdas\0","ewqe\0",50,10,5);*/

}


#endif
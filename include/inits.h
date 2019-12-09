#ifndef _INITS_H
#define _INITS_H

#include "header.h"
#include "image.h"

#define FILENAME0 "./assets/ulaz.bmp"
#define FILENAME1 "./assets/player/player_front.bmp"

GLuint names[2];
static GLuint names2[2];

void initTextures(void)
{
    Image * image;

    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

    image = image_init(0, 0);

    image_read(image, FILENAME0);

    glGenTextures(2, names);

    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);


    image_read(image, FILENAME1);

    glBindTexture(GL_TEXTURE_2D, names[1]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    glBindTexture(GL_TEXTURE_2D, 0);

    image_done(image);
}

void init_Items_Enemies(){

    Pizza = new_Item("Pizza\0","Capricciosa\0",0,0,10,1);
    RolVirsla= new_Item("RolVirsla\0","...\0",0,0,10,1);
    Kafa= new_Item("Kafa\0","Nescafe\0",1,0,5,1);
    CheezeCake= new_Item("CheezeCake\0","...\0",0,2,20,1);

    H2SO4= new_Item("H2SO4\0","Smells Bad\0",10,0,0,1);
    InvisibilityPotion= new_Item("Invisibilty Potion\0","Smells Delicious\0",0,0,0,1);
    //MysteriousPotion= new_Item();
    HPPotion= new_Item("HP Potion\0","Restores Health\0",0,0,10,1);

    Spoon= new_Item("Spoon\0","Its a small spoon\0",10,0,0,0);
    Knjiga=new_Item("Knjiga\0","Knjiga iz Analize 1\0",1,1,0,0);
	Olovka=new_Item("Olovka\0","Tupa je\0",2,0,0,0);

    int programer_attacks[5]={0,1,2,3,4};
    int menadzer_attacks[5]={5,6,7,8,9};
    int operacioni_attacks[5]={10,11,12,13,14};
    int menadzer_kvaliteta_attacks[5]={15,16,17,18,19};
    int boss_attacks[5]={20,21,22,23,24};

    Programer = new_Enemy("Programer sa FON-a\0","Java is Supreme Programing Language\0","Who needs Math anyway\0",10,2,0,programer_attacks);
    Menadzer = new_Enemy("Menadzer sa FON-a\0","smth\0","smthh\0",20,5,5,menadzer_attacks);
    OperacioniMenadzer = new_Enemy("Operacioni Menadzer\0","ssda\0","sdqweq\0",30,7,5,operacioni_attacks);
    MenadzerKvaliteta = new_Enemy("Menadzer Kvaliteta\0","dsad\0","dasew\0",30,4,8,menadzer_kvaliteta_attacks);
    Boss = new_Enemy("Final Boss\0","sdas\0","ewqe\0",50,10,5,boss_attacks);

}

void init_inv(){

	inv=NULL;
	
	add_to_inv(HPPotion,&inv);

	items_in_inv=1;


}

void init(){

    wtp=(char*)calloc(200,sizeof(char));
    if (wtp==NULL){
        fprintf(stderr,"WTP");
        exit(1);
    }

    srand(time(NULL));
    init_Items_Enemies();
    init_inv();
    initTextures();
    
    weapon_equiped=Olovka;
    curr_enemy=Programer;

    int hp=max_hp;
    int my_damage = weapon_equiped->att;
    int enemy_hp=curr_enemy->hp;
    absolute_position_x=64;
    absolute_position_y=64;
    walking=0;

    walking_vec.x=0;
    walking_vec.y=0;
    vec.x=0;
    vec.y=0;
}
#endif
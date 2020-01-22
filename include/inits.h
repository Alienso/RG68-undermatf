#ifndef _INITS_H
#define _INITS_H

#include "header.h"
#include "image.h"
#include "Items_Enemies.h"

#define FILENAME0 "./assets/ulaz.bmp"
#define FILENAME1 "./assets/prvi.bmp"
#define FILENAME2 "./assets/cetvrti.bmp"


/*#define FILENAME6 "./assets/programer.bmp"
#define FILENAME7 "./assets/menadzer.bmp"
#define FILENAME8 "./assets/operacioni_menadzer.bmp"
#define FILENAME9 "./assets/boss.bmp"*/

#define FILENAME10 "./assets/player/player_front.bmp"
#define FILENAME11 "./assets/player/player_front2.bmp"
#define FILENAME12 "./assets/player/player_back.bmp"
#define FILENAME13 "./assets/player/player_back2.bmp"
#define FILENAME14 "./assets/player/player_left.bmp"
#define FILENAME15 "./assets/player/player_left2.bmp"
#define FILENAME16 "./assets/player/player_right.bmp"
#define FILENAME17 "./assets/player/player_right2.bmp"

#define FILENAME18 "./assets/chemist.bmp"
#define FILENAME19 "./assets/menu.bmp"

#define SFILENAME1 "./assets/sounds/walking.wav"
#define SFILENAME2 "./assets/sounds/boss.wav"
#define SFILENAME3 "./assets/sounds/fight.wav"

void initTextures(void)
{
    Image * image;

    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

    image = image_init(0, 0);

    glGenTextures(20, names);

    //ULAZ
    image_read(image, FILENAME0);

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

    //PRVI SPRAT
    image_read(image, FILENAME1);

    glBindTexture(GL_TEXTURE_2D, names[1]);
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

    //CETVRTI SPRAT
    image_read(image, FILENAME2);

    glBindTexture(GL_TEXTURE_2D, names[2]);
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

    /*//PROGRAMER
    image_read(image, FILENAME6);

    glBindTexture(GL_TEXTURE_2D, names[6]);
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

    //MENADZER
    image_read(image, FILENAME7);

    glBindTexture(GL_TEXTURE_2D, names[7]);
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

    //OPERACIONI MENADZER
    image_read(image, FILENAME8);

    glBindTexture(GL_TEXTURE_2D, names[8]);
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

    //BOSS
    image_read(image, FILENAME9);

    glBindTexture(GL_TEXTURE_2D, names[9]);
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
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);*/



    //PLAYER_FRONT
    image_read(image, FILENAME10);

    glBindTexture(GL_TEXTURE_2D, names[10]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                 image->width, image->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);

                 
    //PLAYER_FRONT_DOWN
    image_read(image, FILENAME11);

    glBindTexture(GL_TEXTURE_2D, names[11]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                 image->width, image->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);


    //PLAYER_BACK
    image_read(image, FILENAME12);

    glBindTexture(GL_TEXTURE_2D, names[12]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                 image->width, image->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);

    //PLAYER_BACK_DOWN
    image_read(image, FILENAME13);

    glBindTexture(GL_TEXTURE_2D, names[13]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                 image->width, image->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);

    //PLAYER_LEFT
    image_read(image, FILENAME14);

    glBindTexture(GL_TEXTURE_2D, names[14]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                 image->width, image->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);

    //PLAYER_LEFT_DOWN
    image_read(image, FILENAME15);

    glBindTexture(GL_TEXTURE_2D, names[15]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                 image->width, image->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);

    //PLAYER_RIGHT
    image_read(image, FILENAME16);

    glBindTexture(GL_TEXTURE_2D, names[16]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                 image->width, image->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);

    //PLAYER_RIGHT_DOWN
    image_read(image, FILENAME17);

    glBindTexture(GL_TEXTURE_2D, names[17]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                 image->width, image->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);


    //CHEMIST
    image_read(image, FILENAME18);

    glBindTexture(GL_TEXTURE_2D, names[18]);
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

    //MENU
    image_read(image, FILENAME19);

    glBindTexture(GL_TEXTURE_2D, names[19]);
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

    glBindTexture(GL_TEXTURE_2D, 0);


    image_done(image);
}

void init_Items_Enemies(){

    Pizza = new_Item("Pizza\0","Capricciosa\0",0,0,10,1,100);
    RolVirsla= new_Item("RolVirsla\0","...\0",0,0,10,1,80);
    Kafa= new_Item("Kafa\0","Nescafe\0",1,0,5,1,50);
    CheezeCake= new_Item("CheezeCake\0","...\0",0,2,20,1,250);

    H2SO4= new_Item("H2SO4\0","Smells Bad\0",15,0,0,1,50);
    InvisibilityPotion= new_Item("Invisibilty Potion\0","Smells Delicious\0",0,0,0,1,50);
    MysteriousPotion= new_Item("Mysterious Potion\0","Glows!\0",0,0,0,1,1000);
    HPPotion= new_Item("HP Potion\0","Restores Health\0",0,0,10,1,20);

    Spoon= new_Item("Spoon\0","Its a small spoon\0",10,0,0,0,0);
    Knjiga=new_Item("Knjiga\0","Knjiga iz Analize 1\0",1,1,0,0,0);
	Olovka=new_Item("Olovka\0","Tupa je\0",5,0,0,0,0);

    int dummy_attacks[5]={0,0,0,0,0};
    int programer_attacks[5]={1,2,3,15,5};
    int menadzer_attacks[5]={10,11,7,8,12};
    int operacioni_attacks[5]={4,6,9,13,14};
    int menadzer_kvaliteta_attacks[5]={20,16,17,18,19};
    int boss_attacks[5]={21,21,21,21,21};

    Dummy = new_Enemy("Dummy\0","You Talk to a Dummy..... Doesnt seem much of a conversation\0","You Talk to a Dummy..... Doesnt seem much of a conversation\0",15,2,0,dummy_attacks);
    Programer = new_Enemy("Programer sa FON-a\0","Who needs Math anyway\0","Who needs Math anyway\0",25,3,0,programer_attacks);
    Menadzer = new_Enemy("Menadzer sa FON-a\0","You think you're so smart...Hmmm?\0","You think you're so smart...Hmmm?\0",30,5,5,menadzer_attacks);
    OperacioniMenadzer = new_Enemy("Operacioni Menadzer\0","FON is LIFE\0","FON is LIFE\0",35,4,5,operacioni_attacks);
    MenadzerKvaliteta = new_Enemy("Menadzer Kvaliteta\0","dsad\0","dasew\0",30,4,8,menadzer_kvaliteta_attacks);
    Boss = new_Enemy("Final Boss\0","This is the END\0","This is the END\0",50,4,5,boss_attacks);

    Chemist_items[0]=H2SO4;
    Chemist_items[1]=HPPotion;
    Chemist_items[2]=MysteriousPotion;
    Chemist_items[3]=InvisibilityPotion;
}

void init_inv(){

	inv=NULL;
	
	add_to_inv(HPPotion,&inv);

	items_in_inv=1;


}

void init_walking_collisions(){

    current_map=0;
    for (int i=0;i<4;i++)
        walking_collision_array[i].size=0;

    add_to_wca(62,73,57,80);//Covek
    add_to_wca(59,66,62,115); //levi deo stepenica
    add_to_wca(89,96,62,115); //desni deo stepenica
    add_to_wca(4,6,24,105); //levi zid
    add_to_wca(123,125,26,105); //desni zid
    add_to_wca(4,124,26,28); // donji zid
    add_to_wca(4,124,103,105); //gornji zid
    add_to_wca(44,59,37,69); //4. stub
    add_to_wca(44,59,71,102);//3
    add_to_wca(96,112,37,69);//2
    add_to_wca(96,112,71,102);//1

    current_map=1;
    add_to_wca(346+512,420+512,46,48); // donji zid ulaz
    add_to_wca(418+512,460+512,46,59); //sobica dole
    add_to_wca(420+512,481+512,71,95); //sobica gore
    add_to_wca(449+512,451+512,55,73); //desni zid sobica
    add_to_wca(349+512,351+512,46,96); //levi zid ulaz
    add_to_wca(477+512,479+512,94,182); //desni zid
    add_to_wca(239+512,481+512,180,182); //gornji zid
    add_to_wca(232+512,241+512,124,207); //levi zid hall
    add_to_wca(321+512,348+512,136,163);//molekuli
    add_to_wca(731,737,124,207); //levi zid uske prostorije
    add_to_wca(731,750,201,203); //gornji zid uske prostorije
    add_to_wca(495,708,122,153); //gornji zid hodnik
    add_to_wca(200,465,122,153); //gornji zid hodnik nastavak
    add_to_wca(495,348+512,94,97); //donji zid hodnik
    add_to_wca(410,481,66,95); //donji zid hodnik nastavak
    add_to_wca(706,735,150,152); //stepenice uske
    add_to_wca(461,500,149,151); //studentska sluzba vrata gore
    add_to_wca(500,502,32,95); //wc desni zid
    add_to_wca(380,504,35,37); //wc donji zid
    add_to_wca(494,502,68,72); //ws pregrada
    add_to_wca(441,450,34,70); //wc podela vertikalna
    add_to_wca(417,475,49,57); //wc podela horizontalna
    add_to_wca(416,421,30,38); //wc leva donja pregrada
    add_to_wca(386,389,35,96); //wc levi zid
    add_to_wca(388,397,69,71); //wc leva gornja pregrada
    add_to_wca(428,462,30,80); //wc solje
    add_to_wca(345,400,93,95); //zadnji deo hodnika
    add_to_wca(312,318,0,123); //skroz desno
    add_to_wca(300,323,46,61); //tabla
    add_to_wca(322,343,27,40); //klupa
    add_to_wca(310,354,0,26); //vrata desno
    add_to_wca(348,373,0,77); //lift
    add_to_wca(715,731,122,144); //stepenice ka dole

    current_map=0;
    return;
}

void init_events(){

    for (int i=0;i<4;i++)
        events[i].size=0;

    current_map=0;

    add_event(70,85,53,55,0); //first talk;
    add_event(66,89,92,94,1); //entrance->hall
    
    current_map=1;
    add_event(888,900,48,50,2); //hall->entrance
    add_key_event(590,605,107,123,3); //chemist
    add_event(373,386,59,61,5); //entrance->4 lift
    add_event(718,731,144,146,5); //entrence->4 stepenice
    add_key_event(936,945,168,175,6); //NPC Test Boss
    add_key_event(948,957,168,175,6); // -||- Operacioni Menadzer
    add_key_event(960,969,168,175,6); //Menadzer
    add_key_event(973,982,168,175,6); //Programer


    current_map=0;

}

#ifndef AUDIO
void init_audio(){
    buffer1 = alutCreateBufferFromFile(SFILENAME1);
    buffer2 = alutCreateBufferFromFile(SFILENAME2);
    buffer3 = alutCreateBufferFromFile(SFILENAME3);

    alGenSources(3, &source);
    alSourcei(source[0], AL_BUFFER, buffer1);
    alSourcei(source[1], AL_BUFFER, buffer2);
    alSourcei(source[2], AL_BUFFER, buffer3);

    return;
}
#endif
void init(){

    wtp=(char*)calloc(200,sizeof(char));
    if (wtp==NULL){
        fprintf(stderr,"WTP");
        exit(1);
    }

    for (int i=0;i<100;i++)
        for (int j=0;j<100;j++)
            boss_field[i][j]=0;

    srand(time(NULL));
    init_Items_Enemies();
    init_inv();
    initTextures();
    init_walking_collisions();
    init_events();
    #ifndef AUDIO
    init_audio();
    #endif

    player_side=10;
    current_map=0;
    weapon_equiped=Olovka;
    curr_enemy=Programer;
    encounter_start_animation=0;

    hp=max_hp;
    my_damage = weapon_equiped->att;
    enemy_hp=curr_enemy->hp;
    absolute_position_x=75;
    absolute_position_y=28;
    walking=1;
    gradient=-1;

    walking_vec.x=0;
    walking_vec.y=0;
    vec.x=0;
    vec.y=0;
}
#endif

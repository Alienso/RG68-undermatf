//RADJENO NA P2 KURSU, C NEMA PODRSKU ZA LISTE PA SAM PREUZEO KODOVE SA CASA I PROLAGODIO IH

#ifndef _INVENTORY_
#define _INVENTORY_

#include "header.h"
#include "Items_Enemies.h"

CVOR* napravi_cvor(Item* i){
	CVOR* novi_cvor;


	novi_cvor=(CVOR*) calloc(1,sizeof(CVOR));
	if(novi_cvor==NULL){
		fprintf(stderr, "Problem sa alokacijom!\n");
		exit(1);
	}
    novi_cvor->Items=i;

	return novi_cvor;
}


void dodaj_na_pocetak(Item* v, CVOR** p_pocetak_liste){
	CVOR* novi_cvor;

	novi_cvor=napravi_cvor(v);
	
	novi_cvor->sledeci=*p_pocetak_liste;
	*p_pocetak_liste=novi_cvor;
}

void add_to_inv(Item* v, CVOR** pocetak_liste){

	if(*pocetak_liste==NULL){
		CVOR* novi_cvor=napravi_cvor(v);
		novi_cvor->sledeci=NULL;
		*pocetak_liste=novi_cvor;
		return;
	}
	
	add_to_inv(v,&((*pocetak_liste)->sledeci));

}


void remove_from_inv(int q, CVOR** p_pocetak_liste){
	
	if(*p_pocetak_liste==NULL)
		return;
	
	if (q==0){
		CVOR* pomocni_cvor=(*p_pocetak_liste);
		if (pomocni_cvor==NULL)
			return;
		(*p_pocetak_liste)=(*p_pocetak_liste)->sledeci;
		use_item(pomocni_cvor);
		free(pomocni_cvor);

		items_in_inv--;
		return;
	}

	int i=0;
	while(*p_pocetak_liste!=NULL && i!=q-1){
		CVOR* pomocni_cvor=*p_pocetak_liste;
		*p_pocetak_liste=(*p_pocetak_liste)->sledeci;
		use_item(pomocni_cvor);
		free(pomocni_cvor);
		i++;
	}

	if(*p_pocetak_liste==NULL)
		return;

	/*CVOR* prethodni_cvor=*p_pocetak_liste;
	CVOR* tekuci_cvor=(*p_pocetak_liste)->sledeci;

	CVOR* pomocni_cvor=tekuci_cvor;
	prethodni_cvor->sledeci=tekuci_cvor->sledeci;
	tekuci_cvor=tekuci_cvor->sledeci;
	free(pomocni_cvor);*/

	CVOR* pomocni_cvor=(*p_pocetak_liste)->sledeci;
	if (pomocni_cvor==NULL)
		return;
	(*p_pocetak_liste)->sledeci=(*p_pocetak_liste)->sledeci->sledeci;
	use_item(pomocni_cvor);
	free(pomocni_cvor);

	items_in_inv--;
}

void pisi_listu(CVOR* pocetak_liste){
	
	CVOR* tekuci_cvor=pocetak_liste;

	while(tekuci_cvor!=NULL){
		draw_text(tekuci_cvor->Items->name,0,0,1,1,1);
		tekuci_cvor=tekuci_cvor->sledeci;
	}
}


void oslobodi_listu(CVOR** p_pocetak_liste){
	CVOR* tekuci_cvor=*p_pocetak_liste;

	while(tekuci_cvor!=NULL){
		CVOR* pomocni_cvor=tekuci_cvor;
		tekuci_cvor=tekuci_cvor->sledeci;
		free(pomocni_cvor);
	}

	*p_pocetak_liste=NULL;
}

/*CVOR* obidji_listu(Item* v, CVOR* pocetak_liste){
	
	CVOR* tekuci_cvor=pocetak_liste;
	
	while(tekuci_cvor!=NULL){
		if(tekuci_cvor->vrednost==v)
			return tekuci_cvor;
		tekuci_cvor=tekuci_cvor->sledeci;
	}

	return NULL;
}*/

Item* new_Item(char* name,char* desc,int att,int def,int hp,int consumable,int price){

    Item* new_Item;
    new_Item=(Item*) calloc(1,sizeof(Item));
    if (new_Item==NULL){
        fprintf(stderr,"Item");
        exit(1);
    }

    new_Item->att=att;
    new_Item->def=def;
    new_Item->hp=hp;
    new_Item->consumable=consumable;
	new_Item->price=price;
    strcpy(new_Item->name,name);
    strcpy(new_Item->description,desc);

    return new_Item;
}

void use_item(CVOR* item){

	hp+=item->Items->hp;
	enemy_hp-=item->Items->att;

	if (hp>max_hp)
	hp=max_hp;

    if (enemy_hp<=0){
        glutDisplayFunc(draw_win);
        glutKeyboardFunc(on_keyboard_to_walking);
    }

	if (strcmp(item->Items->name,"Invisibilty Potion")==0)
		invisible=1;
	glutTimerFunc(60*1000,on_timer_invisible,TIMER_INVISIBLE);
	return;
}
#endif
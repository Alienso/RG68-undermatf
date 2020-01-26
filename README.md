# RG68-undermatf
UnderMatf


Igra se sastoji od poteza, igrac treba da izbegava protivnikove napade sto je duze moguce.


Komande:

| WASD  |  Kretanje |

| Space | Interakcija |

| + - | Ubrzavanje/Usporavanje borbe |


Posto brzina igre zavisi od racunara pozeljeno je, radi boljeg iskustva, kalibrisati igru tako da se pri prvoj borbi linija krece simetricno sleva na desno a ne da prekine kretanje pri kraju puta puta.


Postoje 2 verzije igre sa zvukom i bez (ukoliko iz bilo kog razloga bude problema sa alut u openal bibliotekom)
potrebno je uraditi #define AUDIO u header.h fajlu da bi se iskljucio zvuk.
Zbog toga postoje i 2 MakeFile-a, jedan koji ukljucuje alut i drugi koji ne.


instalacija OpanAl-a i alut-a:

   OpenAL: sudo apt-get install libopenal0a libopenal-dev

   ALUT:   sudo apt-get install libalut0 libalut-dev


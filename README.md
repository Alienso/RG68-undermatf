# RG68-undermatf
UnderMatf

Komande:

| WASD  |  Kretanje |

| Space | Interakcija |


Postoje 2 verzije igre sa zvukom i bez (ukoliko iz bilo kog razloga bude problema sa alut u openal bibliotekom)
potrebno je uraditi #define AUDIO u header.h fajlu da bi se iskljucio zvuk.
Zbog toga postoje i 2 MakeFile-a, jedan koji ukljucuje alut i drugi koji ne.

instalacija OpanAl-a i alut-a:

   OpenAL: sudo apt-get install libopenal0a libopenal-dev

   ALUT:   sudo apt-get install libalut0 libalut-dev


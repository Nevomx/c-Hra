#pragma once
#include <string>
using namespace std;
#include "Character.h"


class bereserker : Character
{
    
    public:
        string jmeno;
        int maxZivoty;
        int aktualniZivoty;
        int maxMana;
        int aktualniMana;
        int zlato;
        int level;
        int zkusenosti;
        float utok;
        int Schopnost;
        int poisonTurns = 0;

        Character();
        void zakladniutok(Monster & monster);
        void critical(Monster & monster);
        void zobrazStav();
        void hodsekerou();
        void provestah(Monster & monster);
        void checkpoison();
        void KonecHry();

    
};


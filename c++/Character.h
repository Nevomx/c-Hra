
#pragma once
#include <string>
using namespace std;

class Monster; 

class Character
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
    int vyberclass;
    int shieldTurns = 0;
    bool vyruseniUtoku = false;
    bool tahproveden = false;
    bool porazeni = false;


    Character(string jmeno, int vyberclass);
    void zakladniutok(Monster& monster);
    void critical(Monster& monster);
    void zobrazStav();
    void hodsekerou(Monster& monster, Monster* monster1 = nullptr, Monster* monster2 = nullptr);
    void Shield();
    void provestah(Monster& monster, Monster* monster1 = nullptr, Monster* monster2 = nullptr);
    void checkpoison();
    void KonecHry();
    void heal();
    void aktivujBonus();
    void navstivVesnici();
    void levelUp();

};

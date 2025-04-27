
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

    Character(string jmeno, int vyberclass);
    void zakladniutok(Monster& monster);
	void critical(Monster& monster);
	void zobrazStav();
};

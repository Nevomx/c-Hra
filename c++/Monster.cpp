#include "Monster.h"
#include "Character.h"
#include <iostream>
using namespace std;

Monster::Monster(int monster)
{
    switch (monster)
    {
    case 1:
        jmeno = "zombie";
        maxZivoty = 50;
        aktualniZivoty = 50;
        utok = 10;
        break;
    case 2:
        jmeno = "skeleton";
        maxZivoty = 50;
        aktualniZivoty = 50;
        utok = 10;
        break;
    case 3:
        jmeno = "chicken jockey";
        maxZivoty = 50;
        aktualniZivoty = 50;
        utok = 15;
        break;
    }
}

void Monster::attack(Character& characterhrac)
{
    if (characterhrac.shieldTurns > 0)
    {
        utok /= 2; // Snížení poškození o 50 %
        characterhrac.shieldTurns--; // Snížení poètu zbývajících kol štítu
        cout << characterhrac.jmeno << " má aktivní Svatý Štít! Poškození sníženo na " << utok << "." << endl;
    }
   
    
    cout << "Monster " << jmeno << " zaútoèil na " << characterhrac.jmeno << " a zpùsobil mu " << utok << " poškození!" << endl;
    characterhrac.aktualniZivoty -= utok;
    cout << characterhrac.jmeno << " má teï " << characterhrac.aktualniZivoty << " životù." << endl;
    
   
}

void Monster::poisonarrow(Character& characterhrac, int kolo)
{
    if (jmeno == "skeleton")
    {
        characterhrac.aktualniZivoty -= 7;
        characterhrac.poisonTurns += 3;
    }
    else
    {
        cout << "nefunguje ty curaku";
    }
}

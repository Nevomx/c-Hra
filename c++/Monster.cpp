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
        maxZivoty = 100;
        aktualniZivoty = 100;
        utok = 10;
        break;
    case 2:
        jmeno = "skeleton";
        maxZivoty = 100;
        aktualniZivoty = 100;
        utok = 10;
        break;
    case 3:
        jmeno = "chicken jockey";
        maxZivoty = 100;
        aktualniZivoty = 100;
        utok = 15;
        break;
    }
}

void Monster::attack(Character& characterhrac)
{
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

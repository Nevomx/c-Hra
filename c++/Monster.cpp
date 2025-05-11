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
        utok /= 2; // Sn�en� po�kozen� o 50 %
        characterhrac.shieldTurns--; // Sn�en� po�tu zb�vaj�c�ch kol �t�tu
        cout << characterhrac.jmeno << " m� aktivn� Svat� �t�t! Po�kozen� sn�eno na " << utok << "." << endl;
    }
   
    
    cout << "Monster " << jmeno << " za�to�il na " << characterhrac.jmeno << " a zp�sobil mu " << utok << " po�kozen�!" << endl;
    characterhrac.aktualniZivoty -= utok;
    cout << characterhrac.jmeno << " m� te� " << characterhrac.aktualniZivoty << " �ivot�." << endl;
    
   
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

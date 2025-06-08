#include "Monster.h"
#include "Character.h"
#include <iostream>
#include <random>
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
    case 4:
        jmeno = "Miniboss";
        maxZivoty = 150;
        aktualniZivoty = 150;
        utok = 20;
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
void Monster::chickenAttack(Character& characterhrac)
{
    if (jmeno == "chicken jockey") // Pouze pro chicken jockey
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, 100); // Rozsah 1-100

        int chance = distrib(gen); // Generov�n� n�hodn�ho ��sla
        if (chance <= 50) // 25% �ance, �e slepice za�to��
        {
            cout << "Slepice z chicken jockey za�to�ila na " << characterhrac.jmeno << " a zp�sobila mu 2 po�kozen�!" << endl;
            characterhrac.aktualniZivoty -= 2; // Sn�en� �ivot� hr��e o 2
            cout << characterhrac.jmeno << " m� te� " << characterhrac.aktualniZivoty << " �ivot�." << endl;
        }
        else
        {
            cout << "Slepice z chicken jockey se rozhodla neza�to�it." << endl;
        }
    }
    else
    {
        cout << "Tento �tok nen� dostupn� pro toto monstrum." << endl;
    }
}
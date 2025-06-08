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
void Monster::chickenAttack(Character& characterhrac)
{
    if (jmeno == "chicken jockey") // Pouze pro chicken jockey
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, 100); // Rozsah 1-100

        int chance = distrib(gen); // Generování náhodného èísla
        if (chance <= 50) // 25% šance, že slepice zaútoèí
        {
            cout << "Slepice z chicken jockey zaútoèila na " << characterhrac.jmeno << " a zpùsobila mu 2 poškození!" << endl;
            characterhrac.aktualniZivoty -= 2; // Snížení životù hráèe o 2
            cout << characterhrac.jmeno << " má teï " << characterhrac.aktualniZivoty << " životù." << endl;
        }
        else
        {
            cout << "Slepice z chicken jockey se rozhodla nezaútoèit." << endl;
        }
    }
    else
    {
        cout << "Tento útok není dostupný pro toto monstrum." << endl;
    }
}
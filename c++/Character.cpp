#include "Character.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Character::Character(string jmeno, int vyberclass)
{
    jmeno = jmeno;
    switch (vyberclass)

    {
    case 1:
        maxZivoty = 300;
        aktualniZivoty = 300;
        maxMana = 150;
        aktualniMana = 50;
        zlato = 0;
        level = 1;
        zkusenosti = 0;
        utok = 10;
        Schopnost = 3;
        break;
    case 2:
        maxZivoty = 100;
        aktualniZivoty = 100;
        maxMana = 50;
        aktualniMana = 50;
        zlato = 0;
        level = 1;
        zkusenosti = 0;
        utok = 10;
        Schopnost = 3;
        break;
    case 3:
        maxZivoty = 100;
        aktualniZivoty = 100;
        maxMana = 50;
        aktualniMana = 50;
        zlato = 0;
        level = 1;
        zkusenosti = 0;
        utok = 10;
        Schopnost = 3;
        break;
    case 4:
        maxZivoty = 100;
        aktualniZivoty = 100;
        maxMana = 50;
        aktualniMana = 50;
        zlato = 0;
        level = 1;
        zkusenosti = 0;
        utok = 10;
        Schopnost = 3;
    default:
        break;
    }

}
void Character::zakladniutok(Monster& monster)
{
    cout << jmeno << " za�to�il na " << monster.jmeno << " a zp�sobil mu " << utok << " po�kozen�!" << endl;
    monster.aktualniZivoty -= utok;
    if (monster.aktualniZivoty <= 0)
    {
        cout << monster.jmeno << " byl pora�en!" << endl;
        monster.aktualniZivoty = 0;
    }
    else
    {
        cout << monster.jmeno << " m� te� " << monster.aktualniZivoty << " �ivot�." << endl;
    }
}

void Character::critical(Monster& monster)
{
    monster.aktualniZivoty -= utok * 1.80;
    aktualniMana -= 10;
    cout << jmeno << " za�to�il na " << monster.jmeno << " a zp�sobil mu " << utok << " po�kozen�!" << endl;
    
}
    
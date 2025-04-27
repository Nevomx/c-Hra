#include "Character.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Character::Character(string jmeno, int vyberclass)
{
    this->jmeno = jmeno;
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
    cout << jmeno << " zaútoèil na " << monster.jmeno << " a zpùsobil mu " << utok << " poškození!" << endl;
    monster.aktualniZivoty -= utok;
    if (monster.aktualniZivoty <= 0)
    {
        cout << monster.jmeno << " byl poražen!" << endl;
        monster.aktualniZivoty = 0;
    }
    else
    {
        cout << monster.jmeno << " má teï " << monster.aktualniZivoty << " životù." << endl;
    }
}

void Character::critical(Monster& monster)
{
    monster.aktualniZivoty -= utok * 1.80;
    aktualniMana -= 10;
    cout << jmeno << " zaútoèil na " << monster.jmeno << " a zpùsobil mu " << utok << " poškození!" << endl;
    
}
void Character::zobrazStav()
{
    cout << "-----------------------------" << endl;
    cout << "Stav hrace: " << jmeno << endl;
    cout << "Zivoty: " << aktualniZivoty << "/" << maxZivoty << endl;
    cout << "Mana: " << aktualniMana << "/" << maxMana << endl;
    cout << "Zlato: " << zlato << endl;
    cout << "Level: " << level << endl;
    cout << "Zkusenosti: " << zkusenosti << endl;
    cout << "-----------------------------" << endl;
}
void Character::hodsekerou()
{
	
}
void Character::provestah(Monster& monster)
{
    int vyberutoku;
    bool tah = true;

    cout << "vyber si utok\n";
    cout << "1. Zakladni utok\n";
    cout << "2. Kriticky utok\n";
    cout << "4 stav\n";

    while (tah)
    {
		cin >> vyberutoku;
        switch (vyberutoku)
        {
        case 1:
            zakladniutok(monster);
            tah = false;
            break;
        case 2:
            critical(monster);
            tah = false;
            break;
        case 3:
            // Místo pro další logiku
            break;
        case 4:
            zobrazStav();
            break;
        default:
            cout << "neplatny utok" << endl;
            break;
        }
    }
}
void Character::KonecHry()
{
    if  (aktualniZivoty <= 0)
    {
        cout << "Zemøel jsi!" << endl;
        cout << "Konec hry" << endl;
        exit(0);
    }


}


    
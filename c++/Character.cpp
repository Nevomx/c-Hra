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
    int damage = utok * 1.80;
    monster.aktualniZivoty -= damage;
    aktualniMana -= 10;
    cout << jmeno << " zaútoèil na " << monster.jmeno << " a zpùsobil mu " << damage << " poškození!" << endl;
    
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
void Character::hodsekerou(Monster& monster, Monster* monster1 = nullptr, Monster* monster2 = nullptr)
{
    if (aktualniMana >= 15) // Spotøeba many
    {
        int damage = utok * 1.5; // Plošné poškození
        monster.aktualniZivoty -= damage;
        cout << jmeno << " hodil sekerou na " << monster.jmeno << " a zpùsobil mu " << damage << " poškození!" << endl;

        if (monster1 != nullptr) // Zkontroluje, zda byl pøedán monster1
        {
            monster1->aktualniZivoty -= damage;
            cout << jmeno << " hodil sekerou na " << monster1->jmeno << " a zpùsobil mu " << damage << " poškození!" << endl;
        }

        if (monster2 != nullptr) // Zkontroluje, zda byl pøedán monster2
        {
            monster2->aktualniZivoty -= damage;
            cout << jmeno << " hodil sekerou na " << monster2->jmeno << " a zpùsobil mu " << damage << " poškození!" << endl;
        }

        aktualniMana -= 15; // Snížení many
        cout << "Zbývající mana: " << aktualniMana << endl;
    }
    else
    {
        cout << "Nemáš dost many na použití schopnosti hod sekerou!" << endl;
    }
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
void Character :: checkpoison()
{
    if (poisonTurns> 0)
    {
        aktualniZivoty -= 3;
        poisonTurns--;
        cout << "Hráè je otrávený! Ztrácí 3 HP. Zbývá " << poisonTurns << " kol otravy.\n";
    }
    if (aktualniZivoty <= 0)
    {
        KonecHry();
    }
}

void Character::heal()
{
    int manaCost = 20; 
    int healAmount = 50; 

    if (aktualniMana >= manaCost) // Kontrola, zda má hráè dostatek many
    {
        aktualniMana -= manaCost; // Odeètení many
        aktualniZivoty += healAmount; // Pøidání životù

        if (aktualniZivoty > maxZivoty) // Zajištìní, že životy nepøekroèí maximum
        {
            aktualniZivoty = maxZivoty;
        }

        cout << jmeno << " se vyléèil o " << healAmount << " životù!" << endl;
        cout << "Zbývající životy: " << aktualniZivoty << "/" << maxZivoty << endl;
        cout << "Zbývající mana: " << aktualniMana << "/" << maxMana << endl;
    }
    else
    {
        cout << "Nemáš dost many na léèení!" << endl;
    }
}


    

    
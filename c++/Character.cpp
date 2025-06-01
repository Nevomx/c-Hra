#include "Character.h"
#include "Monster.h"
#include <iostream>
#include <random>
using namespace std;

Character::Character(string jmeno, int vyberclass)
{
    this->jmeno = jmeno;
    this->vyberclass = vyberclass;
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
        maxMana = 100;
        aktualniMana = 100;
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
    int damage = utok * 1.80;
    monster.aktualniZivoty -= damage;
    aktualniMana -= 10;
    cout << jmeno << " za�to�il na " << monster.jmeno << " a zp�sobil mu " << damage << " po�kozen�!" << endl;

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
void Character::hodsekerou(Monster& monster, Monster* monster1 , Monster* monster2)
{
    if (aktualniMana >= 15) // Spot�eba many
    {
        int damage = utok * 1.5; // Plo�n� po�kozen�
        monster.aktualniZivoty -= damage;
        cout << jmeno << " hodil sekerou na " << monster.jmeno << " a zp�sobil mu " << damage << " po�kozen�!" << endl;

        if (monster1 != nullptr) // Zkontroluje, zda byl p�ed�n monster1
        {
            monster1->aktualniZivoty -= damage;
            cout << jmeno << " hodil sekerou na " << monster1->jmeno << " a zp�sobil mu " << damage << " po�kozen�!" << endl;
        }

        if (monster2 != nullptr) // Zkontroluje, zda byl p�ed�n monster2
        {
            monster2->aktualniZivoty -= damage;
            cout << jmeno << " hodil sekerou na " << monster2->jmeno << " a zp�sobil mu " << damage << " po�kozen�!" << endl;
        }
        
        aktualniMana -= 15; // Sn�en� many
        cout << "Zb�vaj�c� mana: " << this->aktualniMana << endl;

		
    }
    else
    {
        cout << "Nem� dost many na pou�it� schopnosti hod sekerou!" << endl;
    }
}

void Character::Shield()
{
    int manaCost = 15; // Spot�eba many
    int shieldDuration = 2; // D�lka trv�n� �t�tu v kolech

    if (aktualniMana >= manaCost) // Kontrola, zda m� hr�� dostatek many
    {
        aktualniMana -= manaCost; // Ode�ten� many
        shieldTurns = shieldDuration; // Nastaven� trv�n� �t�tu

        cout << jmeno << " aktivoval Svat� �t�t! P��choz� po�kozen� bude sn�eno o 50 % na " << shieldDuration << " kola." << endl;
           
    }
    else
    {
        cout << "Nem� dost many na Svat� �t�t!" << endl;
    }
}







void Character::provestah(Monster& monster, Monster* monster1, Monster* monster2)
{
    int vyberutoku;
    bool tah = true;
    bool dalsiTah = true; // Prom�nn� pro kontrolu dal��ho tahu
    

    while (tah)
    {
        
        switch (vyberclass)
        {
        case 1:
            cout << "Vyber si utok:\n";
            cout << "1. Zakladni utok\n";
            cout << "2. Kriticky utok\n";
            cout << "3. Hod sekerou\n";
            cout << "4. Heal\n";
            cout << "5. Zobrazit stav\n";
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
                hodsekerou(monster, monster1, monster2);
                tah = false;
                break;
            case 4:
                heal();
                tah = false;
                break;
            case 5:
                zobrazStav();
            default:
                cout << "Neplatny utok" << endl;
                break;
            }
            break;

        case 2:
            cout << "Vyber si utok:\n";
            cout << "1. Zakladni utok\n";
            cout << "2. Kriticky utok\n";
            cout << "3. Svat� �t�t\n";
            cout << "4. Heal\n";
            cout << "5. Zobrazit stav\n";
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
                Shield();
                tah = false;
                break;
            case 4:
                heal();
                tah = false;
                break;
            case 5:
                zobrazStav();
            default:
                cout << "Neplatny utok" << endl;
                break;
            }
            break;
            

        case 3:
            
            while (dalsiTah) // Cyklus pro Assassinovy tahy
            {
                cout << "Vyber si utok:\n";
                cout << "1. Zakladni utok\n";
                cout << "2. Kriticky utok\n";
                cout << "3. Heal\n";
                cout << "4. Zobrazit stav\n";
                cin >> vyberutoku;

                switch (vyberutoku)
                {
                case 1:
                    zakladniutok(monster);

                    break;
                case 2:
                    critical(monster);
                    break;
                case 3:
                    heal();
                    break;
                case 4:
                    zobrazStav();
                    break;
                default:
                    cout << "Neplatny utok" << endl;
                    break;
                  
                }

                // Pasivn� �ance na dal�� tah pro Assassina
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> distrib(1, 100); // Rozsah 1-100

                int chance = distrib(gen); // Generov�n� n�hodn�ho ��sla
                if (chance <= 20) // �ance na dal�� tah
                {
                    cout << jmeno << " m� �anci na dal�� tah!" << endl;
                    continue; // Umo�n� hr��i znovu si vybrat akci
                }
                else
                {
                    // Pokud �ance nevyjde, ukon�� cyklus
                    dalsiTah = false;
                    tah = false;
                }

               
            }
            break;
            
           
            

        case 4:
            cout << "Vyber si utok:\n";
            cout << "1. Zakladni utok\n";
            cout << "2. Kriticky utok\n";
            cout << "3. U�it� vlastn�ho produktu(boost na zlato a xp za 50many)\n";
            cout << "3. Heal\n";
            cout << "4. Zobrazit stav\n";
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
                aktivujBonus();
                tah = false;
                break;
            case 4:
                heal();
                tah = false;
                break;
            case 5:
                zobrazStav();
            default:
                cout << "Neplatny utok" << endl;
                break;
                
            }
            break;

        default:
            cout << "Neplatna trida postavy.\n";
            tah = false;
            break;
        }
        
    }
    
}

void Character::KonecHry()
{
    if  (aktualniZivoty <= 0)
    {
        cout << "Zem�el jsi!" << endl;
        cout << "Konec hry" << endl;
        exit(0);
    }
}
void Character::aktivujBonus()
{
    int manaCost = 75; // Cena za aktivaci bonusu

    if (aktualniMana >= manaCost) // Kontrola, zda m� hr�� dostatek many
    {
        aktualniMana -= manaCost; // Ode�ten� many
        Schopnost = 1; // Nastaven� bonusu (1 = aktivn�)
        cout << jmeno << " aktivoval bonus na zdvojn�soben� p��jmu XP a zlata!" << endl;
        cout << "Zb�vaj�c� mana: " << aktualniMana << "/" << maxMana << endl;
    }
    else
    {
        cout << "Nem� dost many na aktivaci bonusu!" << endl;
    }
}
void Character :: checkpoison()
{
    if (poisonTurns> 0)
    {
        aktualniZivoty -= 3;
        poisonTurns--;
        cout << "Hr�� je otr�ven�! Ztr�c� 3 HP. Zb�v� " << poisonTurns << " kol otravy.\n";
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

    if (aktualniMana >= manaCost) // Kontrola, zda m� hr�� dostatek many
    {
        aktualniMana -= manaCost; // Ode�ten� many
        aktualniZivoty += healAmount; // P�id�n� �ivot�

        if (aktualniZivoty > maxZivoty) // Zaji�t�n�, �e �ivoty nep�ekro�� maximum
        {
            aktualniZivoty = maxZivoty;
        }

        cout << jmeno << " se vyl��il o " << healAmount << " �ivot�!" << endl;
        cout << "Zb�vaj�c� �ivoty: " << aktualniZivoty << "/" << maxZivoty << endl;
        cout << "Zb�vaj�c� mana: " << aktualniMana << "/" << maxMana << endl;
    }
    else
    {
        cout << "Nem� dost many na l��en�!" << endl;
    }
}
//switch
void Character::navstivVesnici()
{
    int volba;
    bool veVesnici = true;
    while (veVesnici)
    {
        cout << "\n--- Vesnice ---\n";
        cout << "Tve zlato: " << zlato << endl;
        cout << "1. Koupit 50 zivotu (cena: 20 zlata)\n";
        cout << "2. doplnit manu (cena: 15 zlata)\n";
        cout << "3. Koupit posilovac utoku (+5 damage, cena: 50 zlata)\n";
        cout << "4. Odejit z vesnice\n";
        cout << "Vyber akci: ";
        cin >> volba;

        switch (volba)
        {
        case 1:
            if (zlato >= 20)
            {
                aktualniZivoty += 50;
                if (aktualniZivoty > maxZivoty) aktualniZivoty = maxZivoty;
                zlato -= 20;
                cout << "Koupil jsi 50 �ivot�. Aktualn� �ivoty: " << aktualniZivoty << endl;
            }
            else
            {
                cout << "Nem� dost zlata!" << endl;
            }
            break;
        case 2:
            if (zlato >= 15)
            {
                aktualniMana += 1000;
                if (aktualniMana > maxMana) aktualniMana = maxMana;
                zlato -= 15;
                cout << "m� " << aktualniMana <<" ze "<< maxMana << " many" <<  endl;
            }
            else
            {
                cout << "Nem� dost zlata!" << endl;
            }
            break;
        case 3:
            if (zlato >= 50)
            {
                utok += 5;
                zlato -= 50;
                cout << "Koupil jsi posilovac utoku! Aktualni utok: " << utok << endl;
            }
            else
            {
                cout << "Nem� dost zlata!" << endl;
            }
            break;
        case 4:
            veVesnici = false;
            cout << "Odchazis z vesnice.\n";
            break;
        default:
            cout << "Neplatna volba!" << endl;
            break;
        }
    }
}
    

    
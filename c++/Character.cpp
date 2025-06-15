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
        maxZivoty = 100;
        aktualniZivoty = 100;
        maxMana = 100;
        aktualniMana = 100;
        zlato = 0;
        level = 1;
        zkusenosti = 0;
        utok = 10;
        Schopnost = 3;
        
        break;
    case 2:
        maxZivoty = 100;
        aktualniZivoty = 100;
        maxMana = 100;
        aktualniMana = 100;
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
    cout << jmeno << " zaútoèil na " << monster.jmeno << " a zpùsobil mu " << utok << " poškození!" << endl;
    monster.aktualniZivoty -= utok;
    if (monster.aktualniZivoty <= 0)
    {
        cout << monster.jmeno << " byl poražen!" << endl;
        monster.aktualniZivoty = 0;
        porazeni = true;
    }
    else
    {
        cout << monster.jmeno << " má teï " << monster.aktualniZivoty << " životù." << endl;
    }
    tahproveden = true;

}

void Character::critical(Monster& monster)
{
    int damage = utok * 1.80;

    if (aktualniMana >= 10)
    {
        monster.aktualniZivoty -= damage;
        aktualniMana -= 10;
        cout << jmeno << " zaútoèil na " << monster.jmeno << " a zpùsobil mu " << damage << " poškození!" << endl;
        cout << jmeno << " má " << aktualniMana << "/" << maxMana << " Many\n";
    }
    else
    {
        cout << "nemas dostatek many \n";
    }
    
    if (monster.aktualniZivoty <= 0)
    {
        cout << monster.jmeno << " byl poražen!" << endl;
        monster.aktualniZivoty = 0;
        porazeni = true;
    }
    else
    {
        cout << monster.jmeno << " má teï " << monster.aktualniZivoty << " životù." << endl;
    }
    tahproveden = true;

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
    if (aktualniMana >= 15) // Spotøeba many
    {
        int damage = utok * 1.5; // Plošné poškození
        monster.aktualniZivoty -= damage;
        cout << jmeno << " hodil sekerou na " << monster.jmeno << " a zpùsobil mu " << damage << " poškození!" << endl;
        cout << monster.jmeno << " má teï " << monster.aktualniZivoty << " životù." << endl;
       

        if (monster1 != nullptr) // Zkontroluje, zda byl pøedán monster1
        {
            monster1->aktualniZivoty -= damage;
            cout << jmeno << " hodil sekerou na " << monster1->jmeno << " a zpùsobil mu " << damage << " poškození!" << endl;
            cout << monster.jmeno << " má teï " << monster.aktualniZivoty << " životù." << endl;
        }

        if (monster2 != nullptr) // Zkontroluje, zda byl pøedán monster2
        {
            monster2->aktualniZivoty -= damage;
            cout << jmeno << " hodil sekerou na " << monster2->jmeno << " a zpùsobil mu " << damage << " poškození!" << endl;
            cout << monster.jmeno << " má teï " << monster.aktualniZivoty << " životù." << endl;
        }
        
        aktualniMana -= 15; // Snížení many
        cout << "Zbývající mana: " << this->aktualniMana << endl;
        tahproveden = true;

		
    }
    else
    {
        cout << "Nemáš dost many na použití schopnosti hod sekerou!" << endl;
    }
}

void Character::Shield()
{
    int manaCost = 10; // Spotøeba many
    int shieldDuration = 3; // Délka trvání štítu v kolech

    if (aktualniMana >= manaCost) // Kontrola, zda má hráè dostatek many
    {
        aktualniMana -= manaCost; // Odeètení many
        shieldTurns = shieldDuration; // Nastavení trvání štítu

        cout << jmeno << " aktivoval Svatý Štít! Pøíchozí poškození bude sníženo o 50 % na " << shieldDuration << " kola." << endl;
        tahproveden = true;
           
    }
    else
    {
        cout << "Nemáš dost many na Svatý Štít!" << endl;
    }
}







void Character::provestah(Monster& monster, Monster* monster1, Monster* monster2)
{
    int vyberutoku;
    bool tah = true;
    bool dalsiTah = true; // Promìnná pro kontrolu dalšího tahu
    

    while (tah)
    {
        
        switch (vyberclass)
        {
        case 1:
            cout << "Vyber si utok:\n";
            cout << "1. Zakladni utok\n";
            cout << "2. Kriticky utok (10 mana)\n";
            cout << "3. Hod sekerou (15 mana)\n";
            cout << "4. Heal (20 mana)\n";
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
            cout << "2. Kriticky utok (10 mana)\n";
            cout << "3. Svatý štít (10 mana)\n";
            cout << "4. Heal (20 mana)\n";
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
                cout << "2. Kriticky utok (10 mana)\n";
                cout << "3. Heal (20 manaú\n";
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

                // Pasivní šance na další tah pro Assassina
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> distrib(1, 100); // Rozsah 1-100

                int chance = distrib(gen); // Generování náhodného èísla
                if (chance <= 20) // šance na další tah
                {
                    cout << jmeno << " má šanci na další tah!" << endl;
                    continue; // Umožní hráèi znovu si vybrat akci
                }
                else
                {
                    // Pokud šance nevyjde, ukonèí cyklus
                    dalsiTah = false;
                    tah = false;
                }

               
            }
            break;
            
           
            

        case 4:
            cout << "Vyber si utok:\n";
            cout << "1. Zakladni utok\n";
            cout << "2. Kriticky utok (10 mana)\n";
            cout << "3. Užití vlastního produktu(boost na zlato a xp za 75many)\n";
            cout << "4. Heal (20 mana)\n";
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
        cout << "Zemøel jsi!" << endl;
        cout << "Konec hry" << endl;
        exit(0);
    }
}
void Character::aktivujBonus()
{
    int manaCost = 75; // Cena za aktivaci bonusu

    if (aktualniMana >= manaCost) // Kontrola, zda má hráè dostatek many
    {
        aktualniMana -= manaCost; // Odeètení many
        Schopnost = 1; // Nastavení bonusu (1 = aktivní)
        cout << jmeno << " aktivoval bonus na zdvojnásobení pøíjmu XP a zlata!" << endl;
        cout << "Zbývající mana: " << aktualniMana << "/" << maxMana << endl;
        tahproveden = true;
    }
    else
    {
        cout << "Nemáš dost many na aktivaci bonusu!" << endl;
    }
}
void Character :: checkpoison()
{
    if (poisonTurns> 0)
    {
        aktualniZivoty -= 3;
        poisonTurns--;
        cout << "Hráè je otrávený! Ztrácí 3 HP. Zbývá " << poisonTurns << " kol otravy.\n";
        cout << "Máš " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";
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
        tahproveden = true;
    }
    else
    {
        cout << "Nemáš dost many na léèení!" << endl;
    }
}
//switch
void Character::navstivVesnici()
{
    
    int volba;
    bool veVesnici = true;


    if (Schopnost == 1)
    {
        Schopnost = 0;
        cout << "deaktivoval se bonus\n\n";
    }
    while (veVesnici)
    {
        cout << "\n--- Vesnice ---\n";
        cout << "Tve zlato: " << zlato << endl;
        cout << "1. dopnit zivoty (cena: 3 zlata)\n";
        cout << "2. doplnit manu (cena: 4 zlata)\n";
        cout << "3. Koupit posilovac utoku (+5 damage, cena: 8 zlata)\n";
        cout << "4. Odejit z vesnice\n";
        cout << "Vyber akci: ";
        cin >> volba;

        switch (volba)
        {
        case 1:
            if (zlato >= 3)
            {
                aktualniZivoty += 1000;
                if (aktualniZivoty > maxZivoty) aktualniZivoty = maxZivoty;
                zlato -= 3;
                cout << "dopnil jsi zivoty. Aktualní životy : " << aktualniZivoty << endl;
            }
            else
            {
                cout << "Nemáš dost zlata!" << endl;
            }
            break;
        case 2:
            if (zlato >= 4)
            {
                aktualniMana += 1000;
                if (aktualniMana > maxMana) aktualniMana = maxMana;
                zlato -= 4;
                cout << "máš " << aktualniMana <<" ze "<< maxMana << " many" <<  endl;
            }
            else
            {
                cout << "Nemáš dost zlata!" << endl;
            }
            break;
        case 3:
            if (zlato >= 8)
            {
                utok += 5;
                zlato -= 8;
                cout << "Koupil jsi posilovac utoku! Aktualni utok: " << utok << endl;
            }
            else
            {
                cout << "Nemáš dost zlata!" << endl;
            }
            break;
        case 4:
            veVesnici = false;
            cout << "Odchazis z vesnice.\n\n";
            break;
        default:
            cout << "Neplatna volba!" << endl;
            break;
        }
    }
}

void Character::levelUp()
{
    while (zkusenosti >= 100)
    {
        level++;
        zkusenosti -= 100;
        maxZivoty += 20;
        maxMana += 10;
        utok += 2;
        aktualniZivoty = 20;
        aktualniMana = 10;
        cout << "LEVEL UP! " << jmeno << " je nyní na úrovni " << level << "!" << endl;
        cout << "Maximální životy: " << maxZivoty << ", maximální mana: " << maxMana << ", útok: " << utok << endl << endl;
    }
}

    
// c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>  
#include <random>
using namespace std; 
#include "Character.h"
#include "Monster.h"
void KonecHry()
{
	cout << "Konec hry" << endl;
	exit(0);
}




int main()
{
  
   

    
	int vyberutoku;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 3);
    int random;

    setlocale(LC_ALL, "");
	int potvrzeni = 1,
		vyberclass, potvrzeniclass = 1;
	string jmeno;
    

    cout << "vytej v me hre\n";
	cout << "Zadej jmeno: ";
	cin >> jmeno;
    
    while (potvrzeni == 1)
    {
        cout << "vyber si classu\n";
        cout << "1. Berserker - Vysoký útok, nízká obrana\n";
        cout << "2. Paladin - Vyvážený, s bonusem na obranu\n";
        cout << "3. Mage - Slabé tělo, silná magie\n";
        cout << "4. Rogue - Rychlý a nečekaný útočník\n";
        cout << "Zadej číslo class: ";
		cin >> vyberclass;
		cout << "Potvrdit výběr? (1 - ano, 0 - ne): ";
		cin >> potvrzeniclass;
		if (potvrzeniclass == 1)
		{
			cout << "Vybrali jste class: " << vyberclass << endl;
			potvrzeni = 0;
			 
		}
		else
		{
			cout << "Zadejte znovu class" << endl;
		}
    }

    Character characterhrac(jmeno, vyberclass);

	cout  << " je " << characterhrac.maxZivoty << " zivotu a " << characterhrac.maxMana << " many" << endl;


    Monster setkani1(random= distrib(gen));

	setkani1.attack(characterhrac);

    //encounter
    while (true)
    {
        

        if (characterhrac.poisonTurns > 0) 
		{
            characterhrac.aktualniZivoty -= 3;
            characterhrac.poisonTurns--;
            cout << "Hráč je otrávený! Ztrácí 3 HP. Zbývá " << characterhrac.poisonTurns << " kol otravy.\n";
        }
		if (characterhrac.aktualniZivoty <= 0)
        {
			KonecHry();
		}
		cout << "vyber si utok\n";
		cout << "1. Zakladni utok\n";
		cout << "2. Kriticky utok\n";


        
        cin >> vyberutoku;

        switch (vyberutoku)
        {
        case 1:
            characterhrac.zakladniutok(setkani1);

            setkani1.attack(characterhrac);
            break;
        case 2:
			characterhrac.critical(setkani1);

            break;
        case 3:

            break;
       
            default:
                cout << "neplatny utok" << endl;
                break; 
            
        }
		cout << "Monster " << setkani1.jmeno << " má teď " << setkani1.aktualniZivoty << " životů." << endl;
        



        if (characterhrac.aktualniZivoty <= 0)
        {
            KonecHry();
        }

		


       
    }
}
    

    








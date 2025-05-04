// c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <random>
#include <string>  
using namespace std; 
#include "Character.h"
#include "Monster.h"
using std::cin;
using std::cout;
using std::endl;





void porazenimonstra(Monster& setkani1, Character& characterhrac)
{
	if (setkani1.aktualniZivoty <= 0)
	{
		cout << "Monster " << setkani1.jmeno << " byl poražen!" << endl;
		setkani1.aktualniZivoty = 0;
		cout << "Získal jsi 10 zlata a 10xp" << endl;
		characterhrac.zlato += 10;
		characterhrac.zkusenosti += 10;
	}
}







int main()
{
  
	string jmeno;

	

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 3);
    int random;

    setlocale(LC_ALL, "");
	int potvrzeni = 1,
		vyberclass, potvrzeniclass = 1;
	
    

    cout << "vitej v me hre\n";
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


	cout  << " je " << characterhrac.maxZivoty << " zivotu a " << characterhrac.maxMana <<  " many" << endl;



Monster setkani1(random= distrib(gen));
	cout << "Potkal jsi " << setkani1.jmeno << endl;
	cout << "ma " << setkani1.maxZivoty << " zivotu a " << setkani1.utok << " utok" << endl;

    //encounter
	while (true)
	{
		characterhrac.checkpoison();

		characterhrac.provestah(setkani1);

		setkani1.attack(characterhrac);

		characterhrac.KonecHry();



		porazenimonstra(setkani1, characterhrac);


		characterhrac.hodsekerou(setkani1);
        
       

    }

    





























}
   

    








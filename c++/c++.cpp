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

        // Základní odměna
        int xpReward = 10;
        int goldReward = 0;

        // Náhodná šance na zlato
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, 100); // Rozsah 1-100

        int chance = distrib(gen); // Generování náhodného čísla
        if (chance <= 50) // 50% šance na zlato
        {
            uniform_int_distribution<> goldDistrib(5, 20); // Rozsah zlata 5-20
            goldReward = goldDistrib(gen);
        }

        // Kontrola, zda je aktivní bonus
        if (characterhrac.Schopnost == 1) // Bonus aktivní
        {
            xpReward *= 2; // Zdvojnásobení XP
            goldReward *= 2; // Zdvojnásobení zlata
            characterhrac.Schopnost = 0; // Deaktivace bonusu po použití
            cout << "Bonus aktivní! Odměny zdvojnásobeny!" << endl;
        }

        // Přidání odměn hráči
        characterhrac.zkusenosti += xpReward;
        characterhrac.zlato += goldReward;

        // Výstup odměn
        cout << "Získal jsi " << xpReward << " XP!" << endl;
        if (goldReward > 0)
        {
            cout << "Získal jsi " << goldReward << " zlata!" << endl;
        }
        else
        {
            cout << " beze zlata" << endl;
        }
    }
}







int main()
{

	string test = "kokot";

	string* test2 = &test;
  
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
        cout << "1. Berserker - Vysoký útok, nízká obrana, area attack\n";
        cout << "2. Paladin - Vyvážený, s bonusem na obranu\n";
        cout << "3. Assassin - Šance na dvojitý tah\n";
        cout << "4. Walter Bílý - Podnikatel\n";
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


		
        
       

    }

    





























}
   

    








// c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>  
using namespace std; 

class Character {
    public:
        string jmeno;
        int maxZivoty;
        int aktualniZivoty;
        int maxMana;
        int aktualniMana;
        int zlato;
        int level;
        int zkusenosti;
        int utok;
		int Schopnost;


        
        Character(string jmeno, int vyberclass)
        {
            jmeno = jmeno;
            switch (vyberclass)

            {
            case 1:
				maxZivoty = 300;
				aktualniZivoty = 100;
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
};



int main()
{
	int potvrzeni = 1,
		vyberclass, potvrzeniclass = 1;
	string jmeno;
    

    cout << "vytej v me hre";
	cout << "Zadej jmeno: ";
	cin >> jmeno;
    
    while (potvrzeni == 1)
    {
        cout << "vyber si classu\n";
        cout << "1. Berserker - Vysoký útok, nízká obrana\n";
        cout << "2. Paladin - Vyvážený, s bonusem na obranu\n";
        cout << "3. Mage - Slabé tìlo, silná magie\n";
        cout << "4. Rogue - Rychlý a neèekaný útoèník\n";
        cout << "Zadej èíslo class: ";
		cin >> vyberclass;
		cout << "Potvrdit výbìr? (1 - ano, 0 - ne): ";
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
    



}



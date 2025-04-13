// c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>  
#include <random>
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
        int poisonTurns = 0;  // kolik kol je otrávený


        
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
class Monster
{
    public:
        int maxZivoty;
        int aktualniZivoty;
        int utok;
		string jmeno;
        
        Monster(int monster)
        {
			
            switch (monster)
            {
                case 1:
				    jmeno = "zombie";
                    maxZivoty = 100;
                    aktualniZivoty = 100;
                    utok = 10;
                    break;
            
                case 2:
				    jmeno = "skeleton";
				    maxZivoty = 100;
                    aktualniZivoty = 10;
				    utok = 10;
                    break;
			    case 3:
				    jmeno = "chicken jockey";
				    maxZivoty = 10;
				    aktualniZivoty = 100;
				    utok = 15;
				    break;
                



                
            }

        }

        void attack(Character characterhrac)
        {
            cout << "Monster " << jmeno << " zaútočil na " << characterhrac.jmeno << " a způsobil mu " << utok << " poškození!" << endl;
            characterhrac.aktualniZivoty -= utok;
            cout << characterhrac.jmeno << " má teď " << characterhrac.aktualniZivoty << " životů." << endl;
        }
        void poisonarrow(Character characterhrac, int kolo)
        {
            if (jmeno == "skeleton")
            {
                characterhrac.aktualniZivoty -= 7;
                characterhrac.poisonTurns = 3;
                

            }
            else
                cout << "nefunguje ty curaku";
        }
		
};

void KonecHry()
{
	cout << "Konec hry" << endl;
	exit(0);
}


int main()
{
	
    int kolo;
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
			
		}
    //cin >> utok;


        if (characterhrac.aktualniZivoty <= 0)
        {
            KonecHry();
        }




        kolo++;

    }
    

    








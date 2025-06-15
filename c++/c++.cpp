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
        int xpReward = 25;
        int goldReward = 0;

        // Náhodná šance na zlato
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, 100); // Rozsah 1-100

        int chance = distrib(gen); // Generování náhodného čísla
        if (setkani1.jmeno == "Miniboss")
        {
            goldReward = 40;
            characterhrac.zlato += goldReward;
            cout << "Získáváš 35 zlata";

        }
        else
        {
            if (chance <= 50) // 50% šance na zlato
            {
                uniform_int_distribution<> goldDistrib(5, 27); // Rozsah zlata 5-20
                goldReward = goldDistrib(gen);
            }
        }


        // Kontrola, zda je aktivní bonus
        if (characterhrac.Schopnost == 1) // Bonus aktivní
        {
            xpReward *= 2; // Zdvojnásobení XP
            goldReward *= 2; // Zdvojnásobení zlata
          
            cout << "Bonus aktivní! Odměny zdvojnásobeny!" << endl;
        }

        // Přidání odměn hráči
        characterhrac.zkusenosti += xpReward;
        characterhrac.zlato += goldReward;

        // Výstup odměn
        cout << "Získal jsi " << xpReward << " XP!" << endl;
        if (goldReward > 0)
        {
            cout << "Získal jsi " << goldReward << " zlata!\n" << endl;
        }
        else
        {
            cout << " beze zlata\n" << endl;
        }

        characterhrac.levelUp();
        characterhrac.porazeni = false;
    }
}

void vypisClassInfo()
{
    cout << "\n--- útok ---\n";
    cout << "Všechny classy mají na výběr 4 možnosti tahu\n";
    cout << "1. Záklandí útok\n";
    cout << "2. Kritický útok\n";
    cout << "3. Speciální schponost\n";
    cout << "4. Heal\n";
    cout << "----------------- class -----------------------";
    cout << endl << "1. Berserker\n";
    cout << "   Útok: 10\n";
    cout << "   Maximální životy: 100\n";
    cout << "   Maximálná mana: 100\n";
    cout << "   Speciální schopnost je area damage do všech monster. S základním poškozením x 50%. Cena je 15 many.\n\n";
    cout << "2. Paladin\n";
    cout << "   Útok: 10\n";
    cout << "   Maximální životy: 100 \n";
    cout << "   Maximálná mana: 100\n";
    cout << "   Speciální schopnost je posvátný štít, který redukuje příchozí poškození o 50% po dobu 2 kol za cenu 15 many. \n\n";
    cout << "3. Assassin\n";
    cout << "   Útok: 10\n";
    cout << "   Maximální životy: 100\n";
    cout << "   Maximálná mana: 100\n";
    cout << "   Speciální schponost je pasivnka, která má 20% šanci na aktivaci a udělá to ,že má hráč tah navíc. \n\n";
    cout << "4. Walter Bílý\n";
    cout << "   Útok: 10\n";
    cout << "   Maximální životy: 100\n";
    cout << "   Maximálná mana: 100\n";
    cout << "   Speciálí schopnost je užití vlastního produktu, který dá bonus na 2x větší příjem zlata a xp za cenu 75 many. Bonus bude aktivní dokud hráč nedojde do vesnice.\n\n ";
    cout << "Ve vesnici můžeš doplnit životy, manu a případně i koupit item, který zvětší poškození proti monstrům.\n\n";
    cout << "----------------- Boss Fight -----------------------\n";
    cout << " Když dojdeš až na konec tak potkáš bosse Quadraterru a nebude to nic lehkého.\n";
    cout << " Nejdříve Quadraterra zvolí element a pak dostaneš na výber jestli zvolíš místo nebo item.\n";
    cout << " Pro lespší požitek ze hry tě nechám přijít co jaka kombinace dělá :)\n";


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
        cout << "5. Zobrazit podrobné informace o třídách\n";
        cout << "Zadej číslo class: ";
        cin >> vyberclass;
        if (vyberclass == 5)
        {
            vypisClassInfo();
            // Znovu se zeptá na výběr třídy
            continue;
        }
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


    cout << " má " << characterhrac.maxZivoty << " zivotu a " << characterhrac.maxMana << " many\n" << endl;



    Monster setkani1(random = distrib(gen));
    cout << "Potkal jsi " << setkani1.jmeno << endl;
    cout << "ma " << setkani1.maxZivoty << " zivotu a " << setkani1.utok << " utok" << endl;

    //encounter




    while (!(setkani1.aktualniZivoty <= 0))
    {
        characterhrac.tahproveden = false;
        characterhrac.checkpoison();

        while (characterhrac.tahproveden == false)
        {
            characterhrac.provestah(setkani1);
        }

        if (setkani1.aktualniZivoty > 0)
        {
            setkani1.encouter(characterhrac);
        }

        characterhrac.KonecHry();



        porazenimonstra(setkani1, characterhrac);

    }
    Monster setkani2(random = distrib(gen));
    cout << "Potkal jsi " << setkani2.jmeno << endl;
    cout << "ma " << setkani2.maxZivoty << " zivotu a " << setkani2.utok << " utok" << endl;

    while (!(setkani2.aktualniZivoty <= 0))
    {
        characterhrac.tahproveden = false;

        characterhrac.checkpoison();

        while (characterhrac.tahproveden == false)
        {
            characterhrac.provestah(setkani2);
        }

        if (setkani2.aktualniZivoty > 0)
        {
            setkani2.encouter(characterhrac);
        }



        characterhrac.KonecHry();



        porazenimonstra(setkani2, characterhrac);

    }

    

    characterhrac.navstivVesnici();





    


    Monster setkani3(random = distrib(gen));
    cout << "Potkal jsi " << setkani3.jmeno << endl;
    cout << "ma " << setkani3.maxZivoty << " zivotu a " << setkani3.utok << " utok" << endl;

    while (!(setkani3.aktualniZivoty <= 0))
    {
        characterhrac.tahproveden = false;
        characterhrac.checkpoison();

        while (characterhrac.tahproveden == false)
        {
            characterhrac.provestah(setkani3);
        }



        if (setkani3.aktualniZivoty > 0)
        {
            setkani3.encouter(characterhrac);
        }

        characterhrac.KonecHry();




        porazenimonstra(setkani3, characterhrac);

    }




    Monster setkani4(random = distrib(gen));
    Monster setkani5(random = distrib(gen));
    cout << "Potkal jsi " << setkani4.jmeno << endl;
    cout << "ma " << setkani4.maxZivoty << " zivotu a " << setkani4.utok << " utok" << endl;
    cout << "Potkal jsi " << setkani5.jmeno << endl;
    cout << "ma " << setkani5.maxZivoty << " zivotu a " << setkani5.utok << " utok" << endl;

    while (!(setkani4.aktualniZivoty <= 0 && setkani5.aktualniZivoty <= 0))
    {
        characterhrac.checkpoison();

        int rozhod;
        cout << " vyber si na koho chceš zaútočit\n";
        cout << "1. je " << setkani4.jmeno << " a 2. je " << setkani5.jmeno << endl;
        cin >> rozhod;

        switch (rozhod)
        {
        case 1:
            characterhrac.provestah(setkani4, &setkani5);

            break;
        case 2:
            characterhrac.provestah(setkani5, &setkani4);

            break;
        }




        if (setkani4.aktualniZivoty > 0)
        {
            setkani4.encouter(characterhrac);
        }

        if (setkani5.aktualniZivoty > 0)
        {
            setkani5.encouter(characterhrac);
        }


        characterhrac.KonecHry();
    }
    porazenimonstra(setkani4, characterhrac);
    porazenimonstra(setkani5, characterhrac);


    characterhrac.navstivVesnici();

    Monster setkani6(random = distrib(gen));
    cout << "Potkal jsi " << setkani6.jmeno << endl;
    cout << "ma " << setkani6.maxZivoty << " zivotu a " << setkani6.utok << " utok" << endl;

    while (!(setkani6.aktualniZivoty <= 0))
    {
        characterhrac.tahproveden = false;
        characterhrac.checkpoison();

        while (characterhrac.tahproveden == false)
        {
            characterhrac.provestah(setkani6);
        }



        if (setkani6.aktualniZivoty > 0)
        {
            setkani6.encouter(characterhrac);
        }

        characterhrac.KonecHry();




        porazenimonstra(setkani6, characterhrac);

    }

    
    Monster setkani7(4);
    cout << "Potkal jsi " << setkani7.jmeno << endl;
    cout << "ma " << setkani7.maxZivoty << " zivotu a " << setkani7.utok << " utok" << endl;

    while (!(setkani7.aktualniZivoty <= 0))
    {
        characterhrac.tahproveden = false;
        characterhrac.checkpoison();

        if (setkani7.aktualniZivoty > 0)
        {
            setkani7.encouter(characterhrac);
        }

        characterhrac.KonecHry();

        while (characterhrac.tahproveden == false)
        {
            characterhrac.provestah(setkani7);
        }

        porazenimonstra(setkani7, characterhrac);

    }

    Monster setkani8(random = distrib(gen));
    cout << "Potkal jsi " << setkani8.jmeno << endl;
    cout << "ma " << setkani8.maxZivoty << " zivotu a " << setkani8.utok << " utok" << endl;

    while (!(setkani8.aktualniZivoty <= 0))
    {
        characterhrac.tahproveden = false;
        characterhrac.checkpoison();

        while (characterhrac.tahproveden == false)
        {
            characterhrac.provestah(setkani8);
        }



        if (setkani8.aktualniZivoty > 0)
        {
            setkani8.encouter(characterhrac);
        }

        characterhrac.KonecHry();




        porazenimonstra(setkani8, characterhrac);

    }

    characterhrac.navstivVesnici();



    Monster setkani9(random = distrib(gen));
    Monster setkani10(random = distrib(gen));
    Monster setkani11(random = distrib(gen));
    cout << "Potkal jsi " << setkani9.jmeno << endl;
    cout << "ma " << setkani9.maxZivoty << " zivotu a " << setkani9.utok << " utok" << endl;
    cout << "Potkal jsi " << setkani10.jmeno << endl;
    cout << "ma " << setkani10.maxZivoty << " zivotu a " << setkani10.utok << " utok" << endl;
    cout << "Potkal jsi " << setkani11.jmeno << endl;
    cout << "ma " << setkani11.maxZivoty << " zivotu a " << setkani11.utok << " utok\n" << endl;


    while (!(setkani9.aktualniZivoty <= 0 && setkani10.aktualniZivoty <= 0 && setkani11.aktualniZivoty <= 0 ))
    {
        characterhrac.checkpoison();

        int rozhod;
        cout << " vyber si na koho chceš zaútočit\n";
        cout << "1. je " << setkani9.jmeno << " 2. je " << setkani10.jmeno << " a 3. je " << setkani11.jmeno << endl;
        cin >> rozhod;

        switch (rozhod)
        {
        case 1:
            characterhrac.provestah(setkani9, &setkani10, &setkani11);

            break;
        case 2:
            characterhrac.provestah(setkani10, &setkani9, &setkani11);

            break;

        case 3:
            characterhrac.provestah(setkani11, &setkani9, &setkani10);

            break;
        }




        if (setkani9.aktualniZivoty > 0)
        {
            setkani9.encouter(characterhrac);
        }

        if (setkani10.aktualniZivoty > 0)
        {
            setkani10.encouter(characterhrac);
        }

        if (setkani11.aktualniZivoty > 0)
        {
            setkani11.encouter(characterhrac);
        }

        



        characterhrac.KonecHry();
    }

    porazenimonstra(setkani9, characterhrac);
    porazenimonstra(setkani10, characterhrac);
    porazenimonstra(setkani11, characterhrac);



    characterhrac.navstivVesnici();





    cout << "Potkáváš bosse Quadraterru\n";
    cout << "Teď jde o všechno\n\n";


    Monster setkaniboss(5);
    while (!(setkaniboss.aktualniZivoty <= 0))
    {
        setkaniboss.encouter(characterhrac);
        characterhrac.KonecHry();

        if (characterhrac.vyruseniUtoku == true)
        {
            characterhrac.vyruseniUtoku = false;
        }
        else
        {

            characterhrac.provestah(setkaniboss);
        }


    }
    cout << "Vyhral jsi";





















}


























       
        






























   

    








#include "Monster.h"
#include "Character.h"
#include <iostream>
#include <random>
using namespace std;

Monster::Monster(int monster)
{
    switch (monster)
    {
    case 1:
        jmeno = "zombie";
        maxZivoty = 50;
        aktualniZivoty = 50;
        utok = 10;
        break;
    case 2:
        jmeno = "skeleton";
        maxZivoty = 50;
        aktualniZivoty = 50;
        utok = 10;
        break;
    case 3:
        jmeno = "chicken jockey";
        maxZivoty = 35;
        aktualniZivoty = 35;
        utok = 15;
        break;
    case 4:
        jmeno = "Miniboss";
        maxZivoty = 180;
        aktualniZivoty = 180;
        utok = 15;
        break;
    case 5:
        jmeno = "Quadraterra";
        maxZivoty = 800;
        aktualniZivoty = 800;
        utok = 18;

    }
}
void Monster::encouter(Character& characterhrac)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100); // Rozsah 1-100

    int chance = distrib(gen); // Generování náhodného èísla







    if (jmeno == "zombie")
    {
        attack(characterhrac);
    }
    else if (jmeno == "skeleton")
    {
        if (chance <= 60)
        {
            poisonarrow(characterhrac);

        }
        else
        {
            attack(characterhrac);
        }
    }
    else if (jmeno == "chicken jockey")
    {
        if (chance <= 60)
        {
            chickenAttack(characterhrac);

            attack(characterhrac);

        }
        else
        {
            attack(characterhrac);
        }
    }
    else if (jmeno == "Miniboss")
    {
        attack(characterhrac);
    }


    else if (jmeno == "Quadraterra")
    {
        BossFight(characterhrac);
        attack(characterhrac);


    }
}

void Monster::attack(Character& characterhrac)
{
    if (characterhrac.shieldTurns > 0)
    {
        int snizenyutok = utok / 2; // Snížení poškození o 50 %
        
        characterhrac.shieldTurns--; // Snížení poètu zbývajících kol štítu
        cout << characterhrac.jmeno << " má aktivní Svatý Štít! Poškození sníženo na " << snizenyutok << "." << endl;
        cout << "zbývá " << characterhrac.shieldTurns << "kol\n";

        cout << "Monster " << jmeno << " zaútoèil na " << characterhrac.jmeno << " a zpùsobil mu " << snizenyutok << " poškození!" << endl;
        characterhrac.aktualniZivoty -= snizenyutok;
        cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";

    }
   
    else
    {
        cout << "Monster " << jmeno << " zaútoèil na " << characterhrac.jmeno << " a zpùsobil mu " << utok << " poškození!" << endl;
        characterhrac.aktualniZivoty -= utok;
        cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
    }
    
    
   
}

void Monster::poisonarrow(Character& characterhrac)
{
    if (characterhrac.shieldTurns > 0)
    {
        int snizenyutok = utok / 2; // Snížení poškození o 50 %
        characterhrac.poisonTurns += 3;
        characterhrac.shieldTurns--; // Snížení poètu zbývajících kol štítu
        cout << characterhrac.jmeno << " má aktivní Svatý Štít! Poškození sníženo na " << snizenyutok << "." << endl;
        cout << "zbývá " << characterhrac.shieldTurns << "kol\n";

        cout << "Monster " << jmeno << " vystøelil jedovatý šíp na " << characterhrac.jmeno << " a zpùsobil mu " << snizenyutok << " poškození!" << endl;
        characterhrac.aktualniZivoty -= snizenyutok;
        cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
    }
    else
    {
        characterhrac.aktualniZivoty -= utok;
        characterhrac.poisonTurns += 3;
        cout << "Monster " << jmeno << " vystøelil jedovatý šíp na " << characterhrac.jmeno << " a zpùsobil mu " << utok << " poškození!" << endl;
        cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
    }
        
    
    
}
void Monster::chickenAttack(Character& characterhrac)
{
    int chickena = 2;
    if (characterhrac.shieldTurns > 0)
    {
        
        int snizenyutok = chickena / 2; // Snížení poškození o 50 %

        cout << characterhrac.jmeno << " má aktivní Svatý Štít! Poškození slepice sníženo na " << snizenyutok << "." << endl;
        cout << "zbývá " << characterhrac.shieldTurns << "kol\n";

        cout << "Slepice z chicken jockey zaútoèila na " << characterhrac.jmeno << " a zpùsobila mu "<< snizenyutok << " poškození!" << endl;
        characterhrac.aktualniZivoty -= snizenyutok;
        cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
    }
    else
    {
        cout << "Slepice z chicken jockey zaútoèila na " << characterhrac.jmeno << " a zpùsobila mu 2 poškození!" << endl;
        characterhrac.aktualniZivoty -= chickena; // Snížení životù hráèe o 2
        cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
    }
}
  
void Monster::BossFight(Character& characterhrac)
{
    string elementy[4] = { "Oheò", "Zemì", "Vítr", "Voda" };
    string predmety[4] = { "Ampule vody", "Hrst hlíny", "Svitek hurikánu", "Vulkanické sirky" };
    string mista[4] = { "Místo zemì", "Místo ohnì", "Místo vìtru", "Místo vody" };
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> elemDist(0, 3);

    int element = elemDist(gen); // náhodný element
    cout << "\nQuadraterra vyvolává element: " << elementy[element] << "!\n";
    cout << "Chceš použít pøedmìt (1) nebo se pøemístit (2)? ";
    int volba;
    cin >> volba;
    

    if (volba == 1) {
        cout << "Vyber pøedmìt:\n";
        for (int i = 0; i < 4; ++i) cout << i + 1 << ". " << predmety[i] << endl;
        int p; cin >> p;
        switch (p) {
        case 1: // Ampule vody
            if (element == 0) { // Oheò
                
                aktualniZivoty -= characterhrac.utok * 1.4 ;
                cout << "Ampule vody udìlila Quadraterøe " << characterhrac.utok * 1.4<< " poškození!\n";
                cout << "Quadraterra má " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";
            }
            else if (element == 1) { // Zemì
                int heal = maxZivoty * 0.1;
                aktualniZivoty += heal;
                
                if (aktualniZivoty > maxZivoty)
                {
                    aktualniZivoty = maxZivoty;
                    cout << "Quadraterra se vyléèila na max\n";
                    cout << "Quadraterra má " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";
                }
                else
                {
                    cout << "Quadratterra se vyléèila o " << heal << " HP\n";
                    cout << "Quadraterra má " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";
                }
            }
            else {
                cout << "Žádný efekt.\n";
            }
            break;
        case 2: // Hrst hlíny
            if (element == 0) {
                aktualniZivoty -= characterhrac.utok * 1.3;
                cout << "Hrst hlíny udìlila Quadraterøe " << characterhrac.utok * 1.3 << " poškození!\n";
                cout << "Quadraterra má " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";
            }
            else if (element == 2) {
                characterhrac.aktualniZivoty -= 10;
                cout << "Vítr vrátil hlínu na hráèe! Utrpìl jsi 10 poškození.\n";
                cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
                
            }
            else if (element == 3) {
                aktualniZivoty -= characterhrac.utok * 1.05;
                cout << "Hrst hlíny udìlila Quadraterøe " << characterhrac.utok * 1.05 << " poškození!\n";
                cout << "Quadraterra má " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";
            }
            else {
                cout << "Žádný efekt.\n";
            }
            break;
        case 3: // Svitek hurikánu
            if (element == 0) {
                characterhrac.aktualniZivoty -= 20;
                cout << "Oheò zesílil! Utrpìl jsi 20 poškození.\n";
                cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else if (element == 2) {
                cout << "Vítr vyrušil tvé pro poškození toto kolo!\n\n";
                characterhrac.vyruseniUtoku = true;
            }
            else if (element == 3) {
                aktualniZivoty -= characterhrac.utok * 1.05;
                characterhrac.aktualniZivoty -= 10;
                cout << "Voda: Quadraterra utrpìla " << characterhrac.utok * 1.05 << " poškození a hráè 10 poškození.\n";
                cout << "Quadraterra má " << aktualniZivoty << "/" << maxZivoty << " HP\n";
                cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else {
                cout << "Žádný efekt.\n";
            }
            break;
        case 4: // Vulkanické sirky
            if (element == 0) {
                characterhrac.aktualniZivoty -= 10;
                cout << "Oheò: Hráè utrpìl 10 poškození.\n";
                cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else if (element == 1) {
                cout << "Zemì: Tvé poškození vyrušeno toto kolo!\n\n";
                
            }
            else if (element == 2) {
                aktualniZivoty -= characterhrac.utok * 1.1;
                characterhrac.aktualniZivoty -= 10;
                cout << "Voda: Quadraterra utrpìla " << characterhrac.utok * 1.1 << " poškození a hráè 10 poškození.\n";
                cout << "Quadraterra má " << aktualniZivoty << "/" << maxZivoty << " HP\n";
                cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else {
                cout << "Žádný efekt.\n";
            }
            break;
        default:
            cout << "Neplatná volba.\n";
            break;
        }
    }
    else if (volba == 2) {
        cout << "Vyber místo:\n";
        for (int i = 0; i < 4; ++i) cout << i + 1 << ". " << mista[i] << endl;
        int m; cin >> m;
        switch (m) {
        case 1: // Místo zemì
            if (element == 0) {
                aktualniZivoty -= characterhrac.utok;
                cout << "Oheò: Plné poškození Qudraterøe: " << characterhrac.utok << endl;
                cout << "Quadraterra má " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";

            }
            else if (element == 1) {
                characterhrac.aktualniZivoty -= utok * 2;
                cout << "Zemì: Dvojnásobné poškození hráèi: " << utok * 2 << endl;
                cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else {
                cout << "Žádné poškození.\n";
            }
            break;
        case 2: // Místo ohnì
            if (element == 0) {
                characterhrac.aktualniZivoty = 0;
                cout << "Oheò: Okamžitá smrt!\n";
            }
            else if (element == 1) {
                characterhrac.aktualniZivoty -= utok;
                cout << "Zemì: Plné poškození hráèi: " << utok << endl;
                cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else if (element == 2) {
               aktualniZivoty -= characterhrac.utok * 2;
               cout << "Vítr: Dvojnásobné poškození Quadraterøe: " << utok * 2 << endl;
               cout << "Quadraterra má " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";
            }
            else {
                cout << "Voda: Žádné poškození.\n";
            }
            break;
        case 3: // Místo vìtru
            if (element == 2) {
                aktualniZivoty = 0;
                cout << "Vítr: Okamžitá Quadraterry\n";
            }
            else if (element == 0 || element == 1 || element == 3) {
                cout << "Žádné poškození.\n";
            }
            break;
        case 4: // Místo vody
            if (element == 1 || element == 2) {
                characterhrac.aktualniZivoty -= utok / 2;
                cout << "Zemì/Vítr: Polovièní poškození hráèi: " << utok / 2 << endl;
                cout << "Máš " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else if (element == 3) {
                characterhrac.aktualniZivoty = 0;
                cout << "Voda: Okamžitá smrt!\n";
            }
            else {
                cout << "Oheò: Žádné poškození.\n";
            }
            break;
        default:
            cout << "Neplatná volba.\n";
            break;
        }
    }
    else {
        cout << "Neplatná volba.\n";
    }
}
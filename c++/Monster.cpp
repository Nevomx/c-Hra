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

    int chance = distrib(gen); // Generov�n� n�hodn�ho ��sla







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
        int snizenyutok = utok / 2; // Sn�en� po�kozen� o 50 %
        
        characterhrac.shieldTurns--; // Sn�en� po�tu zb�vaj�c�ch kol �t�tu
        cout << characterhrac.jmeno << " m� aktivn� Svat� �t�t! Po�kozen� sn�eno na " << snizenyutok << "." << endl;
        cout << "zb�v� " << characterhrac.shieldTurns << "kol\n";

        cout << "Monster " << jmeno << " za�to�il na " << characterhrac.jmeno << " a zp�sobil mu " << snizenyutok << " po�kozen�!" << endl;
        characterhrac.aktualniZivoty -= snizenyutok;
        cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";

    }
   
    else
    {
        cout << "Monster " << jmeno << " za�to�il na " << characterhrac.jmeno << " a zp�sobil mu " << utok << " po�kozen�!" << endl;
        characterhrac.aktualniZivoty -= utok;
        cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
    }
    
    
   
}

void Monster::poisonarrow(Character& characterhrac)
{
    if (characterhrac.shieldTurns > 0)
    {
        int snizenyutok = utok / 2; // Sn�en� po�kozen� o 50 %
        characterhrac.poisonTurns += 3;
        characterhrac.shieldTurns--; // Sn�en� po�tu zb�vaj�c�ch kol �t�tu
        cout << characterhrac.jmeno << " m� aktivn� Svat� �t�t! Po�kozen� sn�eno na " << snizenyutok << "." << endl;
        cout << "zb�v� " << characterhrac.shieldTurns << "kol\n";

        cout << "Monster " << jmeno << " vyst�elil jedovat� ��p na " << characterhrac.jmeno << " a zp�sobil mu " << snizenyutok << " po�kozen�!" << endl;
        characterhrac.aktualniZivoty -= snizenyutok;
        cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
    }
    else
    {
        characterhrac.aktualniZivoty -= utok;
        characterhrac.poisonTurns += 3;
        cout << "Monster " << jmeno << " vyst�elil jedovat� ��p na " << characterhrac.jmeno << " a zp�sobil mu " << utok << " po�kozen�!" << endl;
        cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
    }
        
    
    
}
void Monster::chickenAttack(Character& characterhrac)
{
    int chickena = 2;
    if (characterhrac.shieldTurns > 0)
    {
        
        int snizenyutok = chickena / 2; // Sn�en� po�kozen� o 50 %

        cout << characterhrac.jmeno << " m� aktivn� Svat� �t�t! Po�kozen� slepice sn�eno na " << snizenyutok << "." << endl;
        cout << "zb�v� " << characterhrac.shieldTurns << "kol\n";

        cout << "Slepice z chicken jockey za�to�ila na " << characterhrac.jmeno << " a zp�sobila mu "<< snizenyutok << " po�kozen�!" << endl;
        characterhrac.aktualniZivoty -= snizenyutok;
        cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
    }
    else
    {
        cout << "Slepice z chicken jockey za�to�ila na " << characterhrac.jmeno << " a zp�sobila mu 2 po�kozen�!" << endl;
        characterhrac.aktualniZivoty -= chickena; // Sn�en� �ivot� hr��e o 2
        cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
    }
}
  
void Monster::BossFight(Character& characterhrac)
{
    string elementy[4] = { "Ohe�", "Zem�", "V�tr", "Voda" };
    string predmety[4] = { "Ampule vody", "Hrst hl�ny", "Svitek hurik�nu", "Vulkanick� sirky" };
    string mista[4] = { "M�sto zem�", "M�sto ohn�", "M�sto v�tru", "M�sto vody" };
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> elemDist(0, 3);

    int element = elemDist(gen); // n�hodn� element
    cout << "\nQuadraterra vyvol�v� element: " << elementy[element] << "!\n";
    cout << "Chce� pou��t p�edm�t (1) nebo se p�em�stit (2)? ";
    int volba;
    cin >> volba;
    

    if (volba == 1) {
        cout << "Vyber p�edm�t:\n";
        for (int i = 0; i < 4; ++i) cout << i + 1 << ". " << predmety[i] << endl;
        int p; cin >> p;
        switch (p) {
        case 1: // Ampule vody
            if (element == 0) { // Ohe�
                
                aktualniZivoty -= characterhrac.utok * 1.4 ;
                cout << "Ampule vody ud�lila Quadrater�e " << characterhrac.utok * 1.4<< " po�kozen�!\n";
                cout << "Quadraterra m� " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";
            }
            else if (element == 1) { // Zem�
                int heal = maxZivoty * 0.1;
                aktualniZivoty += heal;
                
                if (aktualniZivoty > maxZivoty)
                {
                    aktualniZivoty = maxZivoty;
                    cout << "Quadraterra se vyl��ila na max\n";
                    cout << "Quadraterra m� " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";
                }
                else
                {
                    cout << "Quadratterra se vyl��ila o " << heal << " HP\n";
                    cout << "Quadraterra m� " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";
                }
            }
            else {
                cout << "��dn� efekt.\n";
            }
            break;
        case 2: // Hrst hl�ny
            if (element == 0) {
                aktualniZivoty -= characterhrac.utok * 1.3;
                cout << "Hrst hl�ny ud�lila Quadrater�e " << characterhrac.utok * 1.3 << " po�kozen�!\n";
                cout << "Quadraterra m� " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";
            }
            else if (element == 2) {
                characterhrac.aktualniZivoty -= 10;
                cout << "V�tr vr�til hl�nu na hr��e! Utrp�l jsi 10 po�kozen�.\n";
                cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
                
            }
            else if (element == 3) {
                aktualniZivoty -= characterhrac.utok * 1.05;
                cout << "Hrst hl�ny ud�lila Quadrater�e " << characterhrac.utok * 1.05 << " po�kozen�!\n";
                cout << "Quadraterra m� " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";
            }
            else {
                cout << "��dn� efekt.\n";
            }
            break;
        case 3: // Svitek hurik�nu
            if (element == 0) {
                characterhrac.aktualniZivoty -= 20;
                cout << "Ohe� zes�lil! Utrp�l jsi 20 po�kozen�.\n";
                cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else if (element == 2) {
                cout << "V�tr vyru�il tv� pro po�kozen� toto kolo!\n\n";
                characterhrac.vyruseniUtoku = true;
            }
            else if (element == 3) {
                aktualniZivoty -= characterhrac.utok * 1.05;
                characterhrac.aktualniZivoty -= 10;
                cout << "Voda: Quadraterra utrp�la " << characterhrac.utok * 1.05 << " po�kozen� a hr�� 10 po�kozen�.\n";
                cout << "Quadraterra m� " << aktualniZivoty << "/" << maxZivoty << " HP\n";
                cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else {
                cout << "��dn� efekt.\n";
            }
            break;
        case 4: // Vulkanick� sirky
            if (element == 0) {
                characterhrac.aktualniZivoty -= 10;
                cout << "Ohe�: Hr�� utrp�l 10 po�kozen�.\n";
                cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else if (element == 1) {
                cout << "Zem�: Tv� po�kozen� vyru�eno toto kolo!\n\n";
                
            }
            else if (element == 2) {
                aktualniZivoty -= characterhrac.utok * 1.1;
                characterhrac.aktualniZivoty -= 10;
                cout << "Voda: Quadraterra utrp�la " << characterhrac.utok * 1.1 << " po�kozen� a hr�� 10 po�kozen�.\n";
                cout << "Quadraterra m� " << aktualniZivoty << "/" << maxZivoty << " HP\n";
                cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else {
                cout << "��dn� efekt.\n";
            }
            break;
        default:
            cout << "Neplatn� volba.\n";
            break;
        }
    }
    else if (volba == 2) {
        cout << "Vyber m�sto:\n";
        for (int i = 0; i < 4; ++i) cout << i + 1 << ". " << mista[i] << endl;
        int m; cin >> m;
        switch (m) {
        case 1: // M�sto zem�
            if (element == 0) {
                aktualniZivoty -= characterhrac.utok;
                cout << "Ohe�: Pln� po�kozen� Qudrater�e: " << characterhrac.utok << endl;
                cout << "Quadraterra m� " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";

            }
            else if (element == 1) {
                characterhrac.aktualniZivoty -= utok * 2;
                cout << "Zem�: Dvojn�sobn� po�kozen� hr��i: " << utok * 2 << endl;
                cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else {
                cout << "��dn� po�kozen�.\n";
            }
            break;
        case 2: // M�sto ohn�
            if (element == 0) {
                characterhrac.aktualniZivoty = 0;
                cout << "Ohe�: Okam�it� smrt!\n";
            }
            else if (element == 1) {
                characterhrac.aktualniZivoty -= utok;
                cout << "Zem�: Pln� po�kozen� hr��i: " << utok << endl;
                cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else if (element == 2) {
               aktualniZivoty -= characterhrac.utok * 2;
               cout << "V�tr: Dvojn�sobn� po�kozen� Quadrater�e: " << utok * 2 << endl;
               cout << "Quadraterra m� " << aktualniZivoty << "/" << maxZivoty << " HP\n\n";
            }
            else {
                cout << "Voda: ��dn� po�kozen�.\n";
            }
            break;
        case 3: // M�sto v�tru
            if (element == 2) {
                aktualniZivoty = 0;
                cout << "V�tr: Okam�it� Quadraterry\n";
            }
            else if (element == 0 || element == 1 || element == 3) {
                cout << "��dn� po�kozen�.\n";
            }
            break;
        case 4: // M�sto vody
            if (element == 1 || element == 2) {
                characterhrac.aktualniZivoty -= utok / 2;
                cout << "Zem�/V�tr: Polovi�n� po�kozen� hr��i: " << utok / 2 << endl;
                cout << "M� " << characterhrac.aktualniZivoty << "/" << characterhrac.maxZivoty << " HP\n\n";
            }
            else if (element == 3) {
                characterhrac.aktualniZivoty = 0;
                cout << "Voda: Okam�it� smrt!\n";
            }
            else {
                cout << "Ohe�: ��dn� po�kozen�.\n";
            }
            break;
        default:
            cout << "Neplatn� volba.\n";
            break;
        }
    }
    else {
        cout << "Neplatn� volba.\n";
    }
}
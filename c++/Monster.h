#pragma once
#include <string>

using namespace std;

class Character;

class Monster
{
public:
    int maxZivoty;
    int aktualniZivoty;
    int utok;
    string jmeno;

    Monster(int monster);

    void attack(Character& characterhrac);
    void poisonarrow(Character& characterhrac);
    void chickenAttack(Character& characterhrac);
    void encouter(Character& characterhrac);
    void BossFight(Character& characterhrac);
};

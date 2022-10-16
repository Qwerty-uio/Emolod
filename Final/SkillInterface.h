#pragma once
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <conio.h>
#include "Monster.h"
#include "Engine.h"
#include "Event.h"
#include "Player.h"

using namespace std;

class SkillInterface {
public:
	virtual void skill(Player* player, Monster* monster) = 0;
};

class Hit : public SkillInterface {
	void skill(Player* player, Monster* monster) override {
		int playerDamage = monster->generateDefence(player->generateDamage());
		if (playerDamage < 0) {
			playerDamage = 0;
		}
		cout << "You dealed monster " << playerDamage << ".\n";
		monster->setHP(monster->getHP() - playerDamage);
		player->setEnergy(player->getEnergy() - player->getLevel() - 3);
	}
};

class DoubleHit : public SkillInterface {
	void skill(Player* player, Monster* monster) override {
		int playerDamage1 = monster->generateDefence(player->generateDamage());
		if (playerDamage1 < 0) {
			playerDamage1 = 0;
		}
		int playerDamage2 = monster->generateDefence(player->generateDamage());
		if (playerDamage2 < 0) {
			playerDamage2 = 0;
		}
		cout << "You dealed monster " << playerDamage1<<" and "<<playerDamage2 << ".\n";
		monster->setHP(monster->getHP() - playerDamage1-playerDamage2);
		player->setEnergy(player->getEnergy() - player->getLevel()*5/4-5);
	}
};
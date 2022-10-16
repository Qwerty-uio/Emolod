#pragma once
#include <iostream>
#include "Monster.h"
#include "Player.h"

using namespace std;

/*class SkillInterface {
public:
	virtual void hit(Player* player, Monster* monster) = 0;
	virtual void doubleHit(Player* player, Monster* monster) = 0;
};

class Hit : public SkillInterface {
	void hit(Player* player, Monster* monster) override {
		int playerDamage = monster->generateDefence(player->generateDamage());
		if (playerDamage < 0) {
			playerDamage = 0;
		}
		cout << "You dealed monster " << playerDamage << ".\n";
		monster->setHP(monster->getHP() - playerDamage);
		player->setEnergy(player->getEnergy() - 5);

	}
};

class DoubleHit : public SkillInterface {
	void doubleHit(Player* player, Monster* monster) {
		int playerDamage1 = monster->generateDefence(player->generateDamage());
		int playerDamage2 = monster->generateDefence(player->generateDamage());
		if (playerDamage1 < 0) {
			playerDamage1 = 0;
		}
		if (playerDamage2 < 0) {
			playerDamage2 = 0;
		}
		cout << "You dealed monster " << playerDamage1 << " and " << playerDamage2 << ".\n";
		monster->setHP(monster->getHP() - (playerDamage1 + playerDamage2));
		player->setEnergy(player->getEnergy() - 8);

	}
};
*/


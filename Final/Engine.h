#pragma once
//#include "SkillInterface.h"
#include <iostream>
#include <vector>
#include "Player.h"
#include "Monster.h"
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class Engine {
private:
	vector <string> monsterNames = { "Bogeyman","Vampire","Zombie", "Hydra","Chimera","Yeti","Dragon","Basilisk","Werewolf", "Gorgon" };
	vector <string> armorNames = { "Leather Armor", "Golden Armor","Bronze Armor","Black Armor" };
	vector <string> weaponNames = { "Sword", "Dagger", "Pike", "Axe", "Spear" };
	//vector <SkillInterface*> skills;

public:
	int random(int min, int max) {

		return min + rand() % (max - min + 1);
	}
	Player* createPlayer(string name, int category) {
		int str = random(4, 7), ag = random(4, 7), end = random(4, 7);
		//SkillInterface* skill = new Hit();

		//this->skills.push_back(skill);
		switch (category)
		{
		case 1:
			str += random(2, 5);
			break;
		case 2:
			end += random(2, 5);
			break;
		case 3:
			ag += random(2, 5);
			//skill = new DoubleHit();

			//this->skills.push_back(skill);
			break;
		}

		return new Player(name, random(25, 50), random(25, 50), str, ag, end, createWeapon(1));
	}

	Monster* createMonster(int lvl) {

		if (lvl > 1) {
			lvl += this->random(-1, 1);
		}
		else {
			lvl += this->random(0, 1);
		}

		int dmg = this->random(2, 7) + lvl * random(1, 4);
		int def = this->random(2, 7) + lvl * random(1, 4);
		int hp = this->random(15, 25) + lvl * random(5, 10);
		int en = this->random(5, 15) + lvl * random(5, 10);
		int exp = this->random(5, 40) + lvl * random(10, 25);
		int money = this->random(2, 7) + lvl * random(3, 5);

		return new Monster(this->monsterNames[random(0, this->monsterNames.size() - 1)], hp, en, dmg, def, lvl, exp, money);
	}

	void fight(Player* player, Monster* monster) {
		cout << "You met a " << monster->getName() << endl;
		do {
			int playerDamage = monster->generateDefence(player->generateDamage());
			if (playerDamage < 0) {
				playerDamage = 0;
			}
			cout << "You dealed monster " << playerDamage << ".\n";
			monster->setHP(monster->getHP() - playerDamage);
			int monsterDamage = player->generateDefence(monster->getDamage());
			if (monsterDamage <= 0) {
				monsterDamage = 1;
			}
			cout << "Monster dealed you " << monsterDamage << ".\n";
			player->setHP(player->getHP() - monsterDamage);
		} while (monster->getHP() > 0 && player->getHP() > 0);
		if (player->getHP() <= 0) {
			cout << "You lost\n";
		}
		else
		{
			cout << "You won\n" <<
				"You get " << monster->getExperience() << "EXP and " << monster->getMoney() << "$.\n";

			player->giveExperience(monster->getExperience());
			player->setCash(player->getCash() + monster->getMoney());
		}
	}

	Weapon* createWeapon(int lvl) {
		int dmg = random(lvl * 2 + 1, lvl * 2 + 20);
		return new Weapon(this->weaponNames[random(0, this->weaponNames.size() - 1)], dmg, dmg + random(0, lvl / 3));
	}
	Armor* createArmor(int lvl) {
		int def = random(lvl * 2 + 3, lvl * 2 + 20);
		return new Armor(this->armorNames[random(0, this->armorNames.size() - 1)], def, def + random(0, lvl / 3));
	}

};
#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Monster.h"
#include "SkillInterface.h"
#include "Weapon.h"
#include "Armor.h"
#include "Engine.h"
#include <string>
#include <algorithm>

using namespace std;

class Event {
private:
	Engine* engine = NULL;
	Player* player = NULL;
	vector <Armor*> armorShop = {};
	vector <Weapon*> weaponShop = {};

	void buyItem() {
		int itemNumber;
		cout << "What would you like to buy?(enter number)\n";
		cin >> itemNumber;
		if (itemNumber > armorShop.size()) {
			Weapon* weapon = weaponShop[itemNumber - armorShop.size() - 1];
			if (enoughMoney(weapon->getPrice())) {
				player->setWeapon(weapon);
				player->setCash(player->getCash() - weapon->getPrice());
				cout << "You've bought " << weapon->getName() << " for " << weapon->getPrice() << endl;
			}
			else {
				cout << "You don't have enough money";
			}
		}
		else if (itemNumber > 0) {
			Armor* armor = armorShop[itemNumber - 1];
			if (enoughMoney(armor->getPrice())) {
				player->setArmor(armor);
				player->setCash(player->getCash() - armor->getPrice());
				cout << "You've bought " << armor->getName() << " for " << armor->getPrice() << endl;
			}
			else {
				cout << "You don't have enough money";
			}
		}
		else {
			cout << "Unknown item";
		}
	}

	bool enoughMoney(int price) {
		if (price <= player->getCash()) {
			return true;
		}
		return false;
	}
public:
	Event(Player* player, Engine* engine) {
		this->player = player;
		this->engine = engine;
	}

	void shop(int itemsCount) {
		this->armorShop.clear();
		this->weaponShop.clear();
		int armorCount = 1 + rand() % (itemsCount - 1);
		int itemNumber = 0;
		int count = 0;
		while (count < armorCount) {
			Armor* armor = this->engine->createArmor(this->player->getLevel());
			this->armorShop.push_back(armor);
			count++;
		}
		count = 0;
		while (count < itemsCount - armorCount) {
			Weapon* weapon = engine->createWeapon(this->player->getLevel());
			weaponShop.push_back(weapon);
			count++;

		}
		if (armorShop.size() != 0) {
			cout << "========Armor========\n";
			for (int i = 0; i < armorShop.size(); i++) {
				cout << i + 1 << " -> ";
				armorShop[i]->printInfo();
				cout << endl;
			}
		}
		if (weaponShop.size() != 0) {
			cout << "========Weapon========\n";
			for (int i = 0; i < weaponShop.size(); i++) {
				cout << i + armorShop.size() + 1 << " -> ";
				weaponShop[i]->printInfo();
				cout << endl;
			}
		}
		cout << "Your cash: " << player->getCash() << "\nYour weapon: ";
		player->getWeapon()->printInfo();
		cout << "\nYour armor: ";
		player->getArmor()->printInfo();
		cout << endl;
		cout << "Would you like to buy something?(yes or no)\n";
		string answer = "";
		cin >> answer;

		transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char c) { return tolower(c); });
		if (answer == "yes") {
			buyItem();
		}
	}
	void meetMonster() {
		Monster* monster = this->engine->createMonster(this->player->getLevel());
		engine->fight(player, monster);
	}

	void hunting() {
		int eventNumber = 1 + rand() % 2;
		switch (eventNumber)
		{
		case 1:
			cout << "You caught a hare in the forest. \n";
			player->setAgility(player->getAgility() + rand() % 4);
			player->setEndurance(player->getEndurance() + rand() % 4);
			break;
		case 2:
			cout << "You defeated a bear in the forest. \n";
			player->setStr(player->getStr() + rand() % 4);
		default:
			break;
		}

	}

};

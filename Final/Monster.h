#pragma once
#include <iostream>
#include "Pearson.h"

using namespace std;

class Monster : public Person {
private:
	int damage = 0;
	int defence = 0;
	int experience = 0;
	int money = 0;
public:
	Monster(string name, int hp, int en, int dmg, int def, int lvl, int exp, int money) : Person(name, lvl, hp, en) {
		damage = dmg;
		defence = def;
		experience = exp;
		this->money = money;
	}

	int getDamage() {
		return this->damage * 2 / 3;
	}
	int getDefence() {
		return this->defence;
	}
	int getExperience() {
		return this->experience;
	}
	int getMoney() {
		return this->money;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	void setDefence(int defence) {
		this->defence = defence;
	}
	void setExperience(int experience) {
		this->experience = experience;
	}
	int generateDefence(int damage) {

		return damage - (defence) / 3;
	}

};


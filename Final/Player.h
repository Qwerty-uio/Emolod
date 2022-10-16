#pragma once
#include <iostream>
#include <vector>
#include "Pearson.h"
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class Player : public Person {
private:
	int strength = 0;
	int agility = 0;
	int endurance = 0;
	int experience = 0;
	int experienceMax = 100;
	int cash = rand() % 20;
	Weapon* weapon = NULL;
	Armor* armor = NULL;


public:
	Player(string name, int hp, int en, int str, int ag, int end, Weapon* weapon) : Person(name, 1, hp, en) {
		strength = str;
		agility = ag;
		endurance = end;
		this->weapon = weapon;
		this->armor = new Armor("None", 0, 0);
	}

	int getStr() {
		return strength;
	}
	int getAgility() {
		return agility;
	}
	int getEndurance() {
		return endurance;
	}
	int getExperience() {
		return experience;
	}
	int getExperienceMax() {
		return experienceMax;
	}
	int getCash() {
		return(this->cash);
	}
	Weapon* getWeapon() {
		return this->weapon;
	}
	Armor* getArmor() {
		return this->armor;
	}
	void setStr(int str) {
		this->strength = str;
	}
	void setAgility(int agility) {
		this->agility = agility;
	}
	void setEndurance(int endurance) {
		this->endurance = endurance;
	}

	void setCash(int money) {
		this->cash = money;
	}
	void setWeapon(Weapon* weapon) {
		this->weapon = weapon;
	}
	void setArmor(Armor* armor) {
		this->armor = armor;
	}

	void regeneration(int regenerate) {
		health += regenerate;
		cout << "Regenerated " << regenerate << " HP.\n";
		if (health > healthMax) {
			health = healthMax;
		}
	}

	void giveExperience(int exp) {
		experience += exp;
		while (experienceMax <= experience) {

			experience -= experienceMax;
			levelUp();
		}
	}
	void levelUp() {
		level += 1;
		experienceMax += 90 + rand() % 21;
		healthMax += rand() % 10;
		energyMax += rand() % 10;
		strength += rand() % 4;
		endurance += rand() % 4;
		agility += rand() % 4;
		cout << "You level increased.(" << level << ")\n";
	}

	int generateDamage() {
		int damage = weapon->getDamage() + strength;
		int critChance = (agility + level) / 3;

		if ((rand() % agility) <= critChance) {
			damage += agility;
		}

		return damage * 2 / 3;
	}

	int generateDefence(int damage) {

		return damage - (endurance + armor->getDefence()) / 3;
	}
};



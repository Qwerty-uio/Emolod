#pragma once
#include <iostream>

using namespace std;

class Person {
protected:
	string name = "";
	int health = 0, healthMax = 0;
	int energy = 0, energyMax = 0;
	int level = 1;

public:
	Person(string name, int level, int health, int energy) {
		this->name = name;
		this->level = level;
		this->health = health;
		this->healthMax = health;
		this->health = health;
		this->energy = energy;
		this->energyMax = energy;
	}

	int getLevel() {
		return this->level;
	}
	int getHP() {
		return health;
	}
	int getHPMax() {
		return healthMax;
	}
	int getEnergy() {
		return energy;
	}
	int getEnergyMax() {
		return energy;
	}
	string getName() {
		return name;
	}
	void setLevel(int level) {
		this->level = level;
	}
	void setHP(int health) {
		this->health = health;
	}
	void setHPMax(int healthMax) {
		this->healthMax = healthMax;
	}
	void setEnergy(int energy) {
		this->energy = energy;
	}
	void setEnergyMax(int energyMax) {
		this->energyMax = energyMax;
	}
};

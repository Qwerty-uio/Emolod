#pragma once
#include <iostream>
#include "Item.h"

using namespace std;

class Weapon : public Item {
private:
	int damage = 0;
public:
	Weapon(string name, int damage, int price = 0) :Item(name, price)
	{
		this->damage = damage;
	}
	int getDamage() {
		return this->damage;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	void printInfo() {
		cout << name << ".  Damage:  " << damage << "  Price:  " << price;
	}
};




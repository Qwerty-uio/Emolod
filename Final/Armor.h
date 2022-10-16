#pragma once
#include <iostream>
#include "Item.h"

using namespace std;

class Armor : public Item {
private:
	int defence = 0;
public:
	Armor(string name, int defence, int price = 0) :Item(name, price)
	{
		this->defence = defence;
	}
	int getDefence() {
		return this->defence;
	}
	void setDefence(int defence) {
		this->defence = defence;
	}
	void printInfo() {
		cout << name << ".  Defence:  " << defence << "  Price:  " << price;
	}
};


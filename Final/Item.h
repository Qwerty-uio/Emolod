#pragma once
#include <iostream>

using namespace std;

class Item {
protected:
	string name = "";
	int price = 0;
public:
	Item(string name, int price = 0) {
		this->name = name;
		this->price = price;
	}
	string getName() {
		return this->name;
	}
	int getPrice() {
		return this->price;
	}
	void setName(string name) {
		this->name = name;
	}
	void setPrice(int price) {
		this->price = price;
	}
};


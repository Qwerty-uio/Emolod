#pragma once
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <conio.h>
#include "Engine.h"
#include "Event.h"
#include "Player.h"
#include "SkillInterface.h"

using namespace std;




class SaveLoad {
private: 
	Player* player = NULL;
public:
	Player* load() {
		
		ifstream load;
		load.open("playerBase.txt");
		if (load.is_open()) {

			load.read((char*)&player, sizeof(Player));
		}
		else {
			cout << "No saves\n";
		}
		load.close();
		return player;
	}
	void save(Player* player) {
		ofstream save;
		save.open("playerBase.txt");
		save.write((char*)&player, sizeof(Player));
		save.close();
	}
};


int main() {
	srand(time(NULL));
	SaveLoad* saveLoad = new SaveLoad();
	Engine* engine = new Engine();
	Player* player = NULL;
	Event* event = NULL;
	//player=saveLoad->load();
	




	if (player == NULL) {
		string name = "";
		int category = 0;

		cout << "Enter player name: ";
		cin >> name;

		cout << "Choose your class: 1-Barbarian, 2-Tank, 3-Rogue:" << endl;
		cin >> category;

		if (category < 1 || category > 3) {
			cout << "Error!";
			return 0;
		}

		player = engine->createPlayer(name, category);
		
	}

	event = new Event(player, engine);

	do {
		int eventChance = rand() % 100;
		if (eventChance < 5) {
			event->shop(engine->random(3,7));
		}
		else if (eventChance < 45) {
			event->meetMonster();
		}
		else if (eventChance<70)
		{
			event->hunting();
		}
		else
		{
			cout << "...\n";
		}


		if (player->getHP() <= 0) {
			cout << "You died.";
			//saveLoad->save(NULL);
			return 0;
		}
		player->regeneration(engine->random(player->getHP() / 5, player->getHPMax() /2));
		cout << "Press ESC to stop game or press any other key to continue.\n";
	} while (_getch()!=27);



	return 1;
}
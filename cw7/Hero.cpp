// Workshop <Workshop #7>
// Name: <doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <hero.cpp>
#define _CRT_SECURE_NO_WARINGS
#include "Hero.h"
#include <cstring>
using namespace std;
namespace sict {

	Hero::Hero()
	{
		hero_name[0] = '\0';
		hero_strength = 0;
		hero_health = 0;
	}
	Hero::Hero(const char name[], int health, int attack) {
		strcpy(hero_name, name);
		hero_health = health;
		hero_strength = attack;
	}
	void Hero::operator-=(int attack) {
		if (attack > 0) {
			this->hero_health -= attack;
		}
		if (!this->hero_health) {
			this->hero_health = 0;
		}
	}
	bool Hero::isAlive() const {
		if (this->hero_health > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	int Hero::attackStrength() const {
		if (this->hero_strength > 0) {
			return this->hero_strength;
		}
		else {
			return 0;
		}
	}
	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		hero.display(os);
		return os;
	}
	void Hero::display(ostream & dp) const {
		if (strcmp(hero_name, "") != 0) {
			dp << hero_name;
		}
		else {
			dp << "No hero" << std::endl;
		}
	}
	const Hero& operator*(const Hero& first, const Hero& second) {
		std::cout << "Ancient Battle! " << first << " vs " << second << " : ";
		Hero A = first;
		Hero B = second;
		const Hero *winner = nullptr;
		unsigned int rounds = 0;
		while (A.isAlive() && B.isAlive() && rounds < 100) {
			rounds++;
			A.operator-=(B.attackStrength());
			B.operator-=(A.attackStrength());
		}
		bool draw;
		if (A.isAlive() && B.isAlive()) {
			draw = true;
		}
		else {
			draw = false;
		}
		if (draw) {
			winner = &first;
		}
		else if (A.isAlive()) {
			winner = &first;
		}
		else {
			winner = &second;
		}
		cout << "Winner is " << *winner << " in " << rounds << " rounds."
			<< endl;
		return *winner;
	}
}

#define _CRT_SECURE_NO_WARNINGS
#include "SuperHero.h"
#include "Hero.h"
using namespace std;
namespace sict {
	SuperHero::SuperHero(const char name[], int health, int strength, int bonus, int defend) : Hero(name, health, strength) {
		attack_bonus = bonus;
		defend_bonus = defend;
	}
	int SuperHero::defend() const {
		return defend_bonus> 0 ? defend_bonus : 0;
	}
	int SuperHero::attackStrength() const {
		return Hero::attackStrength() + attack_bonus > 0 ? Hero::attackStrength() + attack_bonus : 0;
	}
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		cout << "Super Fight! " << first << " vs " << second << " : ";
		SuperHero A = first;
		SuperHero B = second;
		const SuperHero *winner = nullptr;
		unsigned int rounds = 0;
		while (A.isAlive() && B.isAlive() && rounds < 100) {
			rounds++;
			A.operator-=(B.attackStrength() - A.defend());
			B.operator -=(A.attackStrength() - B.defend());
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
		cout << "Winner is " << *winner << " in " << rounds << " rounds."<< endl;
		return *winner;
	}
}
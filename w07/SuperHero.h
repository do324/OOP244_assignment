#ifndef SUPERHERO_H
#define SUPERHERO_H
#include "Hero.h"
namespace sict {
	class SuperHero : public Hero {
		int attack_bonus;
		int defend_bonus;
	public:
		SuperHero(const char name[], int, int, int, int);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif

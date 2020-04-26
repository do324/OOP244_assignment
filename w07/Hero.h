#ifndef HERO_H
#define HERO_H
#include<iostream>
#define max_rounds 100
namespace sict {
	class Hero {
		char hero_name[41];
		int hero_health;
		int hero_strength;
	public:
		Hero();
		Hero(const char name[], int health, int attack);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
		void display(std::ostream & dp) const;
	}
	;
	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif
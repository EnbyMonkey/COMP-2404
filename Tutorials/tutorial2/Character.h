
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

using namespace std;

class Character {

	public:
		//constructor
//		Character();
		Character(string &name, int maxHealth, int damage);


		//setters


		//getters
		string getName();

		//other
		void takeDamage(int);
    int strike();

		void print();

	private:
		//functions


		//variables
    string name;
    int maxHealth;
    int currentHealth;
    int damage;


};
#endif

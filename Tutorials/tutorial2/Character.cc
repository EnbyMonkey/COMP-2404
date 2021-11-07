#include "Character.h"


Character::Character(string &name, int maxHealth, int damage) {
  this->name = name;
  this->maxHealth = this->currentHealth = maxHealth;
  this->damage = damage;
}


// setters


// getters
string Character::getName() {
  return this->name;
}


// other
void Character::takeDamage(int damage) {
  this->currentHealth -= damage;
  if (this->currentHealth < 0) this->currentHealth = 0;
}

int Character::strike() {
  return this->damage;
}

void Character::print() {
  cout << this->name << " has " << this->currentHealth
       << " health left." << endl;

}

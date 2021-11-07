#include <iostream>

#include "Character.h"
#include "battle.h"

using namespace std;

int main(){
  cout << "We are pitting a Gondor fighter against an orc from Mordor!" << endl
       << "What should we name our Gondor fighter?" << endl;

  string fighterName;
  cin >> fighterName;

  cout << "How much health does " << fighterName << " have?" << endl;

  int fighterMaxHealth;
  cin >> fighterMaxHealth;

  cout << "The last thing we need is the damage " << fighterName << " does." << endl << endl;

  int fighterDamage;
  cin >> fighterDamage;

  cout << "What is the name of our orc from Mordor?" << endl;

  string orcName;
  cin >> orcName;

  cout << "How much health does " << orcName << " have?" << endl;

  int orcMaxHealth;
  cin >> orcMaxHealth;

  cout << "And finally we need the damage " << orcName << " does." << endl;

  int orcDamage;
  cin >> orcDamage;

  // initializing fighter and orc
  Character fighter(fighterName, fighterMaxHealth, fighterDamage);
  Character orc(orcName, orcMaxHealth, orcDamage);

  // print our two combatants
  cout << "This is the fighter we created:" << endl;
  fighter.print();
  cout << endl;

  cout << "And this is our orc:" << endl;
  orc.print();
  cout << endl;

  // fight in Gondor
  Gondor::fight(fighter, orc);

  fighter.print();
  orc.print();

  // fight in Mordor
  Mordor::fight(fighter, orc);

  fighter.print();
  orc.print();

  return 0;
}

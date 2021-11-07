#include "battle.h"

// need two namespaces
void Mordor::fight(Character& fighter, Character& orc) {
  string orcName = orc.getName();
  string fighterName = fighter.getName();

  cout << orcName << " and " << fighterName
       << " are fighting in Mordor!" << endl << endl;

  int orcDamage = orc.strike() + 1;
  int fighterDamage = fighter.strike() - 1;

  cout << orcName << " smashes " << fighterName << " in the face! "
       << fighterName << " takes " << orcDamage << " damage." << endl
       << fighterName << " hacks off " << fighterName << "'s arm! "
       << orcName << " takes " << fighterDamage << " damage." << endl << endl;

  fighter.takeDamage(orcDamage);
  orc.takeDamage(fighterDamage);
}

void Gondor::fight(Character& fighter, Character& orc) {
  string const& orcName = orc.getName();
  string const& fighterName = fighter.getName();

  cout << orcName << " and " << fighterName
       << " are fighting in Gondor!"  << endl << endl;

  int orcDamage = orc.strike() - 1;
  int fighterDamage = fighter.strike() + 1;

  cout << orcName << " smashes " << fighterName << " in the face! "
       << fighterName << " takes " << orcDamage << " damage." << endl
       << fighterName << " hacks off " << fighterName << "'s arm! "
       << orcName << " takes " << fighterDamage << " damage." << endl << endl;

  fighter.takeDamage(orcDamage);
  orc.takeDamage(fighterDamage);
}

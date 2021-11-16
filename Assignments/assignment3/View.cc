#include <iostream>
#include <limits>
#include <string>

using namespace std;

#include "View.h"

void View::showMenu(int& choice)
{
  int numOptions = 7;

  cout << endl << endl;
  cout << "Which test would you like to run?"<< endl;
  cout << "  (1) Receive product" << endl;
  cout << "  (2) Fill order" << endl;
  cout << "  (3) Print store locations" << endl;
  cout << "  (4) Print warehouse locations" << endl;
  cout << "  (5) Print products" << endl;
  cout << "  (6) Location test" << endl;
  cout << "  (7) Queue test" << endl;
  cout << "  (0) Exit" << endl <<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::getProduct(string& product){
  cout<<"Which product? ";
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  getline(cin, product);
  cout << endl;
}

void View::getQuantity(int& q){
  cout<<"What quantity? ";
  cin >> q;
  cout << endl;
}

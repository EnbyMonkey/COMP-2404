#include<iostream>
#include<string>

using namespace std;

int main(){

	cout << "Hi!  What is your name?"<<endl;
	string name;
	cin >> name;
	cout << "Hello " + name + "!" << endl;
	return 0;
}

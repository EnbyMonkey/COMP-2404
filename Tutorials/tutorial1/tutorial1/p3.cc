#include<iostream>
#include<string>
#include "power.cc"

using namespace std;

int main(){
	cout << "Please enter two integers: "<<endl;
	int x1, x2, x3;
	cin >> x1 >> x2;

	power(x1, x2, x3);
	cout << x1 << " to the power of " << x2 << " is " << x3 << "!" << endl;
	return 0;
}

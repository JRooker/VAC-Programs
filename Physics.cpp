#include <iostream>
#include <string>
#include <vector>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
struct Physics
{

public:
	const double pi = 3.1415926535;
	const double speedLight = 299792458;
	const double G = 6.67408*pow(10,-11);
	const double g = 9.81;

	Physics() {cout <<"creating physics" << endl;}
	~Physics(){ cout <<"destroying physics" << endl;}
	void Printout()
	{
		cout << "Pi = " << pi << endl;
		cout << "Speed of light = " << speedLight << endl;
		cout << "Gravity constant = " << G << endl;
		cout << "Gravity on earth = " <<g<< endl;
	}
};

int main()
{
	
}
#include <iostream>
#include <string>
#include <vector>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() 
{
	double velstar,postar;
	double k = 1;
	double XO = 1;
	double vhold[100];
	double phold[100];
	double h = .01;
	phold[0] = XO;
	vhold[0] = 0;
	cout << "input calculate u(t) , what t" << endl;
	double t = 0;
	cin >> t;
	t = t / h;
	for (int n = 0; n <= t; t++)
	{
		velstar = vhold[n] + h * (-(pow(k, 2)*phold[n]));
		postar = phold[n] + h * vhold[n];
		vhold[n + 1] = vhold[n] + .5*h*((-pow(k, 2)*phold[n]) - (pow(k, 2)*postar));
		phold[n + 1] = phold[n] + .5*h*(vhold[n] + velstar);
		cout << "Time : " << (n) << ",  Position: " << phold[n] << ",  Velocity: " << vhold[n]<<endl;
	}
}
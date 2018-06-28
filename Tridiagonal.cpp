#include <iostream>
#include <string>
#include <vector>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	vector<double> vectorE(3, -1);
	vector<double> vectorF(4, 2.04);
	vector<double> vectorG(3, -1);
	vector<double> vectorR = { { 40.8 },{ 0.8 },{ 0.8 },{ 200.8 } };
	vector<double> answers(4, 0);
	/*
	vector<double> vectorE(3, -1);
	vector<double> vectorF(4, 2);
	vector<double> vectorG(3, -1);
	vector<double> vectorR = { { .04 },{ 0.04 },{ 0.04 },{ .04 } };
	vector<double> answers(4, 0);*/
	//display
	for (int b = 0; b <(int)vectorE.size(); b++)
		cout << vectorE[b] << " "; cout << endl;
	for (int b = 0; b <(int)vectorF.size(); b++)
		cout << vectorF[b] << " "; cout << endl;
	for (int b = 0; b <(int)vectorG.size(); b++)
		cout << vectorG[b] << " "; cout << endl;
	for (int b = 0; b <(int)vectorR.size(); b++)
		cout << vectorR[b] << " "; cout << endl;

	for (int a = 1; a <(int)vectorF.size(); a++)
	{
		cout << a << "hey";
		vectorF[a] = vectorF[a] - (vectorE[a - 1] / vectorF[a - 1]) * vectorG[a - 1];
		vectorR[a] = vectorR[a] - (vectorE[a - 1] / vectorF[a - 1]) * vectorR[a - 1];
	}
	cout << "check " << (int)vectorF.size() - 1;
	for (int a = (int)vectorF.size() - 1; a >= 0; a--)
	{
		if (a == (int)vectorF.size() - 1)
			answers[a] = vectorR[a] / vectorF[a];
		else
		{
			answers[a] = (vectorR[a] - vectorG[a] * answers[a + 1]) / vectorF[a];
		}
	}

	cout << endl << endl;
	for (int b = 0; b <(int)answers.size(); b++)
		cout << answers[b] << " ";
	cout << endl;
	int a;
	cin >> a;
	return 0;

}
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
void Printe();
void pivot(int);
int const n = 4;
double SystEqu[n][n] = { { 1,2,3,1 },{ 3,4,5,3},{7,8,9,10},{11,12,13,14} };
double SystAnsw[n] = { 8,10,10,4 };
double Xn[n] = {0,0,0,0};
int main()
{
	Printe();
	cout << endl;
	/*for (int r = 0; r < n; r++)
	{
		SystAnsw[r] /= SystEqu[r][r];
		for (int c = 0; c < n; c++)
		{
			SystEqu[r][c] /= SystEqu[r][r];//makes the diagonal 1
		}
	}
		cout << "ones update" << endl;

	Printe();
	cout<<endl<<endl;*/
	double factor;

	for (int k = 0; k < n - 1; k++)
	{
		if (SystEqu[k][k] == 0)
			pivot(k);
		for (int i = k + 1; i < n; i++)
		{
			factor = SystEqu[i][k] / SystEqu[k][k];
			cout << "i " << i << ", k " << k << " , FActor = " << SystEqu[i][k] << "/" << SystEqu[k][k] << " = " << factor << endl;
			for (int j = k; j < n; j++)
				SystEqu[i][j] = SystEqu[i][j] - factor * SystEqu[k][j];
			SystAnsw[i] = SystAnsw[i] - factor * SystAnsw[k];
			Printe(); cout << endl;
		}
	}
	double sum;
	if(SystEqu[n - 1][n - 1] == 0)
		cout<<"This matrix will not work"<<endl;
	Xn[n-1] = SystAnsw[n-1] / SystEqu[n-1][n-1];
	for (int i = n - 2; i >= 0; i--)
	{
		sum = SystAnsw[i];
		for (int j = i + 1; j < n; j++)
			sum = sum - SystEqu[i][j] * Xn[j];
		Xn[i] = sum / SystEqu[i][i];
	}

	cout << endl << endl << " The solution is ";
	for (int i = 0; i < n; i++)
		cout << Xn[i] << " ";

	int q;
	cin >> q;
	return 0;
}

void pivot(int k)
{
	double temp = 0;
	double max = 0;
	int holdi = -1;;
	for (int i = k; i < n; i++)
		if (SystEqu[i][k] > max)
		{
			max = SystEqu[i][k];
			holdi = i;
		}
	if (holdi == -1)
		return;
	cout << "K = " << k<< ", THE bigges element under " << SystEqu[k][k] << " is " << max << ", at positioni " << holdi;
	for (int c = 0; c < n; c++)
	{
		temp = SystEqu[k][c];
		SystEqu[k][c] = SystEqu[holdi][c];
		SystEqu[holdi][c] = temp;
	}
	temp = SystAnsw[k];
	SystAnsw[k] = SystAnsw[holdi];
	SystAnsw[holdi] = temp;
	cout << "  " << SystAnsw[k] << endl;


}

void Printe()
{
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++)
			cout << SystEqu[r][c] << " ";
		cout << "   " <<SystAnsw[r]<<endl;
	}
}

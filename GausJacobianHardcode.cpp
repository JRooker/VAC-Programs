#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
void Printe();
void pivot(int);
void Gaus();
void Jacobian();
int const L = 3;
double SystEqu[L][L] = { { 3,-.1,-.2 },{ .1,7,-.3 },{ .3,-.2,10 } };
double SystAnsw[L] = { 7.85,-19.3,71.4 };
double Xn[L] = { 0,0,0 };
int main()
{
	Jacobian();
}



void Jacobian()
{
	double factor = 0;
	double error = 1;
	const int N = 100;
	int n = 0;
	double x1[N][L];
	x1[0][0] = 1;
	x1[1][0] = 1;
	x1[2][0] = 1;
	while (n < N - 1 && error >= pow(10, -19))
	{

		for (int r = 0; r < L; r++)
		{
			x1[r][n+1] = SystAnsw[r] / SystEqu[r][r];
				for(int i = 0; i < L; i++)
				{
					if (r == i)
						cout << ' ';
					else
						if(i<r)
							x1[r][n + 1] -= SystEqu[r][i] * x1[i][n+1] / SystEqu[r][r];
						else
						x1[r][n + 1] -= SystEqu[r][i]*x1[i][n]/SystEqu[r][r];
				}
		}
		error = (abs(x1[0][n + 1] - x1[0][n]) + abs(x1[1][n + 1] - x1[1][n]) + abs(x1[2][n + 1] - x1[2][n])) / (double)L;
		cout << "error  " << error << ",  N " << n << ": " << x1[0][n] << " " << x1[1][n] << " " << x1[2][n] << "  top part " << abs(x1[0][n + 1] - x1[0][n]) + abs(x1[1][n + 1] - x1[1][n]) + abs(x1[2][n + 1] - x1[2][n]) << endl;

		n++;

	}
	int q;
	cin >> q;
}

void Gaus()
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

	for (int k = 0; k < L - 1; k++)
	{
		if (SystEqu[k][k] == 0)
			pivot(k);
		for (int i = k + 1; i < L; i++)
		{
			factor = SystEqu[i][k] / SystEqu[k][k];
			cout << "i " << i << ", k " << k << " , FActor = " << SystEqu[i][k] << "/" << SystEqu[k][k] << " = " << factor << endl;
			for (int j = k; j < L; j++)
				SystEqu[i][j] = SystEqu[i][j] - factor * SystEqu[k][j];
			SystAnsw[i] = SystAnsw[i] - factor * SystAnsw[k];
			Printe(); cout << endl;
		}
	}
	double sum;
	if (SystEqu[L - 1][L - 1] == 0)
		cout << "This matrix will not work" << endl;
	Xn[L - 1] = SystAnsw[L - 1] / SystEqu[L - 1][L - 1];
	for (int i = L - 2; i >= 0; i--)
	{
		sum = SystAnsw[i];
		for (int j = i + 1; j < L; j++)
			sum = sum - SystEqu[i][j] * Xn[j];
		Xn[i] = sum / SystEqu[i][i];
	}

	cout << endl << endl << " The solution is ";
	for (int i = 0; i < L; i++)
		cout << Xn[i] << " ";

	int q;
	cin >> q;
}

void pivot(int k)
{
	double temp = 0;
	double max = 0;
	int holdi = -1;;
	for (int i = k; i < L; i++)
		if (SystEqu[i][k] > max)
		{
			max = SystEqu[i][k];
			holdi = i;
		}
	if (holdi == -1)
		return;
	cout << "K = " << k << ", THE bigges element under " << SystEqu[k][k] << " is " << max << ", at positioni " << holdi;
	for (int c = 0; c < L; c++)
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
	for (int r = 0; r < L; r++) {
		for (int c = 0; c < L; c++)
			cout << SystEqu[r][c] << " ";
		cout << "   " << SystAnsw[r] << endl;
	}
}
/*#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
void Printe();
void pivot(int);
void Gaus();
void Jacobian();
int const n = 3;
double SystEqu[n][n] = { { 3,-.1,-.2 },{ .1,7,-.3 },{ .3,-.2,10 } };
double SystAnsw[n] = { 7.55,-19.3,71.4 };
double Xn[n] = { { 0,0,0 },{0,0,0},{0,0,0} };
int main()
{
Jacobian();
}



void Jacobian()
{
bool error = true;
const int N = 100;
int n = 0;
vector <double> x1(N), x2(N), x3(N);
while (n < N && error)
{
for(int varcount=0;varcount<n;varcount++)
for (int r = 0; r < n; r++)
x[varcount][n + 1] = -SystEqu[r][1]*x2[n] / SystEqu [r][0]-SystEqu[r][2]*x3[n] / SystEqu[r][0] + SystAnsw[r] / SystEqu[r][0];


}
}*/
#include <iostream>
#include <string>
#include <vector>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


double f(double x)
{
	double a = pow(x,2)+1;
	return a;
}
double fprime(double x)
{
	double b = 2*x;
	return b;
}

using namespace std;
const int rows = 4;
const int cols = 3;
double factorial(double);
void Transp3(int[rows][cols]);
void bankcall1();
void NumberSwitch2();
double Sinapp8();
void Tridiagonal5();
int NewtonMethod4();
void randomizer6();
void Ret_Ana7();
void Ass2b9();

int main() {
	int answer = 0;
	int total = 0;

	int m[rows][cols] = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 },{ 10,11,12 } };

	bool keep = true;
	while (keep == true)
	{
		cout << "Program 1 or 2 or 3 or 4?" << endl;
		cin >> answer;
		if (answer == 1)
			bankcall1();
		else if (answer == 2)
			NumberSwitch2();
		else if (answer == 3)
			Transp3(m);
		else if (answer == 4)
			NewtonMethod4();
		else if (answer == 5)
			Tridiagonal5();
		else if (answer == 6)
			randomizer6();
		else if (answer == 7)
			Ret_Ana7();
		else if (answer == 8)
		{
			double ans = Sinapp8();
			cout << ans << endl;
		}
		else if (answer == 9)
			Ass2b9();
		else
			keep = false;
	}
	int a;
	cin >> a;
	return 0;

}
void Ass2b9()
{
	double val = 1.145434;
	int decimal = 2;
	double temp = val * pow(10,decimal);
	temp = round(temp);
	val = temp / pow(10, decimal);
	cout << val;


}
double Sinapp8()
{
	double xval = 0;
	double answer = 0;
	cout << "sin(x), what x ";
	cin >> xval;
	cout << "\n what accruacy? ";
	int acure = 0;
	cin >> acure;
	for (int n = 0; n < acure; n++)
	{
		answer += ((pow(-1, n)*pow(xval, (2 * n + 1))) / (factorial((2 * n + 1))));
		cout << answer << endl;
	}
	return answer;
}
void Ret_Ana7()
{
	cin.ignore(1);
	cout << "Insert the word to be returned backwards ";
	string useinp;
	getline(cin, useinp);
	int length = size(useinp);
	string reverse = useinp;
	int count = 0;
	for(int q=length-1;q>=0;q--)
	{
		reverse[count] = useinp[q];
		count++;
	}
	cout << endl << "The word reversed : "<< reverse<<endl<<endl<<endl<<"Part two:"<<endl;
	string word1, word2;

	cout << " please submit two words one at a time to be tested for anagram " << endl;
	getline(cin, word1);
	getline(cin, word2);
	count = 0;
	bool moralkeep = false;
	bool masterkeep = true;
	for (int a = 0; a < (int)word1.size(); a++)
	{
		for (int b = 0; b < (int)word1.size(); b++)
			if (word1[b] == word2[a])
			{
				if(!moralkeep)
					word1[b] = ' ';
				moralkeep = true;
			}
		if (!moralkeep)
			masterkeep = false;
		cout << "moralkeep " << moralkeep << " looking for " << word2[a] << ", From word2: "<< word2<< ", in word1: "<< word1<< ", also masterkeep " << masterkeep << endl;
		moralkeep = false;
	}
	if(masterkeep == true)
		cout << "These two words are anagrams" << endl;
	else
		cout << "These two words arent anagrams" << endl;
}
void randomizer6()
{
	cout << "how many  words would you like to print?";
	int answer = 0;
	int count = 0;
	cin >> answer;
	for (int a = 0; a < answer; a++)
	{
		for (int b = 0; b <= rand() % 10; b++)
		{
			count++;
			char r = 'a' + rand() % 26;
			cout << r;
			if (count >= 49)
			{
				count = 0;
				cout << endl;
			}
		}
		count++;
		cout << " ";
	}
}
void Tridiagonal5()
{
	vector<double> vectorE(3, -1);
	vector<double> vectorF(4, 2.04);
	vector<double> vectorG(3, -1);
	vector<double> vectorR = { {40.8},{0.8},{0.8},{200.8} };
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
		cout << a <<"hey";
		vectorF[a] = vectorF[a] - (vectorE[a-1] / vectorF[a - 1]) * vectorG[a - 1];
		vectorR[a] = vectorR[a] - (vectorE[a-1] / vectorF[a - 1]) * vectorR[a - 1];
	}
	cout << "check " << (int)vectorF.size()-1;
	for (int a = (int)vectorF.size()-1; a >= 0; a--)
	{
		if (a == (int)vectorF.size()-1)
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
	

}
int NewtonMethod4()
{
	double x = 0;
	double initial, error, fx, fx1;
	cout.precision(6);
	cout.setf(ios::fixed);
	cout << "Enter initial guess" << endl;
	cin >> initial;
	cout << "Enter accuracy" << endl;
	cin >> error;
	cout << "Term" << "           " << "Term +1" << "             " << "Accuracy" << endl;
	while (fabs((initial - x) / initial) >= error)
	{
		x = initial;
		fx = f(x);
		fx1 = fprime(x);
		initial = x - (fx / fx1);
		cout << x << "     " << initial << "           " << abs((initial - x) / initial) << endl;
	}
	cout << "Root is " << initial << endl;
	cin >> x;
	return 0;
}
void Transp3(int m[rows][cols])
{

	int total = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "[" << i << "][" << j << "]= " << m[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl << endl;
	int temp[cols][rows];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			temp[j][i] = m[i][j];
		}
	}
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << "[" << i << "][" << j << "]= " << temp[i][j] << "  ";
		}
		cout << endl;
	}
}
void NumberSwitch2()
{
	int a = 0;
	int firstnum = 0;
	int newnum = 0;
	int userinp = 0;
	int count = 1;
	cout << "Input your number: ";
	cin >> userinp;
	while (userinp%count != userinp) //finding the correct
	{
		count *= 10;
	}
	int initcount = count / 10;
	int multiply = 1;
	int first = userinp % 10;
	int last = 0;
	int tobeadd = 0;
	while (count != 10)
	{
		count /= 10;
		tobeadd = (userinp / count) % 10;
		cout << "multiplier " << multiply << endl;
		cout << "to be added " << tobeadd * multiply << endl;

		if (initcount == count)
		{
			last = userinp % 10;
			newnum = initcount * last;
		}
		newnum += tobeadd * multiply;
		multiply *= 10;

	}
	cout << newnum;
} 
void bankcall1()
{
	int balance = 1000;
	int depwith = 0;
	int a = 0;

	while (balance > 0)
	{
		cout << "Current Balance :" << balance << endl;
		cout << "Deposit or withdrawl amount?  ";
		cin >> depwith;
		if ((balance += depwith) < 0)
		{
			cout << "You cannot make that deposit, you only have " << balance << " left" << endl;
			balance -= depwith;
		}
	}
}
double factorial(double start)
{
	double ans = 1;
	for (double q = start; start > 0; start--)
	{
		ans *= start;
	}
	return ans;
}
/*  WORD CLOUD (using C++ 14)
Author : YADAV SUMITKUMAR
CSE Sec-C
Reg.No : 149105478
to compile: g++ main.cpp -std=c++0x
*/
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
int CurRow=0;
int CurCol=0;

bool SpecialCase();
void printer();
bool horizontal();
bool vertical();
bool box();
bool diagonal();
void nextment();
void backment();
class InSquare
{
public: int number;
		bool official;
		int box;
		bool justswitched;
		InSquare(int num, bool tr, int b)
		{
			box = b;
			number = num;
			official = tr;
			justswitched = false;
		}
		InSquare(int b)
		{
			box = b;
			number = 0;
			official = false;
			justswitched = false;
		}
		bool Official()
		{
			return official;
		}
};

/*
InSquare S1 = InSquare(2, true, 1);
InSquare S2 = InSquare(6, true, 1);
InSquare S3 = InSquare(7, true, 2);
InSquare S4 = InSquare(1, true, 1);
InSquare S5 = InSquare(6, true, 2);
InSquare S6 = InSquare(8, true, 2);
InSquare S7 = InSquare(7, true, 2);
InSquare S8 = InSquare(9, true, 1);
InSquare S9 = InSquare(1, true, 1);
InSquare S10 = InSquare(9, true, 3);
InSquare S11 = InSquare(4, true, 4);
InSquare S12 = InSquare(5, true, 5);
InSquare S13 = InSquare(8, true, 6);
InSquare S14 = InSquare(2, true, 4);
InSquare S15 = InSquare(1, true, 5);
InSquare S16 = InSquare(4, true, 5);
InSquare S17 = InSquare(4, true, 6);
InSquare S18 = InSquare(6, true, 4);
InSquare S19 = InSquare(2, true, 5);
InSquare S20 = InSquare(9, true, 6);
InSquare S21 = InSquare(5, true, 7);
InSquare S22 = InSquare(3, true, 9);
InSquare S23 = InSquare(2, true, 9);
InSquare S24 = InSquare(8, true, 8);
InSquare S25 = InSquare(9, true, 8);
InSquare S26 = InSquare(3, true, 8);
InSquare S27 = InSquare(7, true, 9);
InSquare S28 = InSquare(4, true, 8);
InSquare S29 = InSquare(4, true, 9);
InSquare S30 = InSquare(5, true, 9);
InSquare S31 = InSquare(3, true, 9);
InSquare S32 = InSquare(6, true, 9);
InSquare S33 = InSquare(7, true, 9);
InSquare S34 = InSquare(3, true, 9);
InSquare S35 = InSquare(1, true, 9);
InSquare S36 = InSquare(8, true, 9);
InSquare map1[9][9] =
{
{ InSquare(1), InSquare(1), InSquare(1), S1, S2, InSquare(2), S3, InSquare(3), S4 },
{ S5, S6, InSquare(1), InSquare(2), S7, InSquare(2), InSquare(3), S8, InSquare(3) },
{ S9, S10, InSquare(1), InSquare(2), InSquare(2), S11, S12, InSquare(3), InSquare(3) },
{ S13, S14, InSquare(4), S15, InSquare(5), InSquare(5), InSquare(6), S16, InSquare(6) },
{ InSquare(4), InSquare(4), S17, S18, InSquare(5), S19, S20, InSquare(6), InSquare(6) },
{ InSquare(4), S21, InSquare(4), InSquare(5), InSquare(5), S22, InSquare(6), S23, S24 },
{ InSquare(7), InSquare(7), S25, S26, InSquare(8), InSquare(8), InSquare(9), S27, S28 },
{ InSquare(7), S29, InSquare(7), InSquare(8), S30, InSquare(8), InSquare(9),S31 , S32 },
{ S33, InSquare(7), S34, InSquare(8), S35, S36, InSquare(9), InSquare(9), InSquare(9) },
};*/

// OR YOU CAN RUN THIS ONE
InSquare S1 = InSquare(5, true,1);
InSquare S2 = InSquare(3, true,1);
InSquare S3 = InSquare(7, true,2);
InSquare S4 = InSquare(6, true,1);
InSquare S5 = InSquare(1, true,2);
InSquare S6 = InSquare(9, true,2);
InSquare S7 = InSquare(5, true,2);
InSquare S8 = InSquare(9, true,1);
InSquare S9 = InSquare(8, true,1);
InSquare S10 = InSquare(6, true,3);
InSquare S11 = InSquare(8, true,4);
InSquare S12 = InSquare(6, true,5);
InSquare S13 = InSquare(3, true,6);
InSquare S14 = InSquare(4, true,4);
InSquare S15 = InSquare(8, true,5);
InSquare S16 = InSquare(3, true,5);
InSquare S17 = InSquare(1, true,6);
InSquare S18 = InSquare(7, true,4);
InSquare S19 = InSquare(2, true,5);
InSquare S20 = InSquare(6, true,6);
InSquare S21 = InSquare(6, true,7);
InSquare S22 = InSquare(2, true,9);
InSquare S23 = InSquare(8, true,9);
InSquare S24 = InSquare(4, true,8);
InSquare S25 = InSquare(1, true,8);
InSquare S26 = InSquare(9, true,8);
InSquare S27 = InSquare(5, true,9);
InSquare S28 = InSquare(8, true,8);
InSquare S29 = InSquare(7, true,9);
InSquare S30 = InSquare(9, true,9);
InSquare map1[9][9] = 
{
{ S1, S2, InSquare(1), InSquare(2), S3, InSquare(2), InSquare(3), InSquare(3), InSquare(3) },
{ S4, InSquare(1), InSquare(1), S5, S6, S7, InSquare(3), InSquare(3), InSquare(3) },
{ InSquare(1), S8, S9, InSquare(2), InSquare(2), InSquare(2), InSquare(3), S10, InSquare(3) },
{ S11, InSquare(4), InSquare(4), InSquare(5), S12, InSquare(5), InSquare(6), InSquare(6), S13 },
{ S14, InSquare(4), InSquare(4), S15, InSquare(5), S16, InSquare(6), InSquare(6), S17 },
{ S18, InSquare(4), InSquare(4), InSquare(5), S19, InSquare(5), InSquare(6), InSquare(6), S20 },
{ InSquare(7), S21, InSquare(7), InSquare(8), InSquare(8), InSquare(8), S22, S23, InSquare(9) },
{ InSquare(7), InSquare(7), InSquare(7), S24, S25, S26, InSquare(9), InSquare(9), S27 },
{ InSquare(7), InSquare(7), InSquare(7), InSquare(8), S28, InSquare(8), InSquare(9), S29, S30 },
};



	bool solved = false;

	int bigboi = 0;
int main()
{
	int hold;
	bool first = true;
	bool thisfirst = true;
	cout << "entering loop" << endl;
	printer();
	while (!solved)
	{
		
		{
			//cout << endl<<"New Loop, Row, " << CurRow << ", Col " << CurCol << " Bigboi  " << bigboi << ", Current value ,"<<map1[CurRow][CurCol].number<<"   ";
			//printer();
		}
		/*if ((map1[0][2].number == 4)&&first)
		{
			first = false;
			printer();
			cin >> hold;
		}
		if ((map1[0][3].number == 6)&& (map1[0][2].number == 4) && thisfirst)
		{
			thisfirst = false;
			printer();
			cin >> hold;
		}
		if(!thisfirst)
		cout << endl<<"New Loop, Row, " << CurRow << ", Col " << CurCol << " Bigboi  " << bigboi << ", Current value ,"<<map1[CurRow][CurCol].number<<"   ";
		if (!thisfirst)
		{
			if (CurCol == 5&& CurRow ==0)
			{
				cout << endl << endl << endl << "JUST CHANGED COL 5 FROM " << map1[CurRow][CurCol].number << " to " << map1[CurRow][CurCol].number + 1 << endl << endl << endl;
				printer();
			}
		}*/
		if (!map1[CurRow][CurCol].Official()) // if its not a given value
		{
			//cout << "1st";
			map1[CurRow][CurCol].number = map1[CurRow][CurCol].number + 1; //increment number
			if (map1[CurRow][CurCol].number != 10) //If it was the last try
			{
				//cout << "2nd";
				if (horizontal()&& vertical() && box()) //if the number works
				{
					//cout << "3rd";
					nextment();
					bigboi++;
				}
			}
			else // it was the last try
			{
				//cout << "4th";
				map1[CurRow][CurCol].number = 0;
				map1[CurRow][CurCol].justswitched = true;
				backment();
			}
		}
		else // if its a given value
		{
			if (SpecialCase())
			{
				//cout << "  SPECIAL CASE   ";
				map1[CurRow][CurCol].justswitched = true;
				backment();
			}
			else //cout << "5th";
				nextment();
		}
	}
	printer();
	int count = 0;
	cin >> count;
	return 0;
}



	bool horizontal()
	{
		bool duplicate = false;
		for (int n = 0; n < 9; n++)
		{
			if (n == CurCol) {}
			else if (map1[CurRow][n].number == map1[CurRow][CurCol].number)
				duplicate = true;
		}
		//if(bigboi >3000)
		//cout << "Horizontal " << !duplicate;
		return !duplicate;
	}
	bool vertical()
	{
		bool duplicate = false;
		for (int n = 0; n < 9; n++)
		{
			if (n == CurRow) {}
			else if (map1[n][CurCol].number == map1[CurRow][CurCol].number)
				duplicate = true;
		}
		//if (bigboi >3000)
		//cout << "vertical " << !duplicate;
		return !duplicate;
	}
	bool box()
	{
		int r = 0;
		int c = 0;
		if (2 == map1[CurRow][CurCol].box)
		{
			r = 0;
			c = 3;
		}
		else if (3 == map1[CurRow][CurCol].box)
		{
			r = 0;
			c = 6;
		}
		else if (4 == map1[CurRow][CurCol].box)
		{
			r = 3;
			c = 0;
		}
		else if (5 == map1[CurRow][CurCol].box)
		{
			r = 3;
			c = 3;
		}
		else if (6 == map1[CurRow][CurCol].box)
		{
			r = 3;
			c = 6;
		}
		else if (7 == map1[CurRow][CurCol].box)
		{
			r = 6;
			c = 0;
		}
		else if (8 == map1[CurRow][CurCol].box)
		{
			r = 6;
			c = 3;
		}
		else if (9 == map1[CurRow][CurCol].box)
		{
			r = 6;
			c = 6;
		}
		bool duplicate = false; 
		//if (bigboi > 3000)
			//cout << "    Box " << map1[CurRow][CurCol].box << "  r = " << r << ",  c= " << c << "start  " << duplicate << endl;
		for (int rr = r; rr < r + 3; rr++)
		{
			for (int cc = c; cc < c + 3; cc++)
			{
				if (rr == CurRow && cc == CurCol) {}
				else if (map1[rr][cc].number == map1[CurRow][CurCol].number)
					duplicate = true;
				//if (CurCol == 5 && CurRow == 0)
				//	cout << "rr " << rr << " cc " << cc << " duplicate? " << duplicate << endl;

			}
		}

		
		return !duplicate;
	}
	bool diagonal()
	{
		if (CurCol == CurRow)
		{
			bool duplicate = false;
			for (int n = 0; n < 9; n++)
			{
				if ((n == CurCol) && (n == CurRow)) {}
				else if (map1[n][n].number == map1[CurRow][CurCol].number)
					duplicate = true;
			}
			//cout << "    diaganal " << !duplicate;
			return !duplicate;
		}
		else if ((CurCol + CurRow == 8))
		{
			bool duplicate = false;
			for (int n = 0; n < 9; n++)
			{
				if ((n == CurRow) && ((8 - n) == CurCol)) {}
				else if (map1[n][8 - n].number == map1[CurRow][CurCol].number)
					duplicate = true;
			}
			//cout << "diaganal " << !duplicate;
			return !duplicate;
		}
		else
			return true;
	}
	void nextment()
	{
		if (CurCol == 8 && CurRow == 8)
			solved = true;
		else if (CurCol == 8)
		{
			CurCol = 0;
			CurRow++;
		}
		else
		{
			CurCol++;
		}
		//cout << "\\nextment loop  " <<CurCol<<"//   ";
	}
	void backment()
	{
		if (CurCol == 0)
		{
			CurCol = 8;
			CurRow--;
		}
		else
		{
			CurCol--;
		}
	}
	bool SpecialCase()
	{
		nextment();
		bool temp = map1[CurRow][CurCol].justswitched;
		if(temp == true)
			map1[CurRow][CurCol].justswitched = false;
		backment();
		return temp;
	}
	void printer()
	{
		cout << endl;
		int count = 1;
		for (int r = 0; r < 9; r++)
		{
			for (int c = 0; c < 9; c++)
			{
				cout << map1[r][c].number << ' ';
				if (count % 3 == 0)
					cout << ' ';
				count++;
			}
			cout << endl;
		}
	}
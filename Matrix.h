#include <iostream>

using namespace::std;

class Matrix
{
private:
	int Board[4][4];
	friend class Tree;
public:
	void TakerUSER()
	{
		cout << "FILL THE GAME BOARD WITH THE NUMBERS(0-8):" << endl << endl;
		cout << "-------------------------------" << endl;
		cout << "|         |         |         |" << endl;
		cout << "|    a    |    b    |    c    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << "-------------------------------" << endl;
		cout << "|         |         |         |" << endl;
		cout << "|    d    |    e    |    f    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << "-------------------------------" << endl;
		cout << "|         |         |         |" << endl;
		cout << "|    g    |    h    |    i    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << "-------------------------------" << endl;
		cout << endl << "The Board Will Be Printed Like Above!" << endl << endl;

		cout << "----------------------------------" << endl;

		cout << "a: ";
		cin >> Board[1][1];
		cout << "b: ";
		cin >> Board[1][2];
		cout << "c: ";
		cin >> Board[1][3];

		cout << "----------------------------------" << endl;

		cout << "d: ";
		cin >> Board[2][1];
		cout << "e: ";
		cin >> Board[2][2];
		cout << "f: ";
		cin >> Board[2][3];

		cout << "----------------------------------" << endl;

		cout << "g: ";
		cin >> Board[3][1];
		cout << "h: ";
		cin >> Board[3][2];
		cout << "i: ";
		cin >> Board[3][3];

		cout << "----------------------------------" << endl;
	}
	void Taker(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
		Board[1][1] = a;
		Board[1][2] = b;
		Board[1][3] = c;

		Board[2][1] = d;
		Board[2][2] = e;
		Board[2][3] = f;

		Board[3][1] = g;
		Board[3][2] = h;
		Board[3][3] = i;
	}
	void Printer() {

		cout << "-------------------------------" << endl;

		cout << "|         |         |         |" << endl;

		cout << "|    ";
		if (Board[1][1] != 0)
		{
			cout << Board[1][1];
		}
		else
		{
			cout << " ";
		}
		cout << "    |    ";
		if (Board[1][2] != 0)
		{
			cout << Board[1][2];
		}
		else
		{
			cout << " ";
		}
		cout << "    |    ";
		if (Board[1][3] != 0)
		{
			cout << Board[1][3];
		}
		else
		{
			cout << " ";
		}
		cout << "    |" << endl;

		cout << "|         |         |         |" << endl;

		cout << "-------------------------------" << endl;

		cout << "|         |         |         |" << endl;

		cout << "|    ";
		if (Board[2][1] != 0)
		{
			cout << Board[2][1];
		}
		else
		{
			cout << " ";
		}
		cout << "    |    ";
		if (Board[2][2] != 0)
		{
			cout << Board[2][2];
		}
		else
		{
			cout << " ";
		}
		cout << "    |    ";
		if (Board[2][3] != 0)
		{
			cout << Board[2][3];
		}
		else
		{
			cout << " ";
		}
		cout << "    |" << endl;

		cout << "|         |         |         |" << endl;

		cout << "-------------------------------" << endl;

		cout << "|         |         |         |" << endl;

		cout << "|    ";
		if (Board[3][1] != 0)
		{
			cout << Board[3][1];
		}
		else
		{
			cout << " ";
		}
		cout << "    |    ";
		if (Board[3][2] != 0)
		{
			cout << Board[3][2];
		}
		else
		{
			cout << " ";
		}
		cout << "    |    ";
		if (Board[3][3] != 0)
		{
			cout << Board[3][3];
		}
		else
		{
			cout << " ";
		}
		cout << "    |" << endl;

		cout << "|         |         |         |" << endl;

		cout << "-------------------------------" << endl << endl << endl;
	}
};
#include <iostream>
#include <queue>
#include <list>
#include "Matrix.h"

using namespace::std;

class Tree
{
private:
	struct Node
	{
		Matrix Board;

		Node* LeftSwap = NULL;
		Node* RightSwap = NULL;
		Node* TopSwap = NULL;
		Node* BottomSwap = NULL;

		Node* Parent = NULL;

		Node* ResultNext = NULL;

		Node* Next = NULL;
	};
	Node* HeadMatrix = new Node;
	
	Node* DefaultMatrix = new Node;


	queue<Node*> Queue;
	list<Node*> List;


public:
	Tree()
	{
		DefaultMatrix->Board.Board[1][1] = 0;
		DefaultMatrix->Board.Board[1][2] = 1;
		DefaultMatrix->Board.Board[1][3] = 2;

		DefaultMatrix->Board.Board[2][1] = 3;
		DefaultMatrix->Board.Board[2][2] = 4;
		DefaultMatrix->Board.Board[2][3] = 5;

		DefaultMatrix->Board.Board[3][1] = 6;
		DefaultMatrix->Board.Board[3][2] = 7;
		DefaultMatrix->Board.Board[3][3] = 8;

		HeadMatrix->Board.TakerUSER();
	}
	Node* HeadChecker() {
		if (Comparator(HeadMatrix))
		{
			HeadMatrix->Board.Printer();
			cout << "Already at the Solved Stage!" << endl;
			return HeadMatrix;
		}
		else
		{
			Queue.push(HeadMatrix);
			return NULL;
		}
	}
	void QueueWork()
	{
		Node* temp1 = NULL;
		Node* temp2 = NULL;
		while (!Queue.empty())
		{
			temp1 = Queue.front();
			Queue.pop();
			temp2 = ChildAdder(temp1);
			
			if (temp2 != NULL)
			{
				break;
			}
		}
		while (temp2 != NULL)
		{
			List.push_front(temp2);
			temp2 = temp2->Parent;
		}
	}
	//	NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[2][2], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
	Node* ChildAdder(Node* temp)	// here we will assign the parent poniter to the poniter...
	{
		if (temp->Board.Board[1][1] == 0)
		{
			temp->RightSwap = NodeAdder(temp->Board.Board[1][2], temp->Board.Board[1][1], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[2][2], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
			temp->BottomSwap = NodeAdder(temp->Board.Board[2][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[1][1], temp->Board.Board[2][2], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
		}
		else if (temp->Board.Board[1][2] == 0)
		{
			temp->LeftSwap = NodeAdder(temp->Board.Board[1][2], temp->Board.Board[1][1], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[2][2], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
			temp->RightSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][3], temp->Board.Board[1][2], temp->Board.Board[2][1], temp->Board.Board[2][2], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
			temp->BottomSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[2][2], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[1][2], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
		}
		else if (temp->Board.Board[1][3] == 0)
		{
			temp->LeftSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][3], temp->Board.Board[1][2], temp->Board.Board[2][1], temp->Board.Board[2][2], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
			temp->BottomSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[2][3], temp->Board.Board[2][1], temp->Board.Board[2][2], temp->Board.Board[1][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
		}
		else if (temp->Board.Board[2][1] == 0)
		{
			temp->RightSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[2][2], temp->Board.Board[2][1], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
			temp->TopSwap = NodeAdder(temp->Board.Board[2][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[1][1], temp->Board.Board[2][2], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
			temp->BottomSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[3][1], temp->Board.Board[2][2], temp->Board.Board[2][3], temp->Board.Board[2][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
		}
		else if (temp->Board.Board[2][2] == 0)
		{
			temp->LeftSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[2][2], temp->Board.Board[2][1], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
			temp->RightSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[2][3], temp->Board.Board[2][2], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
			temp->TopSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[2][2], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[1][2], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
			temp->BottomSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[3][2], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[2][2], temp->Board.Board[3][3]);
		}
		else if (temp->Board.Board[2][3] == 0)
		{
			temp->LeftSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[2][3], temp->Board.Board[2][2], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
			temp->TopSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[2][3], temp->Board.Board[2][1], temp->Board.Board[2][2], temp->Board.Board[1][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
			temp->BottomSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[2][2], temp->Board.Board[3][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[2][3]);
		}
		else if (temp->Board.Board[3][1] == 0)
		{
			temp->RightSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[2][2], temp->Board.Board[2][3], temp->Board.Board[3][2], temp->Board.Board[3][1], temp->Board.Board[3][3]);
			temp->TopSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[3][1], temp->Board.Board[2][2], temp->Board.Board[2][3], temp->Board.Board[2][1], temp->Board.Board[3][2], temp->Board.Board[3][3]);
		}
		else if (temp->Board.Board[3][2] == 0)
		{
			temp->LeftSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[2][2], temp->Board.Board[2][3], temp->Board.Board[3][2], temp->Board.Board[3][1], temp->Board.Board[3][3]);
			temp->RightSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[2][2], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[3][3], temp->Board.Board[3][2]);
			temp->TopSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[3][2], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[2][2], temp->Board.Board[3][3]);
		}
		else if (temp->Board.Board[3][3] == 0)
		{
			temp->LeftSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[2][2], temp->Board.Board[2][3], temp->Board.Board[3][1], temp->Board.Board[3][3], temp->Board.Board[3][2]);
			temp->TopSwap = NodeAdder(temp->Board.Board[1][1], temp->Board.Board[1][2], temp->Board.Board[1][3], temp->Board.Board[2][1], temp->Board.Board[2][2], temp->Board.Board[3][3], temp->Board.Board[3][1], temp->Board.Board[3][2], temp->Board.Board[2][3]);
		}


		if (temp->Parent == NULL)
		{
			if (temp->LeftSwap != NULL)
			{
				if (Comparator(temp->LeftSwap))
				{
					temp->LeftSwap->Parent = temp;
					return temp->LeftSwap;
				}
				else
				{
					temp->LeftSwap->Parent = temp;
					Queue.push(temp->LeftSwap);
				}
				//		add leftswap to queue...
				//temp->LeftSwap->Parent = temp;
				//Queue.push(temp->LeftSwap);
			}
			if (temp->RightSwap != NULL)
			{
				if (Comparator(temp->RightSwap))
				{
					temp->RightSwap->Parent = temp;
					return temp->RightSwap;
				}
				else
				{
					temp->RightSwap->Parent = temp;
					Queue.push(temp->RightSwap);
				}
				//		add rightswap to queue...
				//temp->RightSwap->Parent = temp;
				//Queue.push(temp->RightSwap);
			}
			if (temp->TopSwap != NULL)
			{
				if (Comparator(temp->TopSwap))
				{
					temp->TopSwap->Parent = temp;
					return temp->TopSwap;
				}
				else
				{
					temp->TopSwap->Parent = temp;
					Queue.push(temp->TopSwap);
				}
				//		add topswap to queue...
				//temp->TopSwap->Parent = temp;
				//Queue.push(temp->TopSwap);
			}
			if (temp->BottomSwap != NULL)
			{
				if (Comparator(temp->BottomSwap))
				{
					temp->BottomSwap->Parent = temp;
					return temp->BottomSwap;
				}
				else
				{
					temp->BottomSwap->Parent = temp;
					Queue.push(temp->BottomSwap);
				}
				//		add bottomswap to queue...
				//temp->BottomSwap->Parent = temp;
				//Queue.push(temp->BottomSwap);
			}
		}
		else
		{
			if (temp->LeftSwap != NULL)
			{
				if (!Comparator(temp->Parent, temp->LeftSwap))
				{
					if (Comparator(temp->LeftSwap))
					{
						temp->LeftSwap->Parent = temp;
						return temp->LeftSwap;
					}
					else
					{
						temp->LeftSwap->Parent = temp;
						Queue.push(temp->LeftSwap);
					}
				}
				else
				{
					temp->LeftSwap = NULL;
				}
			}




			if (temp->RightSwap != NULL)
			{
				if (!Comparator(temp->Parent, temp->RightSwap))
				{
					if (Comparator(temp->RightSwap))
					{
						temp->RightSwap->Parent = temp;
						return temp->RightSwap;
					}
					else
					{
						temp->RightSwap->Parent = temp;
						Queue.push(temp->RightSwap);
					}
				}
				else
				{
					temp->RightSwap = NULL;
				}
			}




			if (temp->TopSwap != NULL)
			{
				if (!Comparator(temp->Parent, temp->TopSwap))
				{
					if (Comparator(temp->TopSwap))
					{
						temp->TopSwap->Parent = temp;
						return temp->TopSwap;
					}
					else
					{
						temp->TopSwap->Parent = temp;
						Queue.push(temp->TopSwap);
					}
				}
				else
				{
					temp->TopSwap = NULL;
				}
			}




			if (temp->BottomSwap != NULL)
			{
				if (!Comparator(temp->Parent, temp->BottomSwap))
				{
					if (Comparator(temp->BottomSwap))
					{
						temp->BottomSwap->Parent = temp;
						return temp->BottomSwap;
					}
					else
					{
						temp->BottomSwap->Parent = temp;
						Queue.push(temp->BottomSwap);
					}
				}
				else
				{
					temp->BottomSwap = NULL;
				}
			}
		}
		return NULL;
	}
	bool Comparator(Node* temp1, Node* temp2 = NULL)	//if all the numbers in both boards are same the function will return true...
	{
		if (temp2 == NULL)
		{
			temp2 = DefaultMatrix;
		}
		for (int i = 1; i < 4; i++)
		{
			for (int j = 1; j < 4; j++)
			{
				if (temp1->Board.Board[i][j] != temp2->Board.Board[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
	Node* NodeAdder(int a, int b, int c, int d, int e, int f, int g, int h, int i)
	{
		Node* temp = new Node;
		temp->Board.Board[1][1] = a;
		temp->Board.Board[1][2] = b;
		temp->Board.Board[1][3] = c;

		temp->Board.Board[2][1] = d;
		temp->Board.Board[2][2] = e;
		temp->Board.Board[2][3] = f;

		temp->Board.Board[3][1] = g;
		temp->Board.Board[3][2] = h;
		temp->Board.Board[3][3] = i;

		return temp;
	}
	void Display() {
		int i = 1;
		Node* temp = NULL;
		while (!List.empty())
		{
			temp = List.front();
			List.pop_front();
			temp->Board.Printer();
			if (!List.empty())
			{
				cout << "Step " << i << ":" << endl;
				i++;
			}

		}
		cout << "Solved!" << endl << endl;
	}
};


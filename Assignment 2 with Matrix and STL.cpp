//		Conceps and Coding By:
//				-> M Qais Sultani (2018314)
//
//		This Code need its Two Header files: 'Matrix.h' ; 'Tree.h'.
//
//
//		WORKING OF PROGRAM:
//			1.	First the program will create the tree.(In constructor of the tree it will make a game Board which will
//				be the final state, used for comparission.
//			2.	Then it will check if the user given board is same as final state, if it is true then it will simply
//				stop the further program execution as it does not need to be execut.
//			3.	If above is not the case then, it will just add the user given board to the Queue.
//			4.	Now, a board is poped from queue.
//			5.	Create its childern.
//			6.	Check each child whether it is same as final or not.
//			7.	If same is found then it will show all the boards from user given boards to this board.
//			8.	If it is not same then it will add it to the queue.
//
//			9.	Step 4 to Step 8 will repeat again and again till final state is obtained. 


#include <iostream>
#include "Tree.h"

using namespace::std;

int main()
{
	Tree A;
	if (A.HeadChecker() != NULL)
	{
		return 0;
	}
	A.QueueWork();				//	queueWork
	A.Display();				//	display
}

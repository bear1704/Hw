#include <iostream>
#include <fstream>

#define BINGO_ 999
#define NOT_BINGO_ 444

int CheckBingo(int(*arr)[5], int n);

int main()
{

	std::ifstream in;
	in.open("input.txt");

	int cases;
	in >> cases;

	for (int c = 0; c < cases; c++)
	{
		int arr[5][5];
		int n;
		int count = 0;
		
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				in >> n;
				arr[i][j] = n;
			}
		}

		arr[2][2] = BINGO_;

		while (count <75)
		{
			in >> n;
			if (CheckBingo(arr, n) == n)
			{
				std::cout << count + 1 << std::endl;
				
				for (int j = 0; j < 75 - (count + 1); j++)
					in >> n;

				break;
			}
			
		
	/*		for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					std::cout << arr[i][j] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
*/
			count++;
		}




	}
	
	system("pause");
	in.close();
	return 0;

}

int CheckBingo(int (*arr)[5], int n)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == n)
				arr[i][j] = BINGO_;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if ((arr[i][0] == BINGO_) && (arr[i][1] == BINGO_) && (arr[i][2] == BINGO_) && (arr[i][3] == BINGO_) && (arr[i][4] == BINGO_))
		{
			return n;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if ((arr[0][i] == BINGO_) && (arr[1][i] == BINGO_) && (arr[2][i] == BINGO_) && (arr[3][i] == BINGO_) && (arr[4][i] == BINGO_))
		{
			return n;
		}
	}
	
	if ((arr[0][0] == BINGO_) && (arr[1][1] == BINGO_) && (arr[2][2] == BINGO_) && (arr[3][3] == BINGO_) && (arr[4][4] == BINGO_))
	{
		return n;
	}
	if ((arr[4][0] == BINGO_) && (arr[3][1] == BINGO_) && (arr[2][2] == BINGO_) && (arr[1][3] == BINGO_) && (arr[0][4] == BINGO_))
	{
		return n;
	}
	if ((arr[0][0] == BINGO_) && (arr[4][0] == BINGO_) && (arr[0][4] == BINGO_) && (arr[4][4] == BINGO_))
		return n;


	return NOT_BINGO_;

}
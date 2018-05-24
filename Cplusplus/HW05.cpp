#include <iostream>
#include <fstream>

void printHeadTail(int star);
void printCenter(int plus);
int main()
{
	int cases;
	
	std::ifstream in;
	in.open("input.txt");
	in >> cases;
	
	for (int i = 0; i < cases; i++)
	{
		int k;
		in >> k;
		int center = 1;
		int headTail = (k - center) / 2;
		bool decrease = false;

		for (int j = 0; j < k; j++)
		{
		
				printHeadTail(headTail);
				printCenter(center);
				printHeadTail(headTail);
	
				if (center == k)
					decrease = true;

				if (decrease == false)
					center += 2;
				else
					center -= 2;


			headTail = (k - center) / 2;
			std::cout << std::endl;
		}


	}


	return 0;
}

void printHeadTail(int star)
{
	for (int i = 0; i < star; i++)
		std::cout << "*";
}

void printCenter(int plus)
{
	for (int i = 0; i < plus; i++)
		std::cout << "+";
}

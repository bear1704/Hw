#include <iostream>
#include <fstream>


int main()
{
	int cases;
	int increment;
	std::ifstream in;
	in.open("input.txt");
	in >> cases;
	int floor;

	for (int i = 0; i < cases; i++)
	{
		in >> floor;
	
		bool stSwith = false;
		for (int j = 1; j <= floor; j++)
		{
			increment = floor - 1;
			if (stSwith == false)
			{
				std::cout << j << std::endl;
				stSwith = true;
			}
			else
			{
				std::cout << j << " ";
				int pastSum = j;
				for (int k = 0; k < j - 1; k++)
				{
					std::cout << pastSum + increment << " ";
					pastSum += increment;
					increment--;

				}
				std::cout << std::endl;
			}

		}
	}
		
	return 0;
}


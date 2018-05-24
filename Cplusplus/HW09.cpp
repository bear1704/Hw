#include <iostream>
#include <fstream>

int PrintMinus(int minus);

int main()
{
	std::ifstream in;
	in.open("input.txt");

	int cases;
	int n;
	in >> cases;

	for (int i = 0; i < cases; i++)
	{
		in >> n;
		int nClone = n;
		int minus = 0;
		bool minusDec = false;

		for (int j = 0; j < n; j++)
		{
			int star = nClone / 2 + 1;
			int plus = nClone - star;

			if (minus == n - 1)
				minusDec = true;

			PrintMinus(minus);
			while(1)
			{
				if (star > 0)
				{
					std::cout << "*";
					star--;
				}
				if (plus > 0)
				{
					std::cout << "+";
					plus--;
				}
				if (star <= 0 && plus <= 0)
					break;

			}
			PrintMinus(minus);
			if (minusDec == true)
				nClone += 2;
			else
				nClone -= 2;
	
			if (minusDec == true)
				minus -= 2;
			else
				minus += 2;
	
			std::cout << std::endl;
			

		}

	}

	return 0;
}

int PrintMinus(int minus)
{
	
	for (int i = 0; i < minus / 2; i++)
	{
		std::cout << "-";
	}

	return 0;
}
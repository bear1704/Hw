#include <iostream>
#include <fstream>

int main()
{
	int cases;

	std::ifstream in;
	in.open("input.txt");

	in >> cases;
	
	for (int i = 0; i < cases; ++i)
	{
		int subCase, num;		
		int sum = 0;
		in >> subCase;

		for (int j = 0; j < subCase; j++)
		{
			in >> num;
			sum += num;
		}
		std::cout << sum << std::endl;
	}
	
	return 0;
}
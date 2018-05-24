#include <iostream>
#include <fstream>
int main()
{
	int a, b, cases;
	std::ifstream in;
	in.open("input.txt");

	in >> cases;
	
	for (int i = 0; i < cases; ++i)
	{
		in >> a >> b;
		int sum = 0;

		for (int j = a; j <= b; ++j)
		{
			sum += j;		
		}	
		std::cout << sum << std::endl;
	}
}

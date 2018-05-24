#include <iostream>
#include <fstream>
#include <cmath>

#define ISO 0
#define RIGHT 1

int freq(int, int, int);

int main()
{
	std::ifstream in;
	in.open("input.txt");
	int cases;

	in >> cases;

	for (int i = 0; i < cases; i++)
	{
		int ab, bc, ca;
		in >> ab >> bc >> ca;

		if (!(ab + bc > ca && bc + ca > ab && ca + ab > bc))
			std::cout << "0" << std::endl;
		else if(ab == bc && bc == ca)
			std::cout << "1" << std::endl;
		else if (freq(ab, bc, ca) == ISO)
			std::cout << "3" << std::endl;
		else if (freq(ab, bc, ca) == RIGHT)
			std::cout << "2" << std::endl;
		else
			std::cout << "4" << std::endl;

	}

	//system("pause");
	return 0;

}

int freq(int ab, int bc, int ca)
{
	int sum = 0;

	if (ab == bc)
		sum++;
	if (bc == ca)
		sum++;
	if (ca == ab)
		sum++;

	if (sum >= 1)
		return ISO;

	if (std::pow(ab, 2) + std::pow(bc, 2) == std::pow(ca,2))
		return RIGHT;
	if (std::pow(bc, 2) == std::pow(ca, 2) == std::pow(ab,2))
		return RIGHT;
	if (std::pow(ca, 2) == std::pow(ab, 2) == std::pow(bc,2))
		return RIGHT;

	return -1;

}
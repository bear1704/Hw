#include <iostream>
#include <fstream>

int CheckMySign(int posX, int posY, int n);

int main()
{
	enum {
		XAXIS = 0,
		YAXIS ,
		STAR,
		DOT,
		ZERO
	};

	int cases, n;

	std::ifstream in;
	in.open("input.txt");
	
	in >> cases;
	
	for (int c = 0; c < cases; c++)
	{
		in >> n;
		for (int y = n; y > 0; y--)
		{
			for (int x = 1; x <= n; x++)
			{
				switch (CheckMySign(x, y, n))
				{
				case XAXIS:
					std::cout << "+";
					break;
				case YAXIS:
					std::cout << "I";
					break;
				case STAR:
					std::cout << "*";
					break;
				case DOT:
					std::cout << ".";
					break;
				case ZERO:
					std::cout << "O";
					break;
				}
			}
			std::cout << std::endl;
		}
	}

	//system("pause");
	return 0;

}

int CheckMySign(int posX, int posY, int n)
{
	enum {
		XAXIS = 0,
		YAXIS,
		STAR,
		DOT,
		ZERO
	};

	int center = n / 2 + 1;

	if (posX == center && posY == center)
		return ZERO;
	else if (posY == center)
		return XAXIS;
	else if (posX == center)
		return YAXIS;
	else if (posX == posY)
		return STAR;
	else
		return DOT;

	return 0;
}
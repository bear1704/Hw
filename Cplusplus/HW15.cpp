#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

int compare_(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

bool Not_Triangle(float ax, float ay, float bx, float by, float cx, float cy);


int main()
{
	std::ifstream in;
	in.open("input.txt");

	int cases;
	float ax, ay, bx, by, cx, cy;
	in >> cases;

	for (int c = 0; c < cases; c++)
	{
		in >> ax >> ay >> bx >> by >> cx >> cy;

		float ab = sqrtf( (powf(ax-bx, 2) + powf(ay-by, 2)));
		float bc = sqrtf((powf(bx - cx, 2) + powf(by - cy, 2)));
		float ca = sqrtf((powf(cx - ax, 2) + powf(cy - ay, 2)));
		
		float line[3];
		line[0] = ab;
		line[1] = bc;	
		line[2] = ca;

		qsort(line, 3, sizeof(float), compare_);

		if (Not_Triangle(ax, ay, bx, by, cx, cy) || line[0] + line[1] <= line[2])
			std::cout << "0" << std::endl;
		else if (  floor(powf(line[0], 2)+0.5) + floor(powf(line[1], 2)+0.5) == powf(line[2], 2))
			std::cout << "1" << std::endl;
		else if (powf(line[0], 2) + powf(line[1], 2) <= powf(line[2], 2))
			std::cout << "2" << std::endl;
		else if (powf(line[0], 2) + powf(line[1], 2) >= powf(line[2], 2))
			std::cout << "3" << std::endl;

	}

	system("pause");
	in.close();
	return 0;

}


inline bool Not_Triangle(float ax,float ay, float bx, float by, float cx, float cy)
{
	float sum = ((bx - ax)*(cy - ay) - (cx - ax)*(by - ay)) / 2;

	if (sum == 0)
		return true;

	return false;
}


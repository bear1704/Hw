#include <iostream>
#include <fstream>
#include <cmath>


typedef struct SQUARE_ {

	float xmin, ymin, xmax, ymax;

} square;

typedef struct POINT_ {
	float x, y;
} point;


void swap(float& min, float& max);
int ClosePoint(const square sq, const point pt, point& chase);
float Euc_Distance(const point pt, const point chase);
float Rec_Distance(const point pt, const point chase);

int main()
{
	int cases;
	std::ifstream in;
	in.open("input.txt");
	in >> cases;
	square square;
	point pt;
	point chase;

	for (int c = 0; c < cases; c++)
	{
		in >> square.xmin >> square.ymin >> square.xmax >> square.ymax;
		in >> pt.x >> pt.y;

		if (square.xmin > square.xmax)
			swap(square.xmin, square.xmax);
		if (square.ymin > square.ymax)
			swap(square.ymin, square.ymax);

		if (ClosePoint(square, pt, chase) == -1)
		{
			std::cout << "0 0" << std::endl;
			continue;
		}

		std::cout << powf(Euc_Distance(pt, chase), 2) << " " << Rec_Distance(pt, chase) << std::endl;
	}

	//system("pause");
	in.close();
	return 0;
}

inline void swap(float& min, float& max)
{
	float temp;
	
	temp = min;
	min = max;
	max = temp;
}

inline int ClosePoint(const square sq, const point pt, point& chase)
{
	float pointX = sq.xmin;
	float pointY = sq.ymin;
	bool change = false;
	if ((pt.x <= sq.xmax && pt.y <= sq.ymax)  &&  (pt.x >= sq.xmin && pt.y >= sq.ymin)) //IN
	{
		chase.x = 0;
		chase.y = 0;
		return -1;
	}
	
	while (1)
	{
		if (pointX < pt.x && pointX != sq.xmax)
		{
			pointX++;
			change = true;
		}
		if (pointX > pt.x && pointX != sq.xmin)
		{
			pointX--;
			change = true;
		}
		if (pointY < pt.y && pointY != sq.ymax)
		{
			pointY++;
			change = true;
		}
		if (pointY > pt.y && pointY != sq.ymin)
		{
			pointY--;
			change = true;
		}
		if (!change)
			break;
		
		change = false;

	}

	chase.x = pointX;
	chase.y = pointY;
	return 0;


}

inline float Euc_Distance(const point pt, const point chase)
{
	float sum = sqrtf(powf(chase.x - pt.x, 2) + powf(chase.y - pt.y, 2));
	return sum;
}

inline float Rec_Distance(const point pt, const point chase)
{
	float sum = fabsf(pt.x - chase.x) + fabsf(pt.y - chase.y);
	return sum;
}

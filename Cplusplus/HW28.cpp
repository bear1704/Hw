#include <iostream>
#include <fstream>

inline void YearJump(const int year, int& dayWeek);
inline void MonthJump(int subtractMonth, int subtractDay, int& dayWeek,const bool isLeap);
bool isLeap(const int year);

enum dayW {
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	
};

int main()
{
	int cases;
	int dayWeek = FRIDAY; //요일
	const int gregY = 1582;

	int inputYear, inputMonth, inputDay;

	std::ifstream in;
	in.open("input.txt");
	in >> cases;

	for (int c = 0; c < cases; c++)
	{
		in >> inputYear >> inputMonth >> inputDay;

		for (int i = gregY; i < inputYear; ++i)
		{
			YearJump(i,dayWeek);
		}
		MonthJump(inputMonth - 1, inputDay - 1, dayWeek, isLeap(inputYear));
		
		std::cout << dayWeek << std::endl;

		dayWeek = FRIDAY;
	}
	

	in.close();
	//system("pause");
	return 0;
}

inline void YearJump(const int year,int& dayWeek)
{
	
	if ((year % 400) == 0)
	dayWeek += 2;
	else if ((year % 100) == 0)
		++dayWeek; //평년
	else if ((year % 4) == 0)
		dayWeek += 2;
	else
		++dayWeek;
	if (dayWeek > 6)
		dayWeek -= 7;
}

bool isLeap(const int year)
{
	if ((year % 400) == 0)
		return true;
	else if ((year % 100) == 0)
		return false;
	else if ((year % 4) == 0)
		return true;
	else
		return false;
}

inline void MonthJump(int subtractMonth, int subtractDay, int& dayWeek, const bool isLeap)
{
	const int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	const int LeapMonth[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int sub = subtractDay;

	if (isLeap == false)
	{
		for (int i = 0; i < subtractMonth; ++i)
		{
			if (month[i] == 31)
				dayWeek += 3;
			else if (month[i] == 30)
				dayWeek += 2;

			if (dayWeek > 6)
				dayWeek -= 7;
		}
	}
	else
	{
		for (int i = 0; i < subtractMonth; ++i)
		{
			if (LeapMonth[i] == 31)
				dayWeek += 3;
			else if (LeapMonth[i] == 30)
				dayWeek += 2;
			else if (LeapMonth[i] == 29)
				dayWeek += 1;

			if (dayWeek > 6)
				dayWeek -= 7;
		}

	}

	if ((sub / 7) != 0)
	{
		sub %= 7;
	}
	dayWeek += sub;
	

	if (dayWeek > 6)
		dayWeek -= 7;
}
#include <iostream>
#include <fstream>

inline void YearJump(const int year, int& dayWeek);
inline void MonthJump(int subtractMonth, int subtractDay, int& dayWeek, const bool
	isLeap);
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
	int dayWeek = FRIDAY; //����
	const int gregY = 1582;

	int inputYear, inputMonth;
	int inputDay = 1;

	std::ifstream in;
	in.open("input.txt");
	in >> cases;

	int end_31[13] = { 0,1,0,1,0,1,0,1,1,0,1,0,1 };


	for (int c = 0; c < cases; c++)
	{
		in >> inputYear >> inputMonth;
		int outputCount = 0;
		int lastNum = 0;


		for (int i = gregY; i < inputYear; ++i)
		{
			YearJump(i, dayWeek); 
			// ����, HW28 '���ϰ���ϱ�'���� �����ߴ� �Լ�.
		}
		MonthJump(inputMonth - 1, inputDay - 1, dayWeek, isLeap(inputYear)); 
		// ����, HW28 '���ϰ���ϱ�'���� �����ߴ� �Լ�.


			std::cout << inputYear << " " << inputMonth << std::endl;  
			//�Էµ� ��/���� ����մϴ�.

			for (int k = 0; k < dayWeek; ++k) 
				//ó�� 0�� ä��� for�� �κ�
			{
				std::cout << "0 ";
				++outputCount;
			}



		if (inputMonth == 2 && !isLeap(inputYear)) // ������ �ƴϸ鼭, 2���϶�
			lastNum = 28;
		else if (inputMonth == 2 && isLeap(inputYear)) // �����̸鼭, 2���� ��
			lastNum = 29;
		else if (end_31[inputMonth] == 1) //�ش� ���� ���ڸ��� 31���϶�.
			lastNum = 31;
		else  // �ش� ���� ���ڸ��� 30���� ��.
			lastNum = 30;


		for (int j = 1; j <= lastNum; j++) 
			// �ش� ���� ���ڸ����� ����ϸ� outputCount(7ȸ ��� �� �ٹٲ� ���)
			//�� 7ȸ �̷������ ��� ���� �ѹ�.
		{
			std::cout << j << " ";
			++outputCount;

			if (outputCount == 7) {
				std::cout << std::endl;
				outputCount = 0;
			}
		}



		for (int l = outputCount; l < 7; ++l) 
			// �ش� ���� ���ڸ����� ��� ��, ���� �κп� 0�� ����ֽ��ϴ�.
		{
			std::cout << "0";

			if (l != 6)
				std::cout << " ";
		}
		std::cout << std::endl;




		dayWeek = FRIDAY;
	}


	in.close();
	//system("pause");
	return 0;
}

inline void YearJump(const int year, int& dayWeek)
{

	if ((year % 400) == 0)
		dayWeek += 2;
	else if ((year % 100) == 0)
		++dayWeek; //���
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

inline void MonthJump(int subtractMonth, int subtractDay, int& dayWeek, const bool
	isLeap)
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




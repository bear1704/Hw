#include <iostream>
#include <fstream>
#include <string>
std::string ConvertNumber(const std::string num,int a);
bool isBill = false;
bool isMill = false;
bool isThou = false;
bool AllZero(std::string str);
int main()
{

	
	std::ifstream in;
	in.open("input.txt");

	int cases;
	in >> cases;

	for (int c = 0; c < cases; c++)
	{
		std::string number;
		std::string num_bil = "";
		std::string num_mil = "";
		std::string num_tho = "";
		std::string num_hun = "";

		in >> number;

		while (number.length() < 12)
			number = '0' + number;  //부족한 부분 0 채워주기

		num_bil = number[0];
		num_bil += number[1];
		num_bil += number[2];
		num_mil = number[3];
		num_mil += number[4];
		num_mil += number[5];
		num_tho = number[6];
		num_tho += number[7];
		num_tho += number[8];
		num_hun = number[9];
		num_hun += number[10];
		num_hun += number[11];


		if (AllZero(num_bil) != true) 
		{
			std::cout << ConvertNumber(num_bil,1) << "_Bilion";
			isBill = true;
		}
		if (AllZero(num_mil) != true) 
		{
			std::cout << ConvertNumber(num_mil,2) << "_Milion";
			isMill = true;
		}
		if (AllZero(num_tho) != true)
		{
			std::cout << ConvertNumber(num_tho,3) << "_Thousand";
			isThou = true;
		}

		std::cout << ConvertNumber(num_hun,4) << std::endl;

	}



	system("pause");

}
bool AllZero(std::string str)
{
	if ((str[0] == '0' && str[1] == '0') && str[2] == '0')
		return true;
	else
		return false;
}


std::string ConvertNumber(const std::string num,int a)
{
	std::string num_ = num;
	std::string num_100 = "";
	std::string num_10 = "";
	std::string num_1 = "";
	std::string a_ = "";
	if (((a == 2) && (isBill == true)))
		a_ += "_";
	if (((a == 3) && (isMill == true)))
		a_ += "_";
	if ((((a == 4) && (isThou == true)) && num_[0] - '0' > 0)
		a_ += "_";
		switch (num_[0] - '0') // 백의자리숫자
		{
		
		case 1:
			num_100 += "One_Hundred";
			break;
		case 2:
			num_100 += "Two_Hundred";
			break;
		case 3:
			num_100 += "Three_Hundred";
			break;
		case 4:
			num_100 += "Four_Hundred";
			break;
		case 5:
			num_100 += "Five_Hundred";
			break;
		case 6:
			num_100 += "Six_Hundred";
			break;
		case 7:
			num_100 += "Seven_Hundred";
			break;
		case 8:
			num_100 += "Eight_Hundred";
			break;
		case 9:
			num_100 += "Nine_Hundred";
			break;
		case 0:
			num_100 += "";
			break;
		}

		if (num_[0] - '0' > 0)
			num_10 += "_";

		switch (num_[1] - '0') // 십의자리숫자
		{
		case 1:
			num_10 += "";
			break;
		case 2:
			num_10 += "Twenty";
			break;
		case 3:
			num_10 += "Thirty";
			break;
		case 4:
			num_10 += "Forty";
			break;		   
		case 5:			   
			num_10 += "Fifty";
			break;		   
		case 6:			   
			num_10 += "Sixty";
			break;
		case 7:
			num_10 += "Seventy";
			break;
		case 8:
			num_10 += "Eighty";
			break;
		case 9:
			num_10 += "Ninety";
			break;
		case 0:
			num_10 += "";
			break;
		}
		
		//if ((((num_[1] - '0') != 0) && (num_[2] - '0' > 0)) /*&& (num_[1] - '0' != 1)*/)
		//	num_10 += '_';



		switch (num_[2] - '0') // 일의자리숫자
		{
		case 1:
			if ((num_[1] - '0') == 1)
				num_1 = "Eleven";
			else
				num_1 = "One";
			break;
		case 2:
			if ((num_[1] - '0') == 1)
				num_1 = "Twelve";
			else
				num_1 = "Two";
			break;
		case 3:
			if ((num_[1] - '0') == 1)
				num_1 = "Thirteen";
			else
				num_1 = "Three";
			break;
		case 4:
			if ((num_[1] - '0') == 1)
				num_1 = "Fourteen";
			else
				num_1 = "Four";
			break;
		case 5:
			if ((num_[1] - '0') == 1)
				num_1 = "Fifteen";
			else
				num_1 = "Five";
			break;
		case 6:
			if ((num_[1] - '0') == 1)
				num_1 = "Sixteen";
			else
				num_1 = "Six";
			break;
		case 7:
			if ((num_[1] - '0') == 1)
				num_1 = "Seventeen";
			else
				num_1 = "Seven";
			break;
		case 8:
			if ((num_[1] - '0') == 1)
				num_1 = "Eighteen";
			else
				num_1 = "Eight";
			break;
		case 9:
			if ((num_[1] - '0') == 1)
				num_1 = "Nineteen";
			else
				num_1 = "Nine";
			break;
		case 0:
			if ((num_[1] - '0') == 1)
				num_1 = "Ten";
			else
				num_1 = "";
			break;
		}

		return a_ + num_100 + num_10 + num_1;
}


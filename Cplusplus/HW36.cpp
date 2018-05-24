#include <iostream>
#include <fstream>
#include <string>

bool IsCardLengthOk(const std::string str);
int DoubleArr(int arr[], int size);

int main()
{
	int cases;
	std::ifstream in;
	in.open("input.txt");
	in >> cases;
	

	for (int c = 0; c < cases; c++)
	{
		std::string str;
		bool stNumOk = false;
		int *arr;
		int checksum;
		
		in >> str;

		int size = str.length();
		arr = new int[str.length()];

		stNumOk = IsCardLengthOk(str);

		for (int i = 0; i < str.length(); i++)
		{
			arr[i] = str[i] - '0';
		}
		checksum = 10 - (DoubleArr(arr, size) % 10);

		if ((DoubleArr(arr, size) % 10) == 0)
			checksum = 0;

		if (stNumOk == true && (str[size-1] - '0' == checksum))
			std::cout << "1" << std::endl;
		else
			std::cout << "0" << std::endl;
	

		delete[] arr;
	}

	system("pause");
	
	in.close();
	return 0;
	

}

bool IsCardLengthOk(const std::string str)
{
	int length = str.length();


	switch (str[0] - '0')
	{
	case 3:
		if (length == 15 || length == 14) 
			return true;
		else
			return false;
		break;
	case 4:
		if (length == 13 || length == 16)
			return true;
		else 
			return false;
		break;
	case 5:
		if (length == 16)
			return true;
		else 
			return false;
		break;
	case 6:
		if (length == 16)
			return true;
		else 
			return false;
		break;
	default:
		return false;
		break;

	}

}

int DoubleArr(int arr[],int size)
{
	int sum = 0;

	int *arr_ = new int[size];
	
	for(int k= 0 ; k < size ; k++)
	{
		arr_[k] = arr[k];
	}
	
	
	for (int i = size-2; i >= 0 ; i-=2)
	{
		arr_[i] *= 2;

		if (arr_[i] >= 10)
			arr_[i] -= 9;
	}

	for (int j = size-2; j >= 0; j--)
		sum += arr_[j];

	
	delete[] arr_;
	return sum;

}
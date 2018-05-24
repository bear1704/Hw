#include <iostream>
#include <fstream>
#include <stack>

std::stack<int> DecToBin(const int dec_);
int CalcWeight(std::stack<int> bin_);
int CompareDist( std::stack<int> bin1_, std::stack<int> bin2_);
void StackToArr(std::stack<int> s, int arr[], int max);
int main()
{
	std::ifstream in;
	in.open("input.txt");

	int cases, b1, b2;
	in >> cases;

	for (int i = 0; i < cases; i++)
	{
		in >> b1 >> b2;

		std::stack<int> bin1 = DecToBin(b1);	
		std::stack<int> bin2 = DecToBin(b2);

		std::cout << CalcWeight(bin1) << " " << CalcWeight(bin2) << " ";
		std::cout << CompareDist(bin1, bin2) << std::endl;
		
	}

	system("pause");
	in.close();
	return 0;
}

int CalcWeight(std::stack<int> bin_)
{
	int sum = 0;
	std::stack<int> bin = bin_;
	int SIZE = bin.size();
	for (int i = 0; i < SIZE; i++)
	{
		if (bin.top() == 1)
		{
			bin.pop();
			sum++;
		}
		else
			bin.pop();
	}
	return sum;
}

int CompareDist(std::stack<int> bin1_,std::stack<int> bin2_)
{
	int dist = 0;
	std::stack<int> bin1 = bin1_;
	std::stack<int> bin2 = bin2_;
	
	int SIZE1 = bin1.size();
	int SIZE2 = bin2.size();
	int maxSIZE = (SIZE1 >SIZE2) ? SIZE1 : SIZE2;

	
	int *bin1Arr = new int[maxSIZE+1];
	int *bin2Arr = new int[maxSIZE+1]; // 1부터 쓸거니까 +1

	for (int i = 0; i < maxSIZE + 1; i++)
	{
		bin1Arr[i] = 0;
		bin2Arr[i] = 0;
	}

	StackToArr(bin1, bin1Arr, SIZE1);
	StackToArr(bin2, bin2Arr, SIZE2);

	for (int j = 1; j <= maxSIZE + 1; j++)
	{
		if (bin1Arr[j] != bin2Arr[j])
			dist++;
	}

	return dist;
}

std::stack<int> DecToBin(const int dec_)
{
	std::stack<int> bin;
	int arr[100] = { 0, };
	int dec = dec_;

	int i = 0;

	while (1)
	{
		if (dec == 0)
		{
			i++;
			break;
		}

		if ((dec / 2) != 0)//몫이 0이 아닐경우
		{
			arr[i] = dec % 2; // 나머지를 구하고
			++i;
			dec /= 2; //원숫자를 나누고
		}
		else
		{
			arr[i] = 1;
			break;
		}
	}

	for (int j = i; j >= 0; j--)
		bin.push(arr[j]);

	return bin;

}

void StackToArr(std::stack<int> s, int arr[],int max)
{
	int SIZE = max;

	for (int i = 1; i <= SIZE; i++)
	{
		arr[i] = s.top();
		s.pop();
	}


}
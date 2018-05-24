#include <iostream>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <fstream>
const int PBIT = 2;
std::stack<int> DecToBin(const int dec_);
void BinToParity(int parity[], std::stack<int> bin);
int BinToDec(int arr[]);
void StackToArr(std::stack<int> s, int arr[]);
bool isParityOk(int parity[], int num);
void removeBit(int parity[]);

int main()
{
	int cases, n, zo;
	std::ifstream in;
	in.open("input.txt");
	
	in >> cases;

	int checkSeq[5] = { 1,2,4,8,16 };

	
	for (int i = 0; i < cases; i++)
	{
		std::stack<int> bin;
		int parity[33] = { 0, }; // 0번째 배열값은 혼란을 방지하기 위해 사용하지 않는다
		int ans = 0;
		int sum = 0;
		in >> zo >> n;

		if (n == 0)
		{
			std::cout << "0" << std::endl;
			continue;
		}

		switch (zo)
		{
			case 0:
				bin = DecToBin(n);
				BinToParity(parity, bin);
				ans = BinToDec(parity);
				
				std::cout << ans << std::endl;
				break;
			case 1:
				bin = DecToBin(n);
				StackToArr(bin, parity);
				for (int j = 0; j < 5; j++)
				{
					
					if (isParityOk(parity, checkSeq[j]) == false)
					{
						sum += checkSeq[j];
					}
				}
				
				if (parity[sum] == 1)
					parity[sum] = 0;
				else
					parity[sum] = 1;
				
				removeBit(parity);
				ans = BinToDec(parity);
				std::cout << ans << std::endl;
				break;

		}




	}



	//system("pause");
	in.close();
	return 0;


}

void StackToArr(std::stack<int> s, int arr[])
{
	int SIZE = s.size();

	for (int i = 1; i <= SIZE; i++)
	{
		arr[i] = s.top();
		s.pop();
	}


}



void BinToParity(int parity[], std::stack<int> bin)
{
	parity[1] = PBIT;
	parity[2] = PBIT;
	parity[4] = PBIT;
	parity[8] = PBIT;
	parity[16] = PBIT;
	parity[32] = PBIT;

	int pCount = 0;

	for (int i = 1; i <= 32; i++)
	{
		if ((parity[i] != PBIT) && (!bin.empty()))
		{
			parity[i] = bin.top();
			bin.pop();
		}
		else if ((parity[i] != PBIT) && (bin.empty()))
		{
			parity[i] = 0;
		}
	}




	for (int j = 3; j <= 32; j += 2)  // 패리티 비트 [1] 값 판별
	{
		if (parity[j] == 1)
			pCount++;

		

	}
	if (pCount % 2 == 0)//짝수라면
		parity[1] = 0;
	else
		parity[1] = 1;

	pCount = 0;

	for (int j = 2; j <= 32; j += 4)  // 패리티 비트 [2] 값 판별
	{

		for (int k = j; k <= j + 1; k++)
		{
			if (parity[k] == 1)
				pCount++;
		}

	}
	if (pCount % 2 == 0)//짝수라면
		parity[2] = 0;
	else
		parity[2] = 1;
	pCount = 0;



	for (int j = 4; j <= 32; j += 8)  // 패리티 비트 [4] 값 판별
	{

		for (int k = j; k <= j + 3; k++)
		{
			if (parity[k] == 1)
				pCount++;
		}

	}
	if (pCount % 2 == 0)//짝수라면
		parity[4] = 0;
	else
		parity[4] = 1;
	pCount = 0;


	for (int j = 8; j <= 32; j += 16)  // 패리티 비트 [8] 값 판별
	{

		for (int k = j; k <= j + 7; k++)
		{
			if (parity[k] == 1)
				pCount++;
		}

	}
	if (pCount % 2 == 0)//짝수라면
		parity[8] = 0;
	else
		parity[8] = 1;
	pCount = 0;



	     // 패리티 비트 [16] 값 판별
	
		for (int k = 16; k <= 16 + 15; k++)
		{
			if (parity[k] == 1)
				pCount++;
		}


	if (pCount % 2 == 0)//짝수라면
		parity[16] = 0;
	else
		parity[16] = 1;
	pCount = 0;

	parity[32] = 0;  //32는 비교할 대상이 없음.

	

}

int BinToDec(int arr[])
{
	int sum = 0;

	for (int i = 1; i <= 32; i++)
	{
		if (arr[i] == 1)
			sum += pow(2, i-1);
	}

	return sum;
}


std::stack<int> DecToBin(const int dec_)
{
	std::stack<int> bin;
	int arr[50] = { 0, };
	int dec = dec_;

	int i = 0;

	while (1)  
	{
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

bool isParityOk(int parity[], int num)
{

	int pCount = 0;

	switch (num)
	{
	case 1:
		for (int j = 3; j <= 32; j += 2)  // 패리티 비트 [1] 값 판별
		{
			if (parity[j] == 1)
				pCount++;
		}

		if (pCount % 2 == parity[num])
			return true;
		else
			return false;
		pCount = 0;
		break;
	case 2:
		for (int j = 2; j <= 32; j += 4)  // 패리티 비트 [2] 값 판별
		{
			for (int k = j; k <= j + 1; k++)
			{
				if (parity[k] == 1)
					pCount++;
			}

		}
		if (parity[2] == 1)
			pCount--;
		if (pCount % 2 == parity[num])//parity[num]과 0,1이 동일하다면
			return true;
		else
			return false;

		pCount = 0;
		break;
	case 4:
		for (int j = 4; j <= 32; j += 8)  // 패리티 비트 [4] 값 판별
		{

			for (int k = j; k <= j + 3; k++)
			{
				if (parity[k] == 1)
					pCount++;
				
			}

		}
		if (parity[4] == 1)
			pCount--;
		if (pCount % 2 == parity[num])
			return true;
		else
			return false;

		pCount = 0;
		break;
	case 8:
		for (int j = 8; j <= 32; j += 16)  // 패리티 비트 [8] 값 판별
		{

			for (int k = j; k <= j + 7; k++)
			{
				if (parity[k] == 1)
					pCount++;
			}

		}
		if (parity[8] == 1)
			pCount--;
		if (pCount % 2 == parity[num])
			return true;
		else
			return false;

		pCount = 0;
		break;

	case 16:
		for (int k = 16; k <= 16 + 15; k++)
		{
			if (parity[k] == 1)
				pCount++;
		}
		if (parity[16] == 1)
			pCount--;
		if (pCount % 2 == parity[num])
			return true;
		else
			return false;

		pCount = 0;
		break;

	}
}

void removeBit(int parity[])
{
	int arr[33] = { 0, };
	int j = 1;
	for (int i = 1; i <= 32; i++)
	{
		if ((i == 1) || (i == 2) || (i == 4) ||(i==8) ||(i == 16) || (i == 32))
		{
			
		}
		else
		{
			arr[j] = parity[i];
			j++;
		}
	}

	for (int i = 1; i <= 32; i++)
	{
		parity[i] = arr[i];
	}


}
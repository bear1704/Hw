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
		int parity[33] = { 0, }; // 0��° �迭���� ȥ���� �����ϱ� ���� ������� �ʴ´�
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




	for (int j = 3; j <= 32; j += 2)  // �и�Ƽ ��Ʈ [1] �� �Ǻ�
	{
		if (parity[j] == 1)
			pCount++;

		

	}
	if (pCount % 2 == 0)//¦�����
		parity[1] = 0;
	else
		parity[1] = 1;

	pCount = 0;

	for (int j = 2; j <= 32; j += 4)  // �и�Ƽ ��Ʈ [2] �� �Ǻ�
	{

		for (int k = j; k <= j + 1; k++)
		{
			if (parity[k] == 1)
				pCount++;
		}

	}
	if (pCount % 2 == 0)//¦�����
		parity[2] = 0;
	else
		parity[2] = 1;
	pCount = 0;



	for (int j = 4; j <= 32; j += 8)  // �и�Ƽ ��Ʈ [4] �� �Ǻ�
	{

		for (int k = j; k <= j + 3; k++)
		{
			if (parity[k] == 1)
				pCount++;
		}

	}
	if (pCount % 2 == 0)//¦�����
		parity[4] = 0;
	else
		parity[4] = 1;
	pCount = 0;


	for (int j = 8; j <= 32; j += 16)  // �и�Ƽ ��Ʈ [8] �� �Ǻ�
	{

		for (int k = j; k <= j + 7; k++)
		{
			if (parity[k] == 1)
				pCount++;
		}

	}
	if (pCount % 2 == 0)//¦�����
		parity[8] = 0;
	else
		parity[8] = 1;
	pCount = 0;



	     // �и�Ƽ ��Ʈ [16] �� �Ǻ�
	
		for (int k = 16; k <= 16 + 15; k++)
		{
			if (parity[k] == 1)
				pCount++;
		}


	if (pCount % 2 == 0)//¦�����
		parity[16] = 0;
	else
		parity[16] = 1;
	pCount = 0;

	parity[32] = 0;  //32�� ���� ����� ����.

	

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
		if ((dec / 2) != 0)//���� 0�� �ƴҰ��
		{
			arr[i] = dec % 2; // �������� ���ϰ�
			++i;
			dec /= 2; //�����ڸ� ������
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
		for (int j = 3; j <= 32; j += 2)  // �и�Ƽ ��Ʈ [1] �� �Ǻ�
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
		for (int j = 2; j <= 32; j += 4)  // �и�Ƽ ��Ʈ [2] �� �Ǻ�
		{
			for (int k = j; k <= j + 1; k++)
			{
				if (parity[k] == 1)
					pCount++;
			}

		}
		if (parity[2] == 1)
			pCount--;
		if (pCount % 2 == parity[num])//parity[num]�� 0,1�� �����ϴٸ�
			return true;
		else
			return false;

		pCount = 0;
		break;
	case 4:
		for (int j = 4; j <= 32; j += 8)  // �и�Ƽ ��Ʈ [4] �� �Ǻ�
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
		for (int j = 8; j <= 32; j += 16)  // �и�Ƽ ��Ʈ [8] �� �Ǻ�
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
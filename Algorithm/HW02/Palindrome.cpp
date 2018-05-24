#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>


using namespace std;

bool palindr(int n_data, int radix);
bool success = false;
int cases = 0; //�׽�Ʈ ���̽� ����
int n = 0;   // �׽�Ʈ ������ ����


int main()
{
	
	ifstream in;
	in.open("input.txt");
	
	if (in.fail())
	{
		cerr << "error";
		exit(1);
	}
	in >> cases; 

	for (int i = 0; i < cases; i++)
	{
				in >> n;

				for (int k = 2; k <= 64; k++)
				{
					if (palindr(n, k) == true) //k�� �ش� ����, n_data�� �׽�Ʈ ������
					{
						cout << "1" << endl;
						success = true;
						break;
					}
				}
				if (success == false) { cout << "0" << endl; }
				success = false;
			
	}





	
	//system("pause");
	in.close();
	return 0;
	



}

bool palindr(int n_data, int radix)
{
	int quotient = n_data / radix; //��
	int i; //������ ī����
	int arr[100]; // ������ �迭
	int l = 0;
	int r = 0;


	arr[0] = n_data % radix; //ù��° �迭���� ù ������
	i = 1;
	
	while(true)
	{	
		arr[i] = quotient % radix; // �������� ���� ����ؾ� ���� ������ �����ȴ�.
		quotient /= radix;
		i++;
		if (quotient == 0)
		{
			r = i; //�迭 �� ������ ǩ��
			break;
		}
	}




	while (true)
	{
		if ((arr[l] == arr[r - 1]) && (l < r)) //��Ұ� ȸ���� ����
		{
			l++;
			r--;
		}
		else if (l >= r) //ȸ�������ϰ� ī���Ͱ� �����ų� �������� ���.
			return true;		
		else
			return false;
	}
	
	//return true;
	
}
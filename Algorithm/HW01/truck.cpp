#include <iostream>
#include <fstream>
#include <cstdlib>


bool check_tf();
bool break_time();
using namespace std;



int n = 1;				
int w = 1;				
int L = 10;				
int L_current = 0;		
int tmp1 = 0;
int tmp2 = 0;
int t = 0;				
int* arr;
int* a_temp;
int* sum;


int main(void)
{
	ifstream in;


	in.open("input.txt");
	if (in.fail())
	{
		exit(1);
	}

	in >> t;



	sum = new int[t];

	for (int i = 0; i < t; i++)
	{
		sum[i] = 0;
		
		in >> n >> w >> L;

		arr = new int[n];
		a_temp = new int[n];

		for (int j = 0; j < n; j++)
		{
			in >> arr[j];
			a_temp[j] = 0;
		}

		while (true)
		{
			if (check_tf())
			{

				L_current += arr[tmp1];
				

				++tmp1;
			}

			for (int j = tmp2; j < tmp1; j++)
			{
				++a_temp[j];


				if (a_temp[j] > w - 1)
				{

					++tmp2;
					L_current -= arr[j];

				}
			}

			  ++sum[i];



			if (break_time())
				break;


		}

		tmp1 = 0;
		L_current = 0;
		tmp2 = 0;
		
		
		
		
		delete[] arr;
		delete[] a_temp;
	}




	for (int i = 0; i < t; i++)
	{
		cout << sum[i] + 1 << endl;
	}





	delete[] sum;


	in.close();

	//system("pause");
	return 0;
}

bool check_tf()
{
	if (tmp1 < n && L_current + arr[tmp1] <= L)
	{
		return true;
	}
	else
		return false;
}

bool break_time()
{
	if (L_current == 0 && tmp1 >= n)
	{
		return true;
	}
	else
		return false;

}
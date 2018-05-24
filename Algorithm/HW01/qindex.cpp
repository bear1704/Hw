#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>	


using namespace std;
int comp(const void*, const void*);


int main(void)
{
	ifstream in;
	
	int n = 0;	
	int cases = 0;	
	
	
	int current = 0;
	
	int arrsize = 0;
	
	
	in.open("input.txt");
	if (in.fail())
	{
		cerr << "error\n";
		exit(1);
	}

	
	in >> cases;

	
	
	for (int i = 0; i < cases; i++)
	{
		in >> n;

		int* arr = new int[n];
		
		
		for (int j = 0; j < n; j++)
		{
			in >> arr[j];
		}

		//arrsize = sizeof(arr) / sizeof(int);
		qsort((int*)arr, n, sizeof(int), comp); 

		/*for (int c = 0; c < sizeof(arr); c++)
		{
			cout << arr[c] << endl;
		}*/

		// 정렬 끝

		for (int j = 0; j < n + 1; j++)
		{


			current = arr +n -lower_bound(arr, arr + n, j);

			if (current >= j && arr[n - j - 1] <= j)
			{
				cout << j << endl;
				j = n + 1;
			}
		}

		current = 0;
		
		delete[] arr;
	}

	in.close();
	system("pause");

	return 0;
}

int comp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;


}

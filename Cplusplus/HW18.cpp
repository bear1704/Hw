#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

int compare_(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}


int main()
{
	std::ifstream in;
	in.open("input.txt");
	int cases;
	int n;
	int arr[200];

	in >> cases;

	for (int c = 0; c < cases; c++)
	{
		int SIZE = 0;
		int sum = 0;
		in >> n;
		for (int i = 1; i <= sqrt(n); i++)
		{
			if (n%i == 0)
			{
				arr[SIZE] = i;
				arr[SIZE + 1] = n / i;
				SIZE += 2;

			}
			
		}
		SIZE--; //끝자리 맞추기
		if (arr[SIZE] == arr[SIZE - 1])
		{
			arr[SIZE] = 0;
			SIZE--;
		}  // 100 

		qsort(arr, SIZE+1, sizeof(int), compare_);
		
		for (int k = 0; k < SIZE; k++)
		{
			sum += arr[k];
		}
		
		std::cout << SIZE << " " << sum << std::endl;
		
	}

	//system("pause");
	in.close();
	return 0;

}



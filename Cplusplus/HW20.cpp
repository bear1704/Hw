#include <iostream>
#include <fstream>
#include <cstdlib>


int main()
{
	std::ifstream in;
	in.open("input.txt");
	const int X = 0;
	const int Y = 1;

	int cases;
	
	in >> cases;
	for (int i = 0; i < cases; i++)
	{
		int n;
		int sum = 0;
		in >> n;
		
		int **arr = new int*[n];
		for (int j = 0; j < n; j++)
		{
			arr[j] = new int[2];
			in >> arr[j][X] >> arr[j][Y];
		}


		for (int k = 0; k < n-1; k++)
		{
			sum += (arr[k][X] + arr[k + 1][X])*(arr[k + 1][Y] - arr[k][Y]);
		}
		sum += (arr[n - 1][X] + arr[0][X])*(arr[0][Y] - arr[n - 1][Y]);
		

		std::cout << std::abs(sum) << " ";
		
		if (sum < 0)
			std::cout << "-1" << std::endl;
		else
			std::cout << "1" << std::endl;

		
		for (int l = 0; l < n; l++)
			delete[] arr[l];
		delete[] arr;

	}

	//system("pause");
	in.close();
	return 0;
}
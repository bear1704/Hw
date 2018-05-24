#include <iostream>
#include <fstream>



int main()
{
	int cases, m, n, num;
	std::ifstream in;
	in.open("input.txt");

	in >> cases;

	for (int c = 0; c < cases; ++c)
	{
		in >> m >> n;
		int **arr = new int*[m];

		for (int i = 0; i < m; i++)
			arr[i] = new int[n];


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			in >> num;
			arr[i][j] = num;
		}
	} //행렬초기화


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			in >> num;
			arr[i][j] += num;
		}
	} //행렬덧셈


		for (int i = 0; i < m; i++) //행렬출력테스팅
		{
			for (int j = 0; j < n; j++)
				std::cout << arr[i][j] << " ";
			std::cout<<std::endl;
		}

		for (int k = 0; k < m; k++)
		{
			delete[] arr[k];
		}
		

	}
	

	in.close();
	//system("pause");
	return 0;
}
#include <iostream>
#include <fstream>


int CalcMult(int **arr_1, int **arr_2, int i, int j, int s);
int main()
{
	int cases, i, k,j, num;
	std::ifstream in;
	in.open("input.txt");

	in >> cases;

	for (int c = 0; c < cases; ++c)
	{
		in >> i >> k >> j;
		int **arr_1 = new int*[i];  // i * k
		int **arr_2 = new int*[k]; // k * j
		int **arr_ans = new int*[i]; // i * j


		for (int a = 0; a < i; a++)
			arr_1[a] = new int[k];

		for (int a = 0; a < k; a++)
			arr_2[a] = new int[j];

		for (int a = 0; a < i; a++)
			arr_ans[a] = new int[j];

		for (int a = 0; a < i; a++)  // arr_1 초기화
		{
			for (int b = 0; b < k; b++)
			{
				in >> num;
				arr_1[a][b] = num;
			}
		}
		for (int a = 0; a < k; a++) // arr_2 초기화
		{
			for (int b = 0; b < j; b++)
			{
				in >> num;
				arr_2[a][b] = num;
			}
		}

		for (int a = 0; a < i; a++)
		{
			for (int b = 0; b < j; b++)
				arr_ans[a][b] = CalcMult(arr_1, arr_2, a, b, k);
		}


		for (int a = 0; a < i; a++) //행렬출력테스트
		{
			for (int b = 0; b < j; b++)
				std::cout << arr_ans[a][b] << " ";
			std::cout << std::endl;
		}

		
	

		delete[] arr_1;
		delete[] arr_2;
		delete[] arr_ans;

	}


	in.close();
	//system("pause");
	return 0;
}

int CalcMult(int **arr_1, int **arr_2,int i, int j, int s) // s = 반복횟수    
{
	int ans = 0;


	for (int k = 0; k < s; k++)
	{
		ans += arr_1[i][k] * arr_2[k][j];
	}

	return ans;
}
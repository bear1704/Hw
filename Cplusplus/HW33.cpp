#include <iostream>
#include <fstream>
#include <vector>

int main()
{

	std::ifstream in;
	in.open("input.txt");

	int cases, n, k;
	float num;
	in >> cases;

	for (int c = 0; c < cases; c++)
	{
		int addCnt = 0;  // 각 계산마다 1씩 더하는 그거 
		in >> n;
		std::vector<float> vec;
		

		
		for (int i = 0; i < n; i++)
		{
			in >> num;
			vec.push_back(num);
		
		}
	
		in >> k;
		
		std::cout << n - k + 1 << " ";
		
		for (int i = 1; i <= (n - k + 1); i++)
		{
			float y = 0;
			int y_;
			
			for (int j = 1; j <= k; j++)
			{
				y += vec[j-1+addCnt];
			}
			
			y /= k;

			std::cout << (int)y << " ";
			
			++addCnt;
		}

		
		std::cout << std::endl;
		vec.clear();


	}
	

	system("pause");
	in.close();
	return 0;



}
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <chrono>


inline int cntDivisible(long long int num);

int main()
{
	std::ifstream in;
	in.open("input.txt");

	int cases, n;
	in >> cases;

	auto begin = std::chrono::high_resolution_clock::now();
	for (int c = 0; c < cases; c++)
	{
		int num;
		int count = 0;
		long long int sum = 1;
		int f_count = 0;

		in >> n;
		
		for (int i = 0; i < n; i++)
		{
			in >> num;
			sum *= num;
	
			if (cntDivisible(sum) > 0)
			{
				count += cntDivisible(sum);
				sum /= pow(10, cntDivisible(sum));
			}

		}
		
		while (1)
		{
			if (sum % 10 != 0)
			{
				sum--;
				f_count++;
			}
			else
				break;
		}
		
		//std::cout << f_count << " " << count << std::endl;


	}
	auto end = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	system("pause");
	in.close();
	return 0;

}

inline int cntDivisible(long long int num)
{
	int times = 0;
	long long int nums = num;
	
	while(1)
	{
		if (nums % 10 == 0)
		{
			nums /= 10;
			times++;
		}
		else
			break;
	}
	
	return times;
}
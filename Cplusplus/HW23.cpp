#include <iostream>
#include <fstream>
#include <map>

void InsertMap(std::map<int, int> &m, int n, std::ifstream &in);
int main()
{
	std::ifstream in;
	in.open("input.txt");

	int cases, n;

	in >> cases;

	for (int c = 0; c < cases; c++)
	{
		int max = 0;
		int numOfMax = 1;

		in >> n;
		std::map<int, int> m;
		
		InsertMap(m, n, in);

		std::map<int, int>::iterator iter;
		for (iter = m.begin(); iter != m.end(); iter++)
		{
			if (iter->second > max)
			{
				numOfMax = 1;
				max = iter->second; //iter->second : 불린 횟수 
				
			}
			else if (iter->second == max)
			{
				numOfMax++;
			}
		}
		std::cout << numOfMax << " " << max << " ";
		for (iter = m.begin(); iter != m.end(); iter++)
		{
			if (iter->second == max)
				std::cout << iter->first << " ";
		}
		
		std::cout << std::endl;
		
		m.clear();
	}



	in.close();
	

	//system("pause");
	return 0;
}

void InsertMap(std::map<int,int> &m,int n,std::ifstream &in)
{
	int num;
	
	for (int i = 0; i < n; i++)
	{	
		typedef std::pair <int, int> int_pair;
		in >> num;
		std::map<int, int>::iterator Find = m.find(num);

		if (Find != m.end())
		{
			Find->second++;  //만약 이미 있는 숫자라면 값에 1을 더해주고
		}
		else
			m.insert(int_pair(num, 1)); // 없는 숫자라면 새로 만들어서 1로 초기화

	}


}
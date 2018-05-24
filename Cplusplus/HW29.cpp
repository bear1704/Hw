#include <iostream>
#include <map>
#include <fstream>
#include <cmath>

int main()
{
	std::ifstream in;
	in.open("input.txt");

	int cases, n;
	in >> cases;


	for (int c = 0; c < cases; c++)
	{
		in >> n;
		
		int cntVal = 0;  //총 소인수의 갯수
		std::map<int, int> m;
		std::map<int, int>::iterator iter;

		
		int sqrtn = (int)std::sqrt(n);

		for (int div = 2; div <= sqrtn; ++div)
		{
			while (n %  div == 0)
			{
				n /= div;

				if (m.find(div) == m.end()) // 해당 수가 없었던 경우
				{
					m[div] = 1; //1로 초기화하고
					++cntVal;
				}
				else  //이미 존재했던경우
					++m[div];
			}

			if (div > 10000) // 10000이상 소인수는 없다.
				break;
		}

		if (n > 1)  //남은거
		{
			m[n] = 1;
			++cntVal;
		}


		std::cout << cntVal << " ";
		for (iter = m.begin(); iter != m.end(); ++iter)
		{
			std::cout << iter->first << " " << iter->second << " ";
		}
		std::cout << std::endl;
		
		m.clear();

	}

	in.close();
	//system("pause");
	return 0;

}
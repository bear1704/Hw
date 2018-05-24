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
		
		int cntVal = 0;  //�� ���μ��� ����
		std::map<int, int> m;
		std::map<int, int>::iterator iter;

		
		int sqrtn = (int)std::sqrt(n);

		for (int div = 2; div <= sqrtn; ++div)
		{
			while (n %  div == 0)
			{
				n /= div;

				if (m.find(div) == m.end()) // �ش� ���� ������ ���
				{
					m[div] = 1; //1�� �ʱ�ȭ�ϰ�
					++cntVal;
				}
				else  //�̹� �����ߴ����
					++m[div];
			}

			if (div > 10000) // 10000�̻� ���μ��� ����.
				break;
		}

		if (n > 1)  //������
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
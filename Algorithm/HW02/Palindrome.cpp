#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>


using namespace std;

bool palindr(int n_data, int radix);
bool success = false;
int cases = 0; //테스트 케이스 갯수
int n = 0;   // 테스트 데이터 갯수


int main()
{
	
	ifstream in;
	in.open("input.txt");
	
	if (in.fail())
	{
		cerr << "error";
		exit(1);
	}
	in >> cases; 

	for (int i = 0; i < cases; i++)
	{
				in >> n;

				for (int k = 2; k <= 64; k++)
				{
					if (palindr(n, k) == true) //k는 해당 진법, n_data는 테스트 데이터
					{
						cout << "1" << endl;
						success = true;
						break;
					}
				}
				if (success == false) { cout << "0" << endl; }
				success = false;
			
	}





	
	//system("pause");
	in.close();
	return 0;
	



}

bool palindr(int n_data, int radix)
{
	int quotient = n_data / radix; //몫
	int i; //나누기 카운터
	int arr[100]; // 나머지 배열
	int l = 0;
	int r = 0;


	arr[0] = n_data % radix; //첫번째 배열값은 첫 나누기
	i = 1;
	
	while(true)
	{	
		arr[i] = quotient % radix; // 나머지를 먼저 계산해야 몫의 변형이 방지된다.
		quotient /= radix;
		i++;
		if (quotient == 0)
		{
			r = i; //배열 끝 감지용 푯말
			break;
		}
	}




	while (true)
	{
		if ((arr[l] == arr[r - 1]) && (l < r)) //요소가 회문이 성립
		{
			l++;
			r--;
		}
		else if (l >= r) //회문성립하고 카운터가 만나거나 엇갈렸을 경우.
			return true;		
		else
			return false;
	}
	
	//return true;
	
}
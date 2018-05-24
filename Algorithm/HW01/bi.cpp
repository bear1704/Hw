#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>


using namespace std;

int main(void)
{
	ifstream in;

	int top_length = 0;	
	int src1 = 0;
	int src2 = 0;
	int src3 = 0;

	int cases = 0;		
	int k = 0;

	int* a;
	int* b;
	int* c;

	in.open("input.txt");

	in >> cases;

	for (int i = 0; i < cases; i++)
	{


		in >> k;

		
		
		src1 = pow(2, k+1) + k;



		a = new int[src1];		
		b = new int[src1];		
		c = new int[src1];



		for (int j = 0; j < src1; j++)
		{
			a[j] = 0;
			b[j] = 0;
			c[j] = 0;
		}

		for (int j = 2; j < src1 - k; j++)
		{
			in >> a[j];
		}

		for (int j = pow(2, k); j > 0; --j)
		{
			
			src2 = 2*j;
			//cout << src2 << endl;
			src3 = src2+1;



		if (b[src2] + a[src2] > b[src3] + a[src3])
		{
				b[j] = b[src2] + a[src2];
		}
		else
		{
			b[j] = b[src3] + a[src3];
		}

			c[j] = c[src2] + c[src3] + (b[j] - b[src2]) + (b[j] - b[src3]);
		
		
		
		}

		cout << c[1] << endl;


		src1 = 0;
		src2 = 0;
		src3 = 0;

		top_length = 0;




		delete[] a;
		delete[] b;
		delete[] c;


	}

	//system("pause");
	return 0;
}
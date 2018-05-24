#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


class Mono {
public:
	int x;
	int y;
};


struct Node {
	int x, y;
}node[10002];

int comp_1(const Node &a, const Node &b) {
	
	return a.x != b.x ? a.x < b.x : a.y < b.y;
}

int comp_2(const Node &a, const Node &b) {
	return a.y > b.y;
}

int main()
{
	ifstream in;
	in.open("input.txt");
	
	int n;
	int m;
	int cases;
	Mono monoArr[10002];
	

	for (in >> cases; cases--; )
	{
	in >> n;

	for (int i = 0; i<n; ++i)
		in >> node[i].x >> node[i].y;

	sort(node, node + n, comp_1);

	
	for (int i = 0; i<n; )
	{
		int t = i;

		for (int j = i + 1; j<n; ++j)
		{
			if (node[i].x == node[j].x)
				t = j;
			else
				break;
		}

		if(i != t)
		{
			if (node[i - 1].y != node[i].y)
				sort(node + i, node + t + 1, comp_2);
			i = t + 1;
		}
		else
			++i;
	}

	for (in >> m; m--;)
	{
		int k;
	in >> k;
	cout << node[k - 1].x << " " << node[k - 1].y << endl;
	}
	}

	in.close();
	system("pause");
	return 0;
}

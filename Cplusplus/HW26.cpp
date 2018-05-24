#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAX 0xffffffff



int main()
{
	std::ifstream in;
	in.open("input.txt");
	int testCase;
	in >> testCase;

			std::vector<size_t> v;
	for (size_t i = 1;; i *= 2) {
			for (size_t j = i;; j *= 3) {
				for (size_t k = j;; k *= 5) {
					v.push_back(k);
					if (k > MAX / 5) {
						break;
					}
			}
			if (j > MAX / 3) {
				break;
			}
		}
		if (i > MAX / 2) {
			break;
		}
	}
	std::sort(v.begin(), v.end());
	for (int i = 0; i < testCase; ++i) {
		int index;
		in >> index;
		std::cout << v[index - 1] << std::endl;
	}
	
	in.close();
	return 0;
}
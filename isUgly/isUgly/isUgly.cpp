#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//both I and II
class Solution {
public:
	bool isUgly(int num) {
		if (num == 0)return false;
		while (num % 2 == 0)num /= 2;
		while (num % 3 == 0)num /= 3;
		while (num % 5 == 0)num /= 5;
		return num == 1;
	}
	int nthUglyNumber_too_slow(int n) {
		int pos = 0;
		int i = 1;
		for (; pos < n; i++)
		{
			if (isUgly(i)) pos++;
		}
		return i - 1;
	}
	int nthUglyNumber(int n) {
		int Maximum = INT_MAX / 10;
		vector<int> UglyNumbers; UglyNumbers.reserve(Maximum);
		UglyNumbers.push_back(1);
		int max[3], iter[3];
		max[0] = ceil(log10(Maximum) / log10(2));
		max[1] = ceil(log10(Maximum) / log10(3));
		max[2] = ceil(log10(Maximum) / log10(5));
		for (iter[0] = 0; iter[0] <= max[0]; ++iter[0])
			for (iter[1] = 0; iter[1] <= max[1]; ++iter[1])
				for (iter[2] = 0; iter[2] <= max[2]; ++iter[2]) {
					int tmp = pow(2, iter[0]) * pow(3, iter[1]) * pow(5, iter[2]);
					if (tmp < 0)continue;
					else UglyNumbers.push_back(tmp);
				}
		sort(UglyNumbers.begin(), UglyNumbers.end());
		vector<int>::iterator iterer = unique(UglyNumbers.begin(), UglyNumbers.end());
		UglyNumbers.erase(iterer, UglyNumbers.end());
		return UglyNumbers[n - 1];
	}
};


int main()
{
	Solution a;
	cout << a.nthUglyNumber(386);
	getchar();
	return 0;
}

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
		int count = 1;
		vector<int> UglyNumbers; UglyNumbers.reserve(n);
		UglyNumbers.push_back(1);
		for (; count < n;) {
			int min = UglyNumbers[count-1]*2;
			for (int i = 0; i < UglyNumbers.size() && count < n; i++) {
				if (find(UglyNumbers.begin(), UglyNumbers.end(), UglyNumbers[i] * 2) == UglyNumbers.end()) { if (UglyNumbers[i] * 2 < min&&UglyNumbers[i] * 2>0) min = UglyNumbers[i] * 2; }
				if (find(UglyNumbers.begin(), UglyNumbers.end(), UglyNumbers[i] * 3) == UglyNumbers.end()) { if (UglyNumbers[i] * 3 < min&&UglyNumbers[i] * 3>0) min = UglyNumbers[i] * 3; }
				if (find(UglyNumbers.begin(), UglyNumbers.end(), UglyNumbers[i] * 5) == UglyNumbers.end()) { if (UglyNumbers[i] * 5 < min&&UglyNumbers[i] * 5>0) min = UglyNumbers[i] * 5; }
			}
			UglyNumbers.push_back(min);
			++count;
		}
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

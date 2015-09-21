#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int addDigits_recursion(int num) {
		int count = 0;
		for (; num != 0;) {
			count += num % 10; num /= 10;
		}
		if (count >= 10)
			return addDigits_recursion(count);
		else
			return count;
	}
	int addDigits(int num) {
		return 1 + (num - 1) % 9;
	}
};


int main()
{
	Solution a;
	cout << a.addDigits(38);
	getchar();
	return 0;
}

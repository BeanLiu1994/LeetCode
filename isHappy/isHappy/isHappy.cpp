#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int oneiter(int n){
		int count = 0;
		for (; n != 0;){
			count += (n % 10)*(n % 10); n /= 10;
		}
		return count;
	}

	bool isHappy(int n) {
		vector<int> queue;
		for (; n != 1;){
			if (find(queue.begin(), queue.end(), n)!=queue.end())
				return false;
			queue.push_back(n);
			n = (oneiter(n));
		}
		return true;
	}
};

int main() {
	Solution a;
	cout<<a.isHappy(2);
	getchar();
	return 0;
}
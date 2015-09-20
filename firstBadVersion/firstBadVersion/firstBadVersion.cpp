#include <iostream>
#include <vector>
using namespace std;
bool isBadVersion(int version)
{
	if (version >= 1) return 1;
	else return 0;
}

class Solution {
public:
	int firstBadVersion(int n) {
		return bisearch(1, n, &isBadVersion);
	}
	int bisearch(int start, int end, bool(*judge)(int)) {
		for (; end - start > 1;) {
			int midpos = int(((long long)end + (long long)start) / 2);
			if (!(*judge)(midpos)) start = midpos;
			else end = midpos;
		}
		if (end - start == 1) {
			if (!(*judge)(start))	return end;
			else return start;
		}
		else if (end - start == 0) return start;
	}
};


int main()
{
	Solution a;
	cout << a.firstBadVersion(2);
	getchar();
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int id1 = 1, id2 = nums.size();
		int sum;
		do{
			sum = nums[id1 - 1] + nums[id2 - 1];
			if (sum > target) --id2;
			else if (sum < target) ++id1;
			else break;
		} while (id2 > id1);
		id1_origin = find(nums.begin(), nums.end(), ) - nums.begin();
		return vector<int>({ id1, id2 });
	}
};

int main()
{
	Solution a;
	getchar();
	return 0;
}

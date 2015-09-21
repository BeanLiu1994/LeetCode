#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> nums_workspace = nums;
		sort(nums_workspace.begin(), nums_workspace.end());
		int id1 = 1, id2 = nums.size();
		int sum;
		do{
			sum = nums_workspace[id1 - 1] + nums_workspace[id2 - 1];
			if (sum > target) --id2;
			else if (sum < target) ++id1;
			else break;
		} while (id2 > id1);
		int id1_origin = find(nums.begin(), nums.end(), nums_workspace[id1 - 1]) - nums.begin() + 1;
		int id2_origin = find(nums.begin(), nums.end(), nums_workspace[id2 - 1]) - nums.begin() + 1;
		if (id2_origin == id1_origin) {
			id2_origin = find(nums.begin() + id1_origin, nums.end(), nums_workspace[id2 - 1]) - nums.begin() + 1;
		}
		vector<int> result({ id1_origin, id2_origin });
		sort(result.begin(), result.end());
		return result;
	}
};

int main()
{
	vector<int> input({0,4,3,0});
	Solution a;

	getchar();
	return 0;
}

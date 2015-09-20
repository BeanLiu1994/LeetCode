#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int zeros_count = 0, SizeOfNums = nums.size();
		for (int i = 0; i < SizeOfNums - zeros_count; )
		{
			if (nums[i+zeros_count] == 0)
			{
				++zeros_count;
			}
			else
			{
				if (zeros_count > 0)
				{
					nums[i] = nums[i + zeros_count];
				}
				++i;
			}
		}
		for (int i = SizeOfNums - zeros_count; i < SizeOfNums; i++)
		{
			nums[i] = 0;
		}
	}
};

//vector<int> input = { 1,0,0 };
vector<int> input = { 0,1,0,3,12 };

int main()
{
	cout << "origin: ";
	for (int i = 0; i < input.size(); i++)
	{
		cout << input[i] << " ";
	}
	cout << endl;
	Solution a;
	a.moveZeroes(input);
	cout << "after: ";
	for (int i = 0; i < input.size(); i++)
	{
		cout << input[i] << " ";
	}
	cout << endl;
	getchar();
	return 0;
}

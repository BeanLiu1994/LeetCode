#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> string2num(string num) {
		int Size = num.size();
		vector<int> input; input.reserve(Size);
		const char *pNumString = num.c_str();
		for (int i = 0; i < Size; i++) input.push_back(pNumString[i] - '0');
		return input;
	}
	vector<string> addOperators(string num, int target) {
		vector<int> input = string2num(num);
		vector<string> output;
		int Size = input.size();
		if (Size > 2)
		{
			string subinput; subinput.reserve(Size - 1);
			for (int i = 0; i < Size - 1; i++) subinput.push_back(input[i] + '0');
			// for "+" condition...
			vector<string> plus_subcondition = addOperators(subinput, target - input[Size - 1]);
			for (int i = 0; i < plus_subcondition.size(); i++) output.push_back(plus_subcondition[i] + "+" + num[Size - 1]);
			// for "-" condition...
			vector<string> minus_subcondition = addOperators(subinput, target + input[Size - 1]);
			for (int i = 0; i < minus_subcondition.size(); i++) output.push_back(minus_subcondition[i] + "-" + num[Size - 1]);
			// for "*" condition...
			vector<string> multiply_subcondition;
			if (target% input[Size - 1] == 0)
			{
				multiply_subcondition = addOperators(subinput, target / input[Size - 1]);
				for (int i = 0; i < multiply_subcondition.size(); i++) output.push_back(multiply_subcondition[i] + "*" + num[Size - 1]);
			}
			
		}
		else if (Size == 2)
		{
			if (input[0] + input[1] == target)
				output.push_back(string("") + num[0] + "+" + num[1]);
			if (input[0] - input[1] == target)
				output.push_back(string("") + num[0] + "-" + num[1]);
			if (input[0] * input[1] == target)
				output.push_back(string("") + num[0] + "*" + num[1]);
		}
		return output;
	}
};

string input = "232";
int target = 8;

int main()
{
	cout << input << " " << target << endl;
	Solution a;
	vector<string>result = a.addOperators(input, target);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i]<< endl;
	}
	getchar();
	return 0;
}

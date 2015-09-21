#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode p[10];
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (root == NULL) return result;
		if (root->left != NULL)	{
			vector<string> tmp = binaryTreePaths(root->left);
			for (int i = 0; i < tmp.size(); i++) {
				result.push_back(tmp[i]);
			}
		}
		if (root->right != NULL){
			vector<string> tmp = binaryTreePaths(root->right);
			for (int i = 0; i < tmp.size(); i++) {
				result.push_back(tmp[i]);
			}
		}
		if (root->right == NULL && root->left == NULL)
		{
			char tmp_c[10]; sprintf(tmp_c, "%d", root->val);
			string tmp(tmp_c);
			result.push_back(tmp);
			return result;
		}
		for (int i = 0; i < result.size(); i++) {
			char tmp_c[10]; sprintf(tmp_c, "%d", root->val);
			result[i] = string(tmp_c) + "->" + result[i];
		}
		return result;
	}
};

//vector<int> input = { 1,0,0 };
int main()
{
	p->val = 1;
	(p + 1)->val = 2;
	(p + 2)->val = 3;
	p->left = p + 1;
	p->right = p + 2;
	Solution a;
	vector<string> result = a.binaryTreePaths(p);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	getchar();
	return 0;
}

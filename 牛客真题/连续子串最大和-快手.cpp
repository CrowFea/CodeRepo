/*
题目描述
一个非空整数数组，选择其中的两个位置，使得两个位置之间的数和最大。
如果最大的和为正数，则输出这个数；如果最大的和为负数或0，则输出0
输入描述:
3,-5,7,-2,8
输出描述:
13
示例1
输入?
复制
-6,-9,-10
输出
复制
0
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> nums;
	int num=0, n = 0;
	while (cin>>num) {
		nums.push_back(num);
		if (cin.get() == '\n')	break;
	}
	num = 0;
	int maxnum = 0;
	for (int i = 0; i < nums.size(); ++i) {
		num = max(num + nums[i], 0);
		maxnum = max(maxnum, num);
	}
	maxnum = max(maxnum, nums[nums.size() - 1]);
	cout << maxnum << endl;
	return 0;
}
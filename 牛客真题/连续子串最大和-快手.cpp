/*
��Ŀ����
һ���ǿ��������飬ѡ�����е�����λ�ã�ʹ������λ��֮����������
������ĺ�Ϊ������������������������ĺ�Ϊ������0�������0
��������:
3,-5,7,-2,8
�������:
13
ʾ��1
����?
����
-6,-9,-10
���
����
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
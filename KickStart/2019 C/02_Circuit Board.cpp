#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXNUM 10000000

int solve(vector<vector<int>> nums, int k1,int r,int c) 
{
	int maxnum = 0, minnum = 0;
	vector<vector<int>> dp(r, vector<int>(c, 0));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			dp[i][j] = 1;
			maxnum = nums[i][j];
			minnum = nums[i][j];
			for (int k = j + 1; k < c; ++k) {
				maxnum = max(maxnum, nums[i][k]);
				minnum = min(minnum, nums[i][k]);
				if (maxnum - minnum > k1)	break;
				else
				{
					++dp[i][j];
				}
			}
		}
	}
	int res = 0;
	minnum = MAXNUM;
	for (int j = 0; j < c; ++j) {
		for (int i = 0; i < r; ++i) {
			minnum = dp[i][j];
			for (int k = i; k < r; ++k) {
				minnum = min(dp[k][j], minnum);
				res = max(res, minnum*(k - i+1));
			}
		}
	}
	return res;
}

int main() 
{
	int t;
	cin >> t;
	for (int tt = 0; tt < t; ++tt) {
		int r, c, k;
		cin >> r >> c >> k;
		vector<vector<int>> nums(r, vector<int>(c, 0));
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> nums[i][j];
			}
		}
		int res = solve(nums,k,r,c);
		cout << "Case #" << tt + 1 << ": " << res << endl;
	}
	return 0;
}
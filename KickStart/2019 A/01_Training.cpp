#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int T, N, P;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> P;
		vector<int> nums(N, 0);
		for (int j = 0; j < N; ++j) {
			cin >> nums[j];
		}
		sort(nums.begin(), nums.end());
		int temp = 0, minnum = 0;
		for (int j = N - 1; j >= N - P; --j) {
			temp += nums[j];
		}
		minnum = nums[N - 1]*P-temp;
		for (int j = N - 1; j >= P; --j) {
			temp = temp - nums[j] + nums[j - P];
			minnum = min(minnum, nums[j-1]*P-temp);
			if (minnum == 0)   break;
		}
		cout << "Case #" << i+1 << ": " << minnum << endl;
	}
	return 0;
}
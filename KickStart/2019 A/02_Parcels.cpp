#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

#define INF 900000

int BFS(vector<vector<int>> nums, vector<vector<int>> &cost) {
	queue<pair<int,int>> q;
	int dx[4] = { 0,-1,1,0 }, dy[4] = { 1,0,0,-1 };
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 0; j < nums[0].size(); ++j) {
			if (nums[i][j] == 1)	q.push(make_pair(i, j));
		}
	}
	int maxdist = 0;
	while (!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();
		maxdist = cost[cur.first][cur.second];
		for (int k = 0; k < 4; ++k) {
			int x = cur.first + dx[k];
			int y = cur.second + dy[k];
			if (x < nums.size() && x >= 0 && y < nums[0].size() && y >= 0 && cost[x][y] == -1) {
				cost[x][y] = maxdist + 1;
				q.push(make_pair(x, y));
			}
		}

	}
	return maxdist;
}

bool isMatch(int mid, vector<vector<int>> nums, vector<vector<int>> cost) {
	int x = -INF;
	int y = INF;
	int z = -INF;
	int w = INF;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 0; j < nums[0].size(); ++j) {
			if (cost[i][j] > mid) {
				x = max(x, i + j);
				y = min(y, i + j);
				z = max(z, i - j);
				w = min(w, i - j);
			}
		}
	}
	if (w == INF) 
		return true;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 0; j < nums[0].size(); ++j) {
			if (abs(x - (i + j)) <= mid &&
				abs(y - (i + j)) <= mid &&
				abs(z - (i - j)) <= mid &&
				abs(w - (i - j)) <= mid)
				return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int p = 0; p < T; ++p) {

		int R, C;
		cin >> R >> C;
		vector<vector<int>> nums(R, vector<int>(C, 0));
		vector<vector<int>> cost(R, vector<int>(C, -1));
		string s;
		for (int i = 0; i < R; ++i) {
			cin >> s;
			for (int j = 0; j < C; ++j) {
				nums[i][j]=int(s[j]-48);
				if(nums[i][j]==1)
					cost[i][j] = 0;
			}
		}
		int high = BFS(nums, cost);
		int low = 0;
		while (low <= high) {
			int mid = (high + low) >> 1;
			if (isMatch(mid,nums,cost))
				high = mid - 1;
			else
				low = mid + 1;
		}
		cout << "Case #" << p + 1 << ": " << high+1 << endl;
	}
	return 0;
}
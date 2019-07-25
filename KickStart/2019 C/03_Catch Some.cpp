#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXNUM 1005

int dp[MAXNUM][MAXNUM][2];

int main()
{
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas)
	{
		int n, m;
		cin >> n >> m;
		vector<int> g[MAXNUM];
		vector<int> a(MAXNUM), b(MAXNUM);
		for (int i = 1; i <= 1000; ++i) g[i].clear();
		for (int i = 1; i <= n; ++i) 
			cin>>a[i];
		for (int i = 1; i <= n; ++i) 
			cin>>b[i];
		for (int i = 1; i <= n; ++i) 
			g[b[i]].push_back(a[i]);

		for (int i = 1; i <= 1000; ++i) 
			sort(g[i].begin(), g[i].end());
		for (int i = 0; i <= 1000; ++i)
			for (int j = 0; j <= 1000; ++j)
				dp[i][j][0] = dp[i][j][1] = 1e9;


		for (int i = 0; i <= 1000; ++i) 
			dp[i][0][0] = dp[i][0][1] = 0;
		for (int i = 1; i <= 1000; ++i){
			for (int k = 0; k <= m; ++k) {
				dp[i][k][0] = dp[i - 1][k][0];
				dp[i][k][1] = dp[i - 1][k][1];
			}
			for (int j = 0; j < g[i].size(); ++j){
				int o = j + 1, d = g[i][j];
				for (int k = o; k <= m; ++k){
					dp[i][k][0] = min(dp[i][k][0], dp[i - 1][k - o][0] + 2 * d);
					dp[i][k][1] = min(dp[i][k][1], dp[i - 1][k - o][0] + d);
					dp[i][k][1] = min(dp[i][k][1], dp[i - 1][k - o][1] + 2 * d);
				}
			}
		}
		int ans = 1e9;
		for (int i = 1; i <= 1000; ++i) 
			ans = min(ans, dp[i][m][1]);
		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}
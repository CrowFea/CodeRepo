#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_TIME 100 * 100 + 1010

using namespace std;

struct stones
{
	int s;
	int e;
	int l;
};

vector<stones> st(100);

bool mycmp(const struct stones &stones1, const struct stones &stones2)
{
	return stones1.s*stones2.l < stones1.l*stones2.s;
}


int solve()
{
	vector<int> dp(MAX_TIME);
	sort(st.begin(), st.end(), mycmp);
	int ans = 0;
	for (int j = 0; j < st.size(); j++) {
		for (int k = MAX_TIME - 1; k >= st[j].s; k--) {
			int currE = max(st[j].e - (k - st[j].s) * st[j].l, 0);
			dp[k] = max(dp[k - st[j].s] + currE, dp[k]);
			ans = max(ans, dp[k]);
		}
	}
	return ans;
}

int main() 
{
	int T;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		
		int n;
		cin >> n;
		st.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> st[i].s >> st[i].e >> st[i].l;
		}
		int res = solve();
		cout << "Case #" << tt + 1 << ": " << res << endl;
	}
	return 0;
}
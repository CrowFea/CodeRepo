#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

const int N = (int) 2e5 + 6, mod = (int)0;
int seg[N << 2], ch[N << 2];
int a[N];
vector<int> all[N];

void update(int i, int j, int x, int v = 1, int b = 0, int e = N) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		seg[v] += x;
		ch[v] += x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	seg[v] = max(seg[l], seg[r]) + ch[v];
}

int main() {
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		memset(seg, 0, sizeof seg);
		memset(ch, 0, sizeof ch);
		for (int j = 0; j < N; ++j) all[j].clear();
		int n, s;
		cin >> n >> s;
		int res = 0;
		for (int j = 0; j < n; ++j) cin >> a[j], --a[j], all[a[j]].push_back(j);
		for (int j = 0; j < n; ++j) {
			int cur = a[j];
			update(0, j + 1, 1);
			int pos = lower_bound(ALL(all[cur]), j) - all[cur].begin();
			if (pos >= s) {
				int xl = all[cur][pos - s];
				update(0, xl + 1, -1);
				int bef = (pos - s == 0 ? -1 : all[cur][pos - s - 1]);
				update(bef + 1, xl + 1, -s);
			}
			res = max(res, seg[1]);
		}
		cout << "Case #" << tt << ": " << res << endl;
	}
	return 0;
}


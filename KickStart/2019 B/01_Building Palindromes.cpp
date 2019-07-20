#include <iostream>
#include <algorithm>
#include <vector>
#include<string>

using namespace std;

const int N = (int) 2e5 + 5, mod = (int)0;
int sum[N][26];

int main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < 26; ++i) {
				sum[j + 1][i] = sum[j][i] ^ (s[j] == i + 'A');
			}
		}
		int res = 0;
		for (int j = 0; j < q; ++j) {
			int l, r;
			cin >> l >> r;
			--l;
			int cnt = 0;
			for (int i = 0; i < 26; ++i)
				cnt += sum[r][i] ^ sum[l][i];
			if (cnt <= 1) ++res;
		}
		cout << "Case #" << tt << ": " << res << '\n';

	}
	return 0;
}

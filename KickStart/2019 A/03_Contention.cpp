#include<iostream>
#include<vector>
#include<algorithm>
#include<assert.h>

using namespace std;

int isOK(int k, vector<pair<int, int>> book,int n,int q) {
	if (k == 0)return true;
	vector<int> bg(q, 0);

	for (int i = 0; i < q; ++i) {
		int sweep_to = max(book[i].first, bg[i]), ed = book[i].second;
		int next_start = ed;
		int cnt = 0;

		for (int j = i + 1; j < q; ++j) {
			int l = book[j].first, r = book[j].second;
			if (l > ed)break;
			if (r <= ed) {
				if (l > sweep_to)cnt += l - sweep_to;
				sweep_to = max(sweep_to, r);
				if (cnt >= k) {
					next_start = l - (cnt - k);
					break;
				}
			}
		}
		if (cnt < k) {
			cnt += ed - sweep_to;
			if (cnt < k)return false;
			next_start = ed - (cnt - k);
		}

		for (int j = i + 1; j < q; ++j) {
			int l = book[j].first, r = book[j].second;
			if (l >= next_start)break;
			if (book[j].second > ed) {
				bg[j] = max(bg[j], ed);
			}
		}
	}
	return true;

}


int solve(vector<pair<int, int>> book,int n,int q) {
	sort(book.begin(), book.end());
	int high = n, low = 0;
	while (low <= high) {
		int mid = (high + low) >> 1;
		if (isOK(mid, book,n,q))   low = mid + 1;
		else    high = mid - 1;
	}
	
	return low - 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int round = 0; round < T; ++round) {
		int n, q;
		cin >> n >> q;
		vector<pair<int, int>> book(q);
		for (int i = 0; i < q; ++i) {
			cin >> book[i].first;
			book[i].first--;
			cin >> book[i].second;
		}
		
		int res = solve(book,n,q);
		cout << "Case #" << round+1 << ": " << res << endl;
	}
	return 0;
}
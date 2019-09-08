#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,M;
    int d,p;
    cin>>N>>M;
    vector<pii> a(N);
    for(int i=0;i<N;++i){
       cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end());
    vector<int> b(N);
    b[0] = a[0].second;
    for (int i = 1; i < N; i++) {
        b[i] = max(a[i].second, b[i - 1]);
    }
    for (int i = 0; i < M; i++) {
        int v;
        cin >> v;
        auto x = upper_bound(a.begin(), a.end(), pii(v, 1000000005)) - a.begin();
        cout << b[x - 1] << endl;
    }
    return 0;
}
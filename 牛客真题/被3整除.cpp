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
    
    int l,r;
    cin>>l>>r;
    int res=0;
    for(int i=l;i<=r;++i){
        if(i%3==1)    continue;
        else    ++res;
    }
    cout<<res<<endl;
    return 0;
}
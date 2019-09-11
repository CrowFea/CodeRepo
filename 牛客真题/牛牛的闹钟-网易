/*
题目描述
牛牛总是睡过头，所以他定了很多闹钟，只有在闹钟响的时候他才会醒过来并且决定起不起床。从他起床算起他需要X分钟到达教室，上课时间为当天的A时B分，请问他最晚可以什么时间起床
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含一个正整数，表示闹钟的数量N(N<=100)。
接下来的N行每行包含两个整数，表示这个闹钟响起的时间为Hi(0<=A<24)时Mi(0<=B<60)分。
接下来的一行包含一个整数，表示从起床算起他需要X(0<=X<=100)分钟到达教室。
接下来的一行包含两个整数，表示上课时间为A(0<=A<24)时B(0<=B<60)分。
数据保证至少有一个闹钟可以让牛牛及时到达教室。
输出描述:
输出两个整数表示牛牛最晚起床时间。
示例1
输入
复制
3 
5 0 
6 0 
7 0 
59 
6 59
输出
复制
6 0
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define pii pair<int,int>
#define mp make_pair

int biSearch(vector<int> data, int num){
        int s = 0, e = data.size()-1;     
        while(s <= e){
            int mid = (e - s)/2 + s;
            if(data[mid]==num)    return mid;
            else if(data[mid] < num)
                s = mid + 1;
            else if(data[mid] > num)
                e = mid - 1;
        }
        return s-1;
    }

pii change(vector<pii> nz,pii limit,int cost)
{
    vector<int> nums;
    for(int i=0;i<nz.size();++i){
        nums.push_back(nz[i].first*60+nz[i].second);
    }
    sort(nums.begin(),nums.end());
    int t=limit.first*60+limit.second-cost;
    int r=nums[biSearch(nums,t)];
    pii res;
    res.first=r/60;
    res.second=r%60;
    return res;
}

int main()
{
    vector<pii> nz;
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;++i){ 
        cin>>a>>b;
        nz.push_back(mp(a,b));
    }
    int cost;
    pii limit;
    cin>>cost>>a>>b;
    limit=mp(a,b);
    pii res=change(nz,limit,cost);
    cout<<res.first<<" "<<res.second<<endl;
    return 0;
    
}
class Solution {
	static bool comp(const vector<int> &a, const vector<int> &b){
		return a[1]<b[0];
	}
public:
	vector<vector<int> > insert(vector<vector<int> > &A, vector<int> &a) {
		int i=lower_bound(A.begin(),A.end(),a,comp)-A.begin(), j=0;
		for(j=i; j<A.size() && a[1]>=A[j][0]; ++j)
			a={min(a[0],A[j][0]), max(a[1],A[j][1])};
		A.insert(A.begin()+j,a);
		A.erase(A.begin()+i, A.begin()+j);
		return A;
	}
};
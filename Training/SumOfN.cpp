/*
有关n数之和的各种问题
* 二数之和
* 三数之和
* 最接近的三数之和
* 四数之和
*/

class Solution{
public:
/*
两数之和，求两数之和为target的数对
假设只有一对
*/
    vector<int> TwoSum(vector<int>& nums,int target){
        map<int,int> m;
        vector<int> res;
        for(int i=0;i<nums.size(); ++i){
            if(m.count(target-nums[i])){
                res.push_back(nums[i]);
                res.push_back(target-nums[i]);
                break;
            }
            m[nums[i]]++;
        }
        return res;
    }

/*
三数之和，求三数之和为0的数对
不只有一对
*/
    vector<vector<int>> ThreeSum(vector<int>& nums){
        vector<vector<int>> res;
		if(nums.size()<=2)	return res;
		sort(nums.begin(),nums.end());
		int i,j;
		for(int k=0;k<nums.size();k++){
			if(nums[k]>0)	break;
			if(k>0 && nums[k-1]==nums[k])	continue;
			i=k+1;
			j=nums.size()-1;
			while(i<j){
				if(nums[i]+nums[j]+nums[k]==0){
					vector<int> temp;
					temp.push_back(nums[k]);
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					res.push_back(temp);
					++i;
					--j;
					while(i<j && nums[i]==nums[i-1])	++i;
					while(i<j && nums[j]==nums[j+1])	--j;
					continue;
				}
				else if(nums[i]+nums[j]+nums[k]<0){
					++i;
					continue;
				}
				else	--j;
			}
		}
		return res;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<=2)  return 0;
        sort(nums.begin(),nums.end());
        int res=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();++i){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int b=(nums[i]+nums[l]+nums[r]);
                if(abs(target-b)<abs(target-res))   res=b;
                if(b<target)    l++;
                if(b>target)    r--;
                if(b==target)   return target;
            }
        }
    }
};
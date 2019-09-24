#define ElemType int

class Solution {
public:
//===============================直接插入排序
    void StarightInsertSort(vector<ElemType> nums){
        int n=nums.size();
        int senti=0;    //使用一个哨兵
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                senti=nums[i];
                for(int j=i-1;nums[j]>senti;--j)
                    nums[j+1]=nums[j];
                nums[j+1]=senti;
            }
        }
    }

//===============================二分插入排序
    void BinaryInsertSort(vector<ElemType> nums){
        int n=nums.size();
        int senti=0;
        for(int i=1;i<n;++i){
            senti=nums[i];
            int low=0,high=n-1;
            while(low<=high){
                int mid=(low+high)<<1;
                if(nums[mid]<senti) low=mid+1;
                if(nums[mid>senti]) high=mid-1;
            }
            for(int j=i;j>=high+1;j--){
                nums[j+1]=nums[j];
            }
            nums[j+1]=nums[high+1];
        }   
    }

//===============================希尔排序 
    void ShellSort(vector<ElemType> nums){
        int n=nums.size();
        for(int step=n/2;step>0;step/=2){
            for(int i=0;i<i+step;i+=step){
                for(int j=0;j<i; ++j){
                    if(nums[j]<nums[j+1])
                }
            }
        }
    }

    void BubbleSort(vector<ElemType> nums){
        for(int i=0;i<nums.size();++i){
            for(int j=1;j<nums[i].size();++j){

            }
        }
    }

//===============================================================快排
    int partition(vector<ElemType> nums,int low,int high){
        ElemType senti=nums[low];
        while(low<high){
            while(low<high && nums[high]>=senti)    --high;
            nums[low]=nums[high];
            while(low<high && nums[low]<=senti)     ++low;
            nums[high]=nums[low];
        }
        nums[low]=senti;
        return low;
    }

    void Quicksort(vector<ElemType> nums,int low=0,int high=nums.size()){
        if(low<high){
            int partpos=parition(nums,low,high);
            Quicksort(nums,low,partpos-1);
            Quicksort(nums,partpos+1,high);
        }
        return;
    }

//========================================选择排序
    void SelectSort(vector<ElemType> nums){
        for(int i=0;i<nums.size()-1;++i){
            int minpos=i;
            for(int j=i+1;j<nums.size();++j){
                if(nums[j]<nums[minpos])    minpos=j; 
            }
            if(minpos!=i)   swap(nums[i],nums[minpos]);
        }
    }
};




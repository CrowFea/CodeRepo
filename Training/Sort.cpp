#define ElemType int

class Solution {
public:
//===============================直接插入排序
    void StarightInsertSort(vector<ElemType> &nums){
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
    void BinaryInsertSort(vector<ElemType> &nums){
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
    void ShellSort(vector<ElemType> &nums){
        int n=nums.size();
        for(int step=n/2;step>=1;step/=2){
            for(int i=step+1;i<n;++i){
                if(nums[i]<nums[i-step]){
                    nums[0]=nums[i];
                    for(int j=i-step;j>0 && nums[0]<nums[j];j-=step)    nums[j+dk]=nums[j];
                    nums[j+step]=nums[0];
                }
            }
        }
    }

//===============================冒泡排序
    void BubbleSort(vector<ElemType> &nums){
        bool flag=false;
        for(int i=0;i<nums.size()-1;++i){
            flag=false;
            for(int j=1;j<nums[i].size();++j){
                if(nums[j]<nums[j-1]){
                    swap(nums[i],nums[j]);
                    flag=true;
                }
            }
            if(flag==false) return;
        }
    }

//===============================================================快排
    int partition(vector<ElemType> &nums,int low,int high){
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

    void Quicksort(vector<ElemType> &nums,int low=0,int high=nums.size()){
        if(low<high){
            int partpos=parition(nums,low,high);
            Quicksort(nums,low,partpos-1);
            Quicksort(nums,partpos+1,high);
        }
        return;
    }

//========================================选择排序
    void SelectSort(vector<ElemType> &nums){
        for(int i=0;i<nums.size()-1;++i){
            int minpos=i;
            for(int j=i+1;j<nums.size();++j){
                if(nums[j]<nums[minpos])    minpos=j; 
            }
            if(minpos!=i)   swap(nums[i],nums[minpos]);
        }
    }

//============================================================堆排序
    void AdjustHeap(vector<ElemType>& nums,int k,int n){
        ElemType senti=nums[k];
        for(int i=2*k;i<n;i*=2){
            if(i<n && nums[i]<nums[i+1])
                ++i;
            if(nums[i]<senti)   break;
            else{
                nums[k]=nums[i];
                k=i;
            }
        }
        nums[k]=senti;
    }

    void BuildHeap(vector<ElemType>& nums){
        int n=nums.size();
        for(int i=n/2;i>0;--i){
            AdjustHeap(nums,i,n);
        }
    }

    void HeapSort(vector<ElemType> &nums){
        BuildHeap(nums);
        for(int i=nums.size()-1;i>0;--i){
            swap(nums[0],nums[i]);
            AdjustHeap(nums,0,i-1);
        }
    }
//向上调整
    void AdjustHeapUp(vector<ElemType> &nums,int k){
        ElemType senti=nums[k];
        int i=k/2;
        while(i>=0 && nums[i]<senti){
            nums[k]=nums[i];
            k=i; 
            i=k/2;
        }
        nums[k]=nums[0];
    }

//============================================================归并排序
    void Merge(vector<ElemType> &nums,int low,int mid,int high){
        vector<ElemType> temp=nums;
        for(int i=low,j=mid+1,k=low;i<mid && j<high;++k){
            if(temp[i]>temp[j]) nums[k]=temp[j++];
            if(temp[i]<temp[j]) nums[k]=temp[i++];
        }
        while(i<mid)    nums[k++]=temp[i++];
        while(j<high)   nums[k++]=temp[j++];
    }

    void MergeSort(vector<ElemType> &nums,int low,int high){
        if(low<high){
            int mid=(low+high)/2;
            MergeSort(nums,low,mid);
            MergeSort(nums,mid+1,high);
            Merge(nums,low,mid,high);
        }
    }


};




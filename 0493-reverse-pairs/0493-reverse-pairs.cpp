class Solution {

    void merge(vector<int>& arr, int low, int mid, int high){
        vector<int> temp;
        int left = low, right = mid+1;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        left=low;
        for(int i=0; i<temp.size(); i++){
            arr[low]=temp[i];
            low++;
        }
    }

    int countReverse(vector<int>& arr, int low, int mid, int high){
        int count =0;
        int i=low, j=mid+1;
        while(i<=mid){
            while(j<=high && arr[i]>2* (long long) arr[j]){
                j++;
            }
            count+=(j-(mid+1));
            i++;
        }
        return count;
    }

    int mergeSort(vector<int> &arr, int low, int high){
        int count = 0;
        if(low>=high) return count;

        int mid = (low+high)/2;

        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += countReverse(arr, low, mid,high);
        merge(arr, low, mid, high);
        return count;
    }

public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
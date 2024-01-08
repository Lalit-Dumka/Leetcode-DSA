class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0, high=n-1;
        int sol = INT_MAX;
        while(low<=high){
            int mid =(low+high)/2;
            sol=min(sol,nums[mid]);
            if(nums[low]<=nums[mid] && nums[mid]<=nums[high]){
                sol = min(sol,nums[low]);
                break;
            }
            
            if(nums[low]<nums[mid]){
                sol=min(sol,nums[low]);
                low=mid+1;
            }
            else{
                sol = min(sol,nums[mid+1]);
                high=mid-1;
            }
        }
        return sol;
    }
};
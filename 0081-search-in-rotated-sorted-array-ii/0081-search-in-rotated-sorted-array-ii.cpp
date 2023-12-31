class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left =0, right =n-1;
        while(left<=right){
            int mid= (right+left)/2;
            if(nums[mid]==target) return true;
            
            if(nums[mid]==nums[left] && nums[mid]==nums[right]){
                left++;
                right--;
                continue;
            }
            
            if(nums[mid]<=nums[right]){
                if(nums[mid]<target && nums[right]>=target){
                    left = mid+1;
                }
                else right = mid-1;
            }
            else{
                if(nums[left]<=target&&nums[mid]>target){
                    right = mid-1;
                }
                else left = mid+1;
            }
        }
        return false;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        for(int k=0; k<n; k++){
            int start = k+1, end = n-1;
            if(k>0&&nums[k]==nums[k-1])continue;
            while(start<end){
                int sum = nums[start]+nums[end]+nums[k];
                if(sum==0){
                   sol.push_back(vector<int>({nums[k],nums[start],nums[end]}));
                    start++;
                    end--;
                    while(start < end and (nums[start-1] == nums[start])) start++;
                    while(start < end and (nums[end+1] == nums[end])) end--;
                } else if(sum<0){
                    start++;
                } else{
                    end--;
                }
            }
        }
        return sol;
    }
};
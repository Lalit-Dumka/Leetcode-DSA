class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; ++i){
            int left = i+1, right = n-1;
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]==0){
                    vector<int> temp = {nums[i],nums[left],nums[right]};
                    sol.push_back(temp);
                    ++left;
                    --right;
                    while(left<n && nums[left]==nums[left-1]) ++left;
                    while(right>=0 && nums[right]==nums[right+1]) --right;
                }
                else if(nums[i]+nums[left]+nums[right]<0){
                    ++left;
                }
                else{
                    --right;
                }
            }
            
        }
        return sol;
    }
};
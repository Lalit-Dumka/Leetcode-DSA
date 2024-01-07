class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = 0;
        int sum = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            cur_sum+= nums[i];
            sum = max(sum,cur_sum);
            if(cur_sum <0) cur_sum = 0;
        }
        return sum;
    }
};
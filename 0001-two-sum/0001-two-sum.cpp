class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        int n= nums.size();
        map<int,int> mp;

        for(int i=0; i<n; i++){
            int req=target-nums[i];
            if(mp.find(req)!=mp.end()){
                result.push_back(mp[req]);
                result.push_back(i);
            }
            mp[nums[i]]=i;
        }

        return result;
    }
};
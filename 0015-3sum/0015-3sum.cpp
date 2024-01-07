class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        int i=0, j=0,k=n-1;
        
        for(int i=0; i<=n-3; i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            j = i+1;
            k = n-1;
            while(j<k){
                int sum = (nums[i]+ nums[j]+nums[k]);
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.insert(temp);
                    do{
                        j++;
                    }while(j<k && nums[j]==nums[j-1]);
                    do{
                        k--;
                    }while(j<k && nums[k]==nums[k+1]);
                }
            }            
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};
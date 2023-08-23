class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int c=1, max=1;
        map<int,int>::iterator it = mp.begin();
        int prev=it->first;
        cout<<prev<<" ";
        it++;
        while(it!=mp.end()){
            int cur = it->first;
            cout<<it->first<<" ";
            if(cur==prev){
                c=c;
            }
            else if(cur==prev+1){
                c++;
            }
            else{
                c=1;
            }

            if(max<c) max=c;
            prev=cur;
            it++;
        }
        return max;
    }
};
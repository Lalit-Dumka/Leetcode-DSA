class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> visited;
        int i=0, j=0, count=0, max=0 , n = s.size();
        // if(n<2)return n;
        while(i<n){
            // cout<<s[i];
            if(visited.count(s[i])){
                // cout<<s[i];
                i=j+1;
                j++;
                visited.clear();
                count=0;
            }
            else{
                visited.insert(s[i]);
                count++;
                i++;
            }
            if(max<count){
                max=count;
            }
        }
        return max;
    }
};
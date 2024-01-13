class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> counts;
        
        int n = s.length();
        
        for(int i =0; i<n; i++){
            counts[s[i]]++;
            
            counts[t[i]]--;
        }
        int sol = 0;
        for(auto it : counts){
            sol+=abs(it.second);
        }
        return sol/2;
        
        
    }
};
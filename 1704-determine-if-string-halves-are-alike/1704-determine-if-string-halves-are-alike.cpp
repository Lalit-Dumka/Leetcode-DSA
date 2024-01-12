class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels= {'a','e','i','o','u','A','E','I','O','U'};
        int c1=0,c2=0;
        for(int i =0; i< s.size(); i++){
            if(vowels.find(s[i])!=vowels.end()){
                if(i<s.size()/2) c1++;
                else c2++;
            }
        }
        
        if(c1==c2) return true;
        
        return false;
    }
};
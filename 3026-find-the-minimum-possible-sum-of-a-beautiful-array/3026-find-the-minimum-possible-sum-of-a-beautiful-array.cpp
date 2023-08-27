class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long sum =0;
        int count=1, i=1;
        unordered_set<int> s;
        while(count<=n){
            if(s.find(i) == s.end()){
                s.insert(target-i);
                sum+=i;
                count++;
            }
            i++;
        }
        return sum;
    }
};
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> sol(n+1, 0);
        for(int i=0; i<n+1; i++){
            int count =0;
            int num=i;
            while(num!=0){
                int rem=num%2;
                if(rem) count++;
                num=num/2;
            }
            sol[i]=count;
        }
        return sol;
    }
};
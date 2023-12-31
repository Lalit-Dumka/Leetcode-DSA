class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long nn = n;
        if(nn<0) nn *= -1;

        while(nn){
            if(nn%2==0){
                x=x*x;
                nn/=2;
            }
            else{
                ans=ans*x;
                nn-=1;
            }
        }
        if (n < 0) return 1.0/ans;
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        int profit=0;
        for(int i=0; i<prices.size(); i++){
            if(minPrice>prices[i]){
                minPrice = prices[i];
            }
            profit = prices[i]-minPrice;
            if(maxPro<profit){
                maxPro = profit;
            }
        }
    return maxPro;
    }
};
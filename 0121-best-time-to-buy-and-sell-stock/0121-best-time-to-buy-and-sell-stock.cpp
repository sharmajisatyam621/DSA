class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minSoFar=prices[0];
        for(auto x:prices){
            minSoFar=min(minSoFar,x);
            profit=max(profit,x-minSoFar);
        }
        return profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int buy = INT_MAX;
        for (int sell : prices) {
            buy = min(sell,buy);
            maxprofit = max(maxprofit, sell - buy); 
        }

        return maxprofit;
    }
};

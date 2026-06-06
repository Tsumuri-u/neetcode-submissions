class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int left = 0;
        int right = 1;
        while (right < prices.size()) {
            profit = max(profit, prices[right] - prices[left]);
            if (prices[right] < prices[left]) {
                left = right;
                right = left + 1;
            } else {
                right++;
            }  
        }
        

        return profit;
    }
};

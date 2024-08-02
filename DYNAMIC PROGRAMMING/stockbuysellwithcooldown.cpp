class Solution {
public:
    int maxP(vector<int>& prices, int day, int n, int buy, vector<vector<int>>& t) {
        if (day >= n)
            return 0;
        
        int profit = 0;
        if (t[day][buy] != -1){
            return t[day][buy];
        }
        if(buy) { // buy
            int consider = maxP(prices, day + 1, n, false, t) - prices[day];
            int not_consider = maxP(prices, day + 1, n, true, t);
            profit = max({profit, consider, not_consider});
        } else { // sell
            int consider = maxP(prices, day + 2, n, true, t) + prices[day];
            int not_consider = maxP(prices, day + 1, n, false, t);
            profit = max({profit, consider, not_consider}); 
        }
        
        return t[day][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> t(n, vector<int>(2, -1));
        return maxP(prices, 0, n, true, t);
    }
};

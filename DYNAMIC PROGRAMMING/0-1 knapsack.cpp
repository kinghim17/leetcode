#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int knapSackHelper(int W, vector<int>& wt, vector<int>& val, int i, vector<vector<int>>& dp) {
        // Base case: if no items left or capacity is 0
        if (i == wt.size() || W == 0) 
            return 0; 

        // Check if the solution already exists in dp table
        if (dp[i][W] != -1)
            return dp[i][W];
        
        // If the weight of the item is more than the current capacity, skip it
        if (wt[i] > W) 
            return dp[i][W] = knapSackHelper(W, wt, val, i + 1, dp); 

        // Include the current item or skip it
        return dp[i][W] = max(val[i] + knapSackHelper(W - wt[i], wt, val, i + 1, dp),
                              knapSackHelper(W, wt, val, i + 1, dp)); 
    }

    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return knapSackHelper(W, wt, val, 0, dp);
    }
};


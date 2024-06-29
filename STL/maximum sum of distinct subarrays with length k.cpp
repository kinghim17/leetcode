class Solution {
public:
    long long maximumSubarraySum(vector<int>& a, int k) {
        long long sum = 0, maxSum = 0;
        int i = 0;
        unordered_set<int> s;

        for (int j = 0; j < a.size(); j++) {
            // Shrink window if necessary
            while (s.count(a[j]) || s.size() == k) {
                sum -= a[i];
                s.erase(a[i]);
                i++;
            }

            // Expand window
            sum += a[j];
            s.insert(a[j]);

            // Update maxSum if we have a valid window
            if (s.size() == k) 
                maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

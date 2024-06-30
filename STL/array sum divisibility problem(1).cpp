#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int> arr, int k) {
        int n = arr.size();

        // If the number of elements is odd, we can't pair all of them.
        if (n % 2 == 1) {
            return false;
        }
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            // Compute the remainder of the current element.
            int remain = arr[i] % k;
            if (remain < 0) {
                remain += k; // Make sure the remainder is positive.
            }
            // The other part of the pair should sum with remain to be a multiple of k.
            int other_remain = (k - remain) % k;

            // Check if the counterpart of this remainder exists in the set.
            if (st.find(other_remain) != st.end()) {
                st.erase(other_remain); // If found, remove the counterpart.
            } else {
                st.insert(remain); // Otherwise, add the current remainder.
            }
        }

        // If the set is empty, it means all pairs are correctly formed.
        return st.empty();
    }
};

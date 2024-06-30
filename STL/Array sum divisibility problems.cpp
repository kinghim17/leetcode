//unordered multiset use 
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();

        // If the number of elements is odd, we can't pair all of them.
        if (n % 2 == 1) {
            return false;
        }

        unordered_multiset<int> st;

        for (int i = 0; i < n; i++) {
            // Compute the remainder of the current element.
            int r1 = arr[i] % k;
            if (r1 < 0) {
                r1 += k; // Ensure remainder is non-negative
            }

            // The other part of the pair should sum with r1 to be a multiple of k.
            int r2 = (k - r1) % k;

            // Check if the counterpart of this remainder exists in the multiset.
            auto it = st.find(r2);
            if (it != st.end()) {
                st.erase(it); // If found, remove one counterpart.
            } else {
                st.insert(r1); // Otherwise, add the current remainder.
            }
        }

        // If the multiset is empty, it means all pairs are correctly formed.
        return st.empty();
    }
};

//map use

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        
        // If the number of elements is odd, we can't pair all of them.
        if (n % 2 == 1) {
            return false;
        }
        
        unordered_map<int, int> count;
        
        for (int num : arr) {
            int remainder = num % k;
            if (remainder < 0) {
                remainder += k; // Adjust negative remainder
            }
            count[remainder]++;
        }
        
        for (auto& pair : count) {
            int remainder = pair.first;
            int freq = pair.second;
            
            if (remainder == 0 || 2 * remainder == k) {
                // Check if the count of this remainder is even
                if (freq % 2 != 0) {
                    return false;
                }
            } else {
                // Check if counterpart remainder exists and matches in count
                int counterpart = k - remainder;
                if (count[counterpart] != freq) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

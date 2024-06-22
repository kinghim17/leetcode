//first solution
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Ensure k is within bounds
        
        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());
        
        // Step 2: Reverse the first 'k' elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Step 3: Reverse the remaining 'n - k' elements
        reverse(nums.begin() + k, nums.end());
        
        // Print the rotated array
        for (int i = 0; i < n; i++) {
            cout << nums[i];
        } 
    }
};
//second Solution
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Ensure k is within bounds
        vector<int>v;
    
        for (int i = n - k; i < n; i++) {
            v.push_back(nums[i]);
        }//store the last k elements
        
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }//shift
        
        for (int i = 0; i < k; i++) {
            nums[i] = v[i];
        }
        
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        } 
    }
};


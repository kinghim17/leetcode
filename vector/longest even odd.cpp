class Solution {
public:

     int longestAlternatingSubarray(vector<int>& nums, int threshold) 
     {
        int l = 0;
        int r = nums.size()-1;
        int count = 0;
        int maxCount = INT_MIN;

        // Finding the first valid number which is even and lower than threshold
        while(l <= r && (nums[l]%2 != 0 || nums[l] > threshold))
            l++;

        // Handling corner case if all the elements are greater than threshold or odd
        if(l>r)
            return 0;

        for(int i = l; i < r; i++)
        {
            // Making sure the new subarray starts from even number
            if(count == 0 && nums[i]%2 != 0)
                continue;

            if(nums[i] <= threshold)
            {
                // Increasing the count
                count++;

                // Resetting count as we found the end of current subarray
                if(nums[i]%2 == nums[i+1]%2)
                {
                    maxCount = max(count, maxCount);
                    count = 0;
                }
            }
            else // Resetting count as we found the end of current subarray
            {
                maxCount = max(count, maxCount);
                count = 0;
            }
        }
        // Handling corner case of the last element
        if(nums[r] <= threshold)
        {
            count++;
        }
        return max(maxCount,count);
    }
};
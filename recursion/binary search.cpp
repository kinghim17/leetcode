#include <iostream>
#include <vector>

using namespace std;

// Function to perform binary search recursively
int binarySearch(const vector<int>& nums, int l, int r, int target) {
    if (l <= r) {
        int mid = l + (r - l) / 2; // Calculate the middle index to avoid overflow

        // If the element is present at the middle itself
        if (nums[mid] == target)
            return mid;

        // If the element is smaller than mid, then it can only be in the left subarray
        if (nums[mid] > target)
            return binarySearch(nums, l, mid - 1, target);

        // Else the element can only be in the right subarray
        return binarySearch(nums, mid + 1, r, target);
    }

    // Element is not present in the array
    return -1;
}

int main() {
    vector<int> nums = {2, 3, 4, 10, 40};
    int target = 10;
    int n = nums.size();

    int result = binarySearch(nums, 0, n - 1, target);
    if (result != -1)
        cout << "Element is present at index " << result << endl;
    else
        cout << "Element is not present in the array" << endl;

    return 0;
}

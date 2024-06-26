class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;               // Pointer to the start of the string
        int end = s.size() - 1;      // Pointer to the end of the string

        while (start < end) {       // Loop until the start pointer passes the end pointer
            // Skip non-alphanumeric characters from the start
            if (!isalnum(s[start])) {
                start++;
                continue;
            }

            // Skip non-alphanumeric characters from the end
            if (!isalnum(s[end])) {
                end--;
                continue;
            }

            // Compare characters, ignoring case
            if (tolower(s[start]) != tolower(s[end])) {
                return false;       // If characters don't match, it's not a palindrome
            } else {
                // Move both pointers inward
                start++;
                end--;
            }
        }

        return true;                // If all characters match, it's a palindrome
    }
};

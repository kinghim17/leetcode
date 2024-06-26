class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        vector<int> result;
        if (n < m) return result; 
        
        unordered_map<char, int> charCountP; // Map to count characters in p
        unordered_map<char, int> charCountS; // Map to count characters in current window of s
        
        // Count frequencies of characters in p
        for (char c : p) {
            charCountP[c]++;
        }
        
        // Initial window setup
        for (int i = 0; i < m; i++) {
            charCountS[s[i]]++;
        }
        
        // Sliding window approach
        for (int i = 0; i <= n - m; i++) {
            // Check if current window of s matches anagram of p
            if (charCountS == charCountP) {
                result.push_back(i);
            }
            
            // Slide the window by removing the leftmost character and adding the next character
            charCountS[s[i]]--;
            if (i + m < n) {
                charCountS[s[i + m]]++;
            }
            
            // Remove characters with count 0 to keep the map clean
            if (charCountS[s[i]] == 0) {
                charCountS.erase(s[i]);
            }
        }
        
        return result;
    }
};

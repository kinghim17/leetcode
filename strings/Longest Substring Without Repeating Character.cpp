//stvector
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int i=0;
    int res=0;
    int maxend;
    int n=s.length();
    vector<int>v(256,-1);
    for(int j=0;j<n;j++){
        i=max(i,v[s[j]]+1);
        maxend=j-i+1;
        res=max(res,maxend);
        v[s[j]]=j;
    }
    return res;
    }
};
//sets
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        unordered_set<char> charSet;

        for (int right = 0; right < s.length(); right++) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;        
    }
};
//maps
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        unordered_map<char, int> charIndexMap;

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            
            // If the character is already in the map and its index is not before 'left'
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= left) {
                // Move the left pointer to the right of the last occurrence of currentChar
                left = charIndexMap[currentChar] + 1;
            }

            // Update the last index of the current character
            charIndexMap[currentChar] = right;

            // Update the maximum length of the substring
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;        
    }
};
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
//maps
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
//vector based solution
class Solution {
public:
    int firstUniqChar(string s){
        vector<int> mp(26, 0);
        for(auto i : s) {
            mp[i-'a']++;
        }
        for(int i  = 0;i < s.length();i++){
            if(mp[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
//map use
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (charCount[s[i]] == 1) {
                return i; 
            }
        }

        // If no unique character is found, return -1
        return -1;
    }
};
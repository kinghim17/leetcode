
//compartor function
class Solution {
public:
 static bool compare(pair<int, char>&a,pair<int, char>&b){
    return a.first>b.first;
}
    string frequencySort(string s) {
        unordered_map<char, int> m;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
        }

        vector<pair<int, char>> freqVec;
        for (auto& entry : m) {
            freqVec.push_back({entry.second, entry.first});
        }

        // Step 3: Sort the vector by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), compare);

        // Step 4: Build the resulting string
        string result;
        for (auto& entry : freqVec) {
            result += string(entry.first, entry.second);
        }

        return result;
    }
};
//stl method
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
        }

        vector<pair<int, char>> freqVec;
        for (auto& entry : m) {
            freqVec.push_back({entry.second, entry.first});
        }

        // Step 3: Sort the vector by frequency in descending order
        sort(freqVec.begin(), freqVec.end(),[](const pair<int,char>a,const pair<int,char>b){
            return a.first>b.first;
        });

        // Step 4: Build the resulting string
        string result;
        for (auto& entry : freqVec) {
            result += string(entry.first, entry.second);
        }

        return result;
    }
};
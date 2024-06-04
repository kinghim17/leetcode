class Solution {
public:
 int numIdenticalPairs(vector<int>& nums) {
 int result = 0;
 unordered_map<int, int> mp;

 for(int &num : nums) {
 mp[num]++;
 }

 for(auto &it : mp) {

 int count = it.second;
 result += (count * (count-1))/2;

 }

 return result;
 }
};
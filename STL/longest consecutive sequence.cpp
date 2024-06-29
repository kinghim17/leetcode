class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int n=nums.size();
        int count,maxi=1;
        unordered_set<int>s(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(s.find(nums[i]-1)==s.end()){
                count=1;
                while(s.find(nums[i]+count)!=s.end()){
                    count++;
                    maxi=max(maxi,count);
                }
            }
        }
        return maxi;
    }
};

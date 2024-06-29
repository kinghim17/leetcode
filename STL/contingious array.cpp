class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        //all the zeros are converted to -1
        for(int i=0;i<n;i++){
            if(nums[i]==0){
               nums[i]=-1;
            }
        }
        //now it becomes largest subarray sum question
        //here we we use the prefix sum concept
        int res=0,sum=0,resi;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            if(sum==0){
                resi=i+1;
                res=max(res,resi);
                continue;
            }
            if(m.find(sum)!=m.end()){
                resi=i-m[sum];
                res=max(res,resi);
            }else{
                m.insert({sum,i});
            }
        }
    return res;
    }
};

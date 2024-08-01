class Solution {
public:
    int solve(int n,vector<int>&v){
        if(n<=1)
        return n;
        if(v[n]!=-1)
        return v[n];

        return v[n]=solve(n-1,v)+solve(n-2,v);
    }

    int fib(int n) {
       if(n<=1){
        return n;
       } 
       vector<int>v(n+1,-1);
       return solve(n,v);
    }
};

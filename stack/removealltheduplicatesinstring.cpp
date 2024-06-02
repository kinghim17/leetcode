class Solution {
public:
 string removeDuplicates(string s) {
 stack<int>s1;
 int n=s.length();
 for(int i=n-1;i>=0;i--){
 bool flag=true;
 while(!s1.empty() && s[i]==s1.top()){
 s1.pop();
 flag=false;
 }
 if(flag==true){//you are stopping the copy too
 s1.push(s[i]);
 }
 }
 //conversion
 string result = "";
 while(!s1.empty()) {
 result += s1.top();
 s1.pop();
 }
 return result;
 }
};
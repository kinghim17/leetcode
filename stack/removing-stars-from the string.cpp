string removeStars(string s) {
 string result = "";

 for(char &ch : s) {

 if(ch == '*') {
 result.pop_back();
 } else {
 result.push_back(ch);
 }

 }

 return result;
 }
};
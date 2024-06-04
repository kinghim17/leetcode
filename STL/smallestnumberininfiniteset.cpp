//Approach1:
class SmallestInfiniteSet {
public:
 vector<bool> nums;
 int i;

 SmallestInfiniteSet() {
 nums = vector<bool>(1001, true);
 i = 1;
 }

 int popSmallest() {

 int result = i;

 nums[i] = false;
 for(int j = i + 1; j < 1001; j++) {
 if(nums[j] == true) {
 i = j;
 break;
 }
 }

 return result;

 }

 void addBack(int num) {
 nums[num] = true;
 if(num < i) {
 i = num;
 }
 }
};
//Approach 2:
class SmallestInfiniteSet {
public:
 set<int> st;

 int currSmallest;

 SmallestInfiniteSet() {
 currSmallest = 1;
 }

 int popSmallest() {
 int result;

 if(!st.empty()) {
 result = *st.begin();
 st.erase(st.begin()); //or, st.erase(result)
also works
 } else {
 result = currSmallest;
 currSmallest += 1;
 }

 return result;
 }

 void addBack(int num) {
 if(num >= currSmallest || st.find(num) !=
st.end())
 return;

 st.insert(num);
 }
}
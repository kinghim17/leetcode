class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftCount = 0;
        
        while(left != right) {
            left >>= 1;
            right >>= 1;
            shiftCount++;
        }
        
        return left << shiftCount;
    }
};
//better approach
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right > left) {
            right = right & (right-1);
        }
        
        return right;
    }
};
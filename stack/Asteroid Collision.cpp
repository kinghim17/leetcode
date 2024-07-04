class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; // Stack of integer...
        for(auto &ast : asteroids){
            bool destroy = false; // Initially, NO COLLISION...
            if(ast > 0){
                st.push(ast); // +ve k case mein...
            }
            else{ // -ve k case jb collision nhi hua h...
                if(st.empty() || st.top() < 0){
                    st.push(ast);
                }
                else{ // COLLISION...
                    while(!st.empty() && st.top() > 0){
                        if(abs(ast) == st.top()){
                            destroy = true;
                            st.pop();
                            break;
                        }
                        else if(abs(ast) > st.top()){
                            st.pop();
                        }
                        else{
                            destroy = true;
                            break;
                        }
                    }
                    if(!destroy){
                        st.push(ast);
                    }
                }
            }
        }
        vector<int> ans(st.size());
        // REVERSE...
        for(int i = st.size() - 1; i >= 0; --i){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
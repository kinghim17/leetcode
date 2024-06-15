//aproach-1
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v; 
        vector<int> v1; 
        
        if (root == NULL) {
            return v;
        }

        queue<TreeNode*> q; 
        q.push(root); 
        q.push(NULL);

        while (!q.empty()) {
            TreeNode* curr = q.front(); 
            q.pop();

            if (curr == NULL) { 
                if (!v1.empty()) { 
                    v.push_back(v1); 
                    v1.clear();
                }
                if (!q.empty()){
                    q.push(NULL);
                }
            } else {
                v1.push_back(curr->val); 
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right); 
                }
            }
        }

        return v; // Return the result of level order traversal
    }
};
//approach-2
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if (root == NULL) {
            return v;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> v1;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr != NULL) {
                    v1.push_back(curr->val);

                    if (curr->left != NULL) {
                        q.push(curr->left);
                    }

                    if (curr->right != NULL) {
                        q.push(curr->right);
                    }
                }
            }

            v.push_back(v1);
        }

        return v;
    }
};


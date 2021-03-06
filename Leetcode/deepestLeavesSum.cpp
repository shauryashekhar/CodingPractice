/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int result = 0;
        if(!root) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        map<int, vector<int>> m;
        int l = 0;
        vector<int> level;
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL) {
                m[l] = level;
                l++;
                level.clear();
                if(!q.empty()) {
                    q.push(NULL);
                }
            } else {
                level.push_back(temp->val);
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
        }
        for(auto itr = m.rbegin(); itr != m.rend(); itr++) {
            vector<int> tv = itr->second;
            for(int x : tv) {
                result = result + x;
            }
            break;
        }
        return result;
    }
};
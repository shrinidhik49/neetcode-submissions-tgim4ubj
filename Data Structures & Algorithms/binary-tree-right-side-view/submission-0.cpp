/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightside;
        if(root == NULL) return rightside;

        queue<TreeNode*> q;
        vector<int> level;
        q.push(root);
        q.push(NULL);
        rightside.push_back(root->val);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {
                level.clear();

                if(q.empty()) break;
                else {
                rightside.push_back(q.back()->val);
                q.push(NULL);   
                }
            }
            else {
                level.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

        }

        return rightside;
    }
};

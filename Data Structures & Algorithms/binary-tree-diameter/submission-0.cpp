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

int height (TreeNode* root) {
    if(root == NULL) {
        return 0;
    }

    int H1 = height(root->left);
    int H2 = height(root->right);

    return (1+max(H1,H2));
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int D1 = height(root->left) + height (root->right);
        int D2 = diameterOfBinaryTree(root->left);
        int D3 = diameterOfBinaryTree(root->right);

        return max(D1,max(D2,D3));
    }
};

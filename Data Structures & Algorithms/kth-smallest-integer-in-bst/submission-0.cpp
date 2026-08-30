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

int kthsmallestcur (TreeNode* root, int &count, int k) {
        if (root == NULL) {
            return -1;
        }
        int left = kthsmallestcur(root->left,count, k);

        if (left != -1) {
            return left;
        }

        count++;
        
        if (count == k) {
            return root->val;
        }

        int right = kthsmallestcur(root->right, count, k);
        return right;

}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return kthsmallestcur(root, cnt, k);
    }
};

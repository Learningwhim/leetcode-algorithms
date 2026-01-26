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
    int maxval = INT_MIN;
    int path(TreeNode * root){
        if(root == NULL) return 0;
        int lh = path(root->left);
        int rh = path(root->right);
        maxval = max({maxval, lh+rh+root->val, lh+root->val, rh+root->val});
        maxval = max(root->val, maxval);
        return max(max(lh, rh)+ root->val, root->val);
    }
    int maxPathSum(TreeNode* root) {
        path(root);
        return maxval;
    }
};
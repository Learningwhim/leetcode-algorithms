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
    int maxd = 0;
    int diameter(TreeNode* root){
        if(root == NULL) return 0;
        int lh = diameter(root->left);
        int rh = diameter(root->right);
        maxd = max(lh+rh+1, maxd);
        return max(lh, rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return maxd-1;
    }
};
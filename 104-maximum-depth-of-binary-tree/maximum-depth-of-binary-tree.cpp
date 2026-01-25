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
    int maxd = 1;
    void md(int level, TreeNode *root){
        if(root == nullptr) return;
        maxd = max(maxd, level);
        md(level+1, root->left);
        md(level+1, root->right);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        md(maxd, root);
        return maxd;
    }
};
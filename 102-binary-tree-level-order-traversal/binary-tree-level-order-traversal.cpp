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
    int maxl = -1;
    void traverse(vector<vector<int>> &ans, int level, TreeNode* root){
        if(root == NULL) return;
        maxl = max(maxl, level);
        ans[level].push_back(root->val);
        if(root->left != nullptr) traverse(ans, level+1, root->left);
        if(root->right != nullptr) traverse(ans, level+1, root->right);

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans(2000);
        int level = 0;
        traverse(ans, level, root);
        ans.resize(maxl+1);
        return ans;
    }
};
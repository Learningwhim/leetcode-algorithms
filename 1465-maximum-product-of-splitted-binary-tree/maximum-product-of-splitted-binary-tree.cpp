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
    vector<int> sums;
    int sum(TreeNode* node){
        if(node == NULL) return 0;
        int left = (node->left == NULL ? 0 : sum(node->left));
        int right = (node->right == NULL ? 0 : sum(node->right));
        sums.push_back(node->val+left+right);
        return node->val+left+right;
    }
    int maxProduct(TreeNode* root) {
        long long product = 1;
        int S = sum(root);
        for(long long s : sums){
            product = max(product, s*(S-s));
        }
        long long m = 1e9+7;
        return product%m;
    }
};
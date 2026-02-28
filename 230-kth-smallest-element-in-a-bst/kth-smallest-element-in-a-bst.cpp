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
    int counter = 0, kth;
    int Traverse(TreeNode*  root, int k){
        if(root == NULL) return counter;
        if(root->left) Traverse(root->left, k);
        counter++;
        if(k == counter) kth = root->val;
        if(root->right) Traverse(root->right, k);
        return counter;
    }
    int kthSmallest(TreeNode* root, int k) {
        Traverse(root, k);
        return kth;
    }
};
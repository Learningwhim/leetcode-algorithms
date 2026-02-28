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
    TreeNode* lastright(TreeNode* root){
        if(root->right == NULL) return root;
        return lastright(root->right);
    }
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;
        TreeNode*  rightChild = root->right;
        TreeNode* lastR = lastright(root->left);
        lastR->right = rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val == key){
            return helper(root);
        }
        if(root->val == key) return helper(root);
        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else root->right = deleteNode(root->right, key);
        return root;
    }
};
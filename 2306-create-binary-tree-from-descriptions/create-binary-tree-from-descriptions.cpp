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
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root = nullptr;
        bool flag = true;
        unordered_set<int> childs;
        unordered_map<int, TreeNode*> mp;
        for(auto d : descriptions){
            int par = d[0];
            int child = d[1];
            TreeNode* parNode = mp[par];
            if(parNode == NULL) {
                parNode = new TreeNode(par);
                mp[par] = parNode;
            }
            TreeNode* childNode = mp[child];
            if(childNode == NULL) {
                childNode = new TreeNode(child);
            }
            if(d[2]){
                parNode->left = childNode;
            }else{
                parNode->right = childNode;
            }
            mp[child] = childNode;
            childs.insert(child);
        }
        
        for(auto &[val, node] : mp){
            if(childs.find(val) == childs.end()) return node;
        }
        
        return root;
    }
};
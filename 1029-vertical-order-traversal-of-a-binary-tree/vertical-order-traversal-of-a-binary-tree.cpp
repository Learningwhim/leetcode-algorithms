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
    map<int, map<int, multiset<int>>> mp;
    void dfs(TreeNode* root, int col, int row){
        if(root == NULL) return;
        mp[col][row].insert(root->val);
        if(root->left) dfs(root->left, col-1, row+1);
        if(root->right) dfs(root->right, col+1, row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        dfs(root, 0, 0);
        for(auto each : mp){
            vector<int> colvals;
            for(auto &rowp : each.second){
                for(auto val : rowp.second){
                    colvals.push_back(val);
                }
            }
            ans.push_back(colvals);
        }
        return ans;
    }
};
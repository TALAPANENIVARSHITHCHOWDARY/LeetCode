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
bool dfs(TreeNode* root,int tar){
    if(!root) return false;
    if(!root->left&&!root->right&&tar-root->val==0){
        return true;
    }
 
    return   (dfs(root->left,tar-root->val)||dfs(root->right,tar-root->val));
}
    bool hasPathSum(TreeNode* root, int targetSum) {
       return dfs(root,targetSum);
      
    }
};
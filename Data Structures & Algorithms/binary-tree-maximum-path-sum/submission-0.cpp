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
    int solve(TreeNode*root,int &res){
        if(!root)return 0;
        int lsum=solve(root->left,res);
        int rsum=solve(root->right,res);
        res=max({res,max(lsum,rsum)+root->val,root->val+lsum+rsum,root->val});
        return max(max(lsum,rsum)+root->val,root->val);
    }
    int maxPathSum(TreeNode* root) {
        int res=root->val;
        solve(root,res);
        return res;
    }
};
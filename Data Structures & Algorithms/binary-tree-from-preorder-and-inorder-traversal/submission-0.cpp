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
    TreeNode*solve(vector<int>& preorder, vector<int>& inorder,int &preIdx,int inStart,int inEnd){
        if(inStart>inEnd)return nullptr;
        TreeNode*root=new TreeNode(preorder[preIdx++]);
        int idx=inStart;
        for(int i=inStart;i<=inEnd;i++){
            if(inorder[i]==root->val){
                idx=i;
                break;
            }
        }
        root->left=solve(preorder,inorder,preIdx,inStart,idx-1);
        root->right=solve(preorder,inorder,preIdx,idx+1,inEnd);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return solve(preorder,inorder,idx,0,inorder.size()-1);
    }
};
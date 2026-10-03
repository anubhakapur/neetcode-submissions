/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void preorderSerialize(TreeNode*root,vector<string>&nodes){
        if(!root){
            nodes.push_back("N");
            return;
        }
        nodes.push_back(to_string(root->val));
        preorderSerialize(root->left,nodes);
        preorderSerialize(root->right,nodes);
    }
    string convertToString(vector<string>&nodes){
        string res="";
        int n=nodes.size();
        for(int i=0;i<n-1;i++){
            res+=nodes[i];
            res+=',';
        }
        res+=nodes[n-1];
        return res;
    }
    vector<string> convertToVector(string &data){
        stringstream ss(data);
        string token;
        vector<string>nodes;
        while(getline(ss,token,',')){
            nodes.push_back(token);
        }
        return nodes;
    }
    TreeNode* preorderDeserialize(vector<string>&nodes,int&idx){
        if(nodes[idx]=="N"){
            idx++;
            return nullptr;
        }
        TreeNode*node=new TreeNode(stoi(nodes[idx++]));
        node->left=preorderDeserialize(nodes,idx);
        node->right=preorderDeserialize(nodes,idx);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string>nodes;
        preorderSerialize(root,nodes);
        string res=convertToString(nodes);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>nodes=convertToVector(data);
        int idx=0;
        TreeNode*root=preorderDeserialize(nodes,idx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
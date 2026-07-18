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

class Codec {
public:
    
     void preorder(TreeNode* root , string &res){
           if(root == NULL){
            res += "null," ;
            return ;
           }
           res += to_string(root->val) + "," ;
           preorder(root->left , res);
           preorder(root->right , res);
     }

     TreeNode* build(vector<string> &nodes , int &i){
            if(nodes[i] == "null"){
                i++ ;
                return NULL;
            }
        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++ ;
        root->left = build(nodes,i);
        root->right = build(nodes,i);
        return root ;
     }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        
        preorder(root , res);
        return res;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;
        for(char ch : data){
            if(ch == ','){
                nodes.push_back(temp);
                temp = "";
            }
            else{
                temp += ch; 
            }
        }

        int i=0;

        return build(nodes , i);
    }
};

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
    
 // Function to search root value in inorder array
int search( vector<int>& inorder , int val , int l , int r){
    for(int i = l ; i<= r ;i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}
// Recursive function to build tree
TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int & preIdx , int l , int r){
    // Base case
    if(l > r){
        return NULL ;
    }
    
     // Create root node from preorder
    TreeNode* root = new TreeNode(preorder[preIdx]);
    preIdx++ ; 
    // Find root index in inorder
    int idx = search(inorder,root->val,l,r);
    // Build left and right subtrees
    root->left = helper(preorder,inorder,preIdx,l,idx-1);
     root->right = helper(preorder,inorder,preIdx,idx+1,r);

     return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder,inorder,preIdx,0,inorder.size()-1);
    }

};

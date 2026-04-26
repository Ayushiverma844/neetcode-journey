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
    int diameter = 0; // store maximum diameter

    // Function to calculate height
    int height(TreeNode* root){
    if( root == NULL){
        return 0;
    }
    // left subtree height
    int l = height(root->left);
    // right subtree height
    int r = height(root->right);
    // update diameter
    diameter = max(diameter,l+r);
    
    // return height of tree
    return max(l,r)+1;
  }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root); // call height function
        return diameter;
    }
};

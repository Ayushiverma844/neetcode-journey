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
   
   // Function to perform inorder traversal
    void inorder(TreeNode* root , vector<int>& ans){
        
        // Base case: if node is NULL, return
        if(root == NULL){
            return ;
        }
        // Visit left subtree
        inorder(root->left , ans);
        // Store current node value
        ans.push_back(root->val);
        // Visit right subtree
        inorder(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {

        // Vector to store inorder traversal
        vector<int> ans;
        // Inorder traversal of a BST gives elements
        // in sorted (ascending) order
        inorder(root , ans);
        
        // Return the k-th smallest element
        // (0-based indexing, so use k-1)
        return ans[k-1];
        
    }
};

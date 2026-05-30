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
    bool check(TreeNode* root , int minVal , int maxVal){
        //base case
        if(root == NULL){
            return true;
        }

        // if current node is not in range
        if(root->val <= minVal || root->val >= maxVal){
            return false ;
        }
         // Left subtree and right subtree check
        return check(root->left, minVal, root->val) &&
               check(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
       
        return check(root,INT_MIN ,INT_MAX);
    }
};

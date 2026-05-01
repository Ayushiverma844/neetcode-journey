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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftH = height(root->left);
        if(leftH == -1){
            //if left child not exist
            return -1;
        }
        int rightH = height(root->right);
        if(rightH == -1){
            //if right child not exist
            return -1;
        }
        if(abs(leftH-rightH) > 1){
            // not balanced return false;
        return -1;
     }

    //for calculating height
    return max(leftH,rightH)+1 ;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1 ? true : false;
    }
};

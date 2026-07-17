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
    void count(TreeNode* root ,TreeNode* prev , int& cnt){
        if(root == NULL){
            return;
        }
        if(root->val >= prev->val ){
            cnt++ ;
            prev = root;
        }
        count(root->left , prev , cnt);
        count(root->right , prev , cnt);
    }
    int goodNodes(TreeNode* root) {
        int cnt  =0;
        count(root ,root, cnt);
        return cnt;
    }
};

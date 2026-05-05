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
    bool check(TreeNode* p, TreeNode* q){
        // Case 1: both NULL
        if(p== NULL && q==NULL){
            return true;
        }
        // Case 2: one NULL
        if(p == NULL || q == NULL){
            return false;
        }
       
        // Case 3: value check + recursion
        if(p->val == q->val){
            bool left = check(p->left , q->left);
            bool right = check(p->right , q->right);
         return left && right;
        }
        return false;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};

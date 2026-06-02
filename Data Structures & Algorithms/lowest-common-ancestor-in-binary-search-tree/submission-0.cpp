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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }   
        //found the first node (p or  q) exist in tree
        if(root->val == p->val || root->val == q->val){
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left , p , q);
        TreeNode* rightLCA =  lowestCommonAncestor(root->right , p ,q);

        // when a node contain both left and right lca that mean it is the node which is lca
        if(leftLCA && rightLCA ){
            return root;
        }
        //when right lca is null and leftlca exist then return only leftlca
        else if(leftLCA != NULL){
            return leftLCA;
        }

        //when rightlca is null or boht lest and rightlca is null then return rightlca
        else{
            return rightLCA;
        }
    }
};

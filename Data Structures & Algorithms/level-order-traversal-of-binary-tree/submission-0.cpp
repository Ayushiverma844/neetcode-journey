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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        
         // If tree is empty, return empty answer
        if(root==NULL){
            return ans;
        }
        
        //add root node into the queue
        q.push(root);
        
        while(!q.empty()){
            // Store nodes of current level
           vector<int> temp;
           // Number of nodes present in current level
           int size = q.size();
           // Process all nodes of current level
           for(int i=0; i<size ;i++){
               TreeNode* curr = q.front();
               q.pop();
               // Store current node value
               temp.push_back(curr->val);
               
                // Add left child to queue if it exists
                if(curr->left != NULL ){
                  q.push(curr->left);
                }
                 // Add right child to queue if it exists
                if(curr->right != NULL){
                  q.push(curr->right);
                }
           }

          // Store one complete level in answer
           ans.push_back(temp);
        }
        return ans;
    }
};

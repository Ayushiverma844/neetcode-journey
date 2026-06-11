class Solution {
public:

    void helper(TreeNode* root, int level, vector<int>& ans)
    {
        if(root == NULL)
        {
            return;
        }

         // If we are visiting this level for the first time
        if(level == ans.size())
        {
            ans.push_back(root->val);
        }

        // first visit right subtree
        helper(root->right, level + 1, ans);

        // then left subtree
        helper(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        helper(root, 0, ans);

        return ans;
    }
};
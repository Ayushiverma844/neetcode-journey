class Solution {
public:
    void getAll(int open, int close, int n,
                vector<string>& ans, string &s) {

        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            s.push_back('(');          // Choose
            getAll(open + 1, close, n, ans, s);
            s.pop_back();              // Undo
        }

        if (close < open) {
            s.push_back(')');
            getAll(open, close + 1, n, ans, s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        getAll(0, 0, n, ans, s);
        return ans;
    }
};
class Solution {
public:
    unordered_map<char,string> mp = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

    void solve(string digits , int i , string temp , vector<string>& ans){
         if( i == digits.length()){
            ans.push_back(temp);
            return ;
         }
         string letters = mp[digits[i]];

         for(char ch : letters){
            solve(digits , i+1 , temp+ch  , ans);
         }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return  ans;
        }
        solve(digits , 0 , "" , ans);
        return ans;
    }
};

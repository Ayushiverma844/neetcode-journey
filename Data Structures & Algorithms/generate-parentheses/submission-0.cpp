class Solution {
public:
        // recurrsion

    bool isValid(string& s){
        int open = 0;
        for( char c : s){
            if(c == '('){
               open++ ;    
            }
            else{
                open-- ;
            }
            if(open < 0){
                return false;
            }
        }
        return open == 0;
    } 

    void getAll(string s , vector<string>& ans , int n){
        if(s.length() == 2*n){
            if(isValid(s)){
                ans.push_back(s);
               
            }
             return;
        }

        getAll(s+'(' , ans , n);
        getAll(s+')' , ans , n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        getAll("",ans , n);
        return ans;
    }
};

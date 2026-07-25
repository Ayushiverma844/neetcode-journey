class Solution {
public:
    bool isPalindrome(string s){
        int i=0 , j = s.length()-1;

        while(i < j){
            if(s[i] != s[j]){
               return false;
            }
            i++ ;
             j-- ;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";
        int maxlen = 0 , curr = 0;
        int l = 0 , r=0;
        while(l < s.length()){
            string temp = s.substr(l,r-l+1);
            curr = r-l+1 ;
            if(isPalindrome(temp) && curr >= maxlen ){
                ans = temp;
                maxlen = curr;
            }
            r++ ;
            if(r >= s.length()){
              l++ ; 
              r = l;
            }
        }
    return ans;
    }
};

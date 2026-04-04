class Solution {
public:
    bool isPalindrome(string s) {
        int i=0 , j=s.length()-1;
        while(i< j){
            if(s[i] == ' ' || !isalnum(s[i]) ){
               // skip
               i++ ;
               continue;
            }
            if(s[j] == ' ' || !isalnum(s[j])){
                //skip
                j--;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

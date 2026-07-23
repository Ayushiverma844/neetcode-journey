class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1);
        dp[s.length()] = 1;

        for(int i = s.length()-1; i>=0; i--){
            // start with 0 -> example: 01 , 02 ...
            if(s[i] == '0'){
                dp[i] = 0;
            }
            else{
                dp[i] = dp[i+1];

                // two digit number
                if(i+1 < s.length() && (s[i] == '1' || s[i]=='2' && s[i+1] <'7' )){
                    // 10 to 26
                    dp[i] += dp[i+2];
                }
            }
        }
        return dp[0];
    }
};

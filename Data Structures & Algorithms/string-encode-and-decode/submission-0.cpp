class Solution {
public:

    string encode(vector<string>& strs) {
       string s = "";
       for(int i=0;i<strs.size();i++){
           // length + # + actual string
           s += to_string(strs[i].length()) + "#" + strs[i];
       }
       return s;
    }

    vector<string> decode(string s) {
       vector<string> ans;
       int i =0;

       while(i < s.length()){
        string len = "";
           // '#' tak length read karo
            while (s[i] != '#') {
                len += s[i];
                i++;
            }
            // string length integer me convert
            int stringLength = stoi(len);

            // '#' skip karo
            i++;

            string temp = "";
            // given length tak characters uthao
            for (int j = 0; j < stringLength; j++) {
                temp += s[i];
                i++;
            }

            ans.push_back(temp);
       }
       return ans;
    }
};

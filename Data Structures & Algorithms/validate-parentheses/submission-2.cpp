class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            // Step 1: Push opening brackets
            if(s[i]== '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                // Step 2: Check if stack is empty
                if(st.empty()) {
                    return false; // no matching opening bracket
                }

                // Step 3: Match closing brackets
                if(st.top() == '(' && s[i] == ')'){
                    st.pop();
                }
                else if (st.top() == '{' && s[i] == '}'){
                    st.pop();
                }
                else if (st.top() == '[' && s[i] == ']'){
                    st.pop();
                }
                else {
                    return false; // mismatch case
                }
            }
        }
        return st.empty() ;
    }
};

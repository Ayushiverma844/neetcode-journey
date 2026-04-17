class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<int> st;

        for(int j=0;j<n;j++){
            while(!st.empty() && temperatures[j] > temperatures[st.top()]) {
                int i = st.top();
                st.pop();
                ans[i] = j - i;
            }
            st.push(j);

        }
        return ans;
    }
};

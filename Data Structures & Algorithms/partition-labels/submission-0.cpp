class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char , int > lastIdx;
        
        for(int i=0;i<s.length() ; i++){
            lastIdx[s[i]] = i;
        }

        int size = 0 , end = 0;
        for(int i=0; i<s.length() ; i++){
            size++;
            end = max(end,lastIdx[s[i]]);

            if(i == end){
                ans.push_back(size);
                size =0;
            }
        }
        return ans;
    }
};

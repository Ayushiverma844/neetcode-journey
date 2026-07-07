class Solution {
public:
bool isPalindrome(string s){
    string s2 = s;
    reverse(s2.begin(),s2.end());
    return s2==s ;
}
void getAllParts(string s ,  vector<string> &part,  vector<vector<string>>& ans){
    if(s.size()==0){
        ans.push_back(part);
    }

    for(int i=0;i<s.size();i++){
        if(isPalindrome(s.substr(0,i+1))){
            part.push_back(s.substr(0,i+1));
            getAllParts(s.substr(i+1),part,ans);
            part.pop_back();
        }
    }
}

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        getAllParts(s,part,ans);
        return ans;
    }
};
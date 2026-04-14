class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans =0;
        int st =0;
        unordered_map<char,int> m;
       
       for(int i=0;i<s.length();i++){
         // If character already exists in map and its index is >= start,
         // it means the character is repeating in current substring,
         // so move start to try a new substring
           if(m.find(s[i]) != m.end() && m[s[i]] >= st){
              st = m[s[i]]+1;
           }
           
           // Store/update the current index of the character in the map
           m[s[i]] = i;
           ans = max(ans,i-st+1);

       }
       return ans;
    }
};

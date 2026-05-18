class Solution {
public:
    string minWindow(string s, string t) {
       string ans = "";
       unordered_map<char,int> freq;

       // store freq of t
       for(int i=0;i< t.length();i++){
            freq[t[i]]++ ;
       }

       int i=0 , j = 0 ;
       int count = t.length(); // total required characters
       int minLen = INT_MAX;

       while(j<s.length()){
        // Decrease frequency of current character
           freq[s[j]]-- ;
           if(freq[s[j]] >= 0)
            {
                count--;
            }
             // When valid window found
             while(count == 0){
                 // Update minimum window
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    ans = s.substr(i, minLen);
                }
                 // Remove left character from window
                freq[s[i]]++;

                // If required character removed
                if (freq[s[i]] > 0) {
                    count++;
                }

                // Move left pointer
                i++;
             }
             // Expand right pointer
            j++;
       }
    return ans;
    }
};

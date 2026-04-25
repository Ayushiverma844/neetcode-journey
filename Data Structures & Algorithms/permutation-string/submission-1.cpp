class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();

        // Corrected: sort should be applied on s1 only
        sort(s1.begin(), s1.end());

        int i = 0, j = n - 1;

        // Loop until window reaches end of s2
        while (i < s2.length() && j < s2.length()) {

            // Corrected: substr takes (start_index, length)
            string substr = s2.substr(i, n);

            // Corrected: spelling of begin and variable name
            sort(substr.begin(), substr.end());

            // Compare sorted strings
            if (s1 == substr) {
                return true;
            }

            // Move window forward
            i++;
            j++;
        }

        return false;
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        // Frequency map to count occurrences of characters in current window
        unordered_map<char, int> freq;

        int ans = 0;     // Stores the maximum length of valid substring
        int l = 0;       // Left pointer of sliding window
        int maxf = 0;    // Stores the maximum frequency of a single character in the window

        // Right pointer expands the window
        for (int r = 0; r < s.length(); r++) {
            freq[s[r]]++;  // Include current character in window

            // Update the maximum frequency of any character in the window
            maxf = max(maxf, freq[s[r]]);

            // If more than k replacements are needed, shrink the window
            while ((r - l + 1) - maxf > k) {
                freq[s[l]]--;  // Remove leftmost character from window
                l++;           // Move left pointer forward
            }

            // Update the answer with the current valid window size
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
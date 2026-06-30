class Solution {
public:
    string multiply(string num1, string num2) {

        // Base cases
        if (num1 == "0" || num2 == "0")
            return "0";

        if (num1 == "1")
            return num2;

        if (num2 == "1")
            return num1;

        // Reverse both strings
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> mul(num1.length() + num2.length(), 0);

        // Multiply digits
        for (int i = 0; i < num1.length(); i++) {

            for (int j = 0; j < num2.length(); j++) {

                int dig = (num1[i] - '0') * (num2[j] - '0');

                mul[i + j] += dig;

                // Carry
                mul[i + j + 1] += mul[i + j] / 10;

                // Store only one digit
                mul[i + j] %= 10;
            }
        }

        string ans = "";
        
        // Skip leading zeros 
        //example -> 12 * 13 = 156
        // but in vector we are storing -> 21 * 31 = 6510
        // for answer we have to skip leading zeros (jo last m zero h wahi leading zero honge kuki answer reverse m store h vector m) 
        int i = mul.size() - 1;

        while (i >= 0 && mul[i] == 0)
            i--;

        // Convert vector to string
        while (i >= 0) {
            ans += (mul[i] + '0');
            i--;
        }

        return ans;
    }
};
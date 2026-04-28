class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for(int i = digits.size()-1 ; i>= 0;i--){
            if(digits[i] < 9){
                digits[i]++ ; //plus 1
                return digits;
            }
            
         digits[i] = 0;       // carry
        }

        // if all digits were 9

        digits.insert(digits.begin(), 1);

        return digits;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        // sum without addition operator
        // use xor and and 
        
        while(b != 0){ // Run the loop until there is no carry
          int carry = (a&b)<< 1 ; // Generate carry using and operator and shift it to the next position
          a = a ^ b ; // Add numbers without carry using XOR
          b = carry ;   // Update b with carry for the next iteration
        }
        return a;
    }
};

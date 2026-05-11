class Solution {
public:
    double myPow(double x, int n) {
        // Base case: anything power 0 is always 1
        // If base is 1, answer will always be 1
        if(x == 1 || n==0) return 1;

        // If base is 0, answer will always be 0
        // If power is 1,  return the number itself
        if(n == 1 || x==0) return x;

         // Convert n into long to handle INT_MIN case
        // (because -INT_MIN overflows for int)
        long binary = n;
        double ans = 1;

          // Handle negative powers
        // Example: 2^-3 = 1 / (2^3)
          if( n <0){
            x = 1/x ;// Take reciprocal of x
            binary = -binary; // Convert negative exponent to positive
      
          }

          while(binary > 0){
             // If current bit is odd (1)
            // multiply answer with current x
            if(binary %2 == 1){
                ans *= x;
            }
             // Square the base
            // Example: x = x^2
            x *= x;
            //move to the next bit
            binary /= 2;
          }
          return ans;

    }
};

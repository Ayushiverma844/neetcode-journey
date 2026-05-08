class Solution {
public:
   
   // sum of squares of digits
    int helper(int n){
        int sum = 0;
        while(n >0 ){
            int r = n %10;
            sum += r*r ;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        // use floyed cycle detection algo for detecting cycle
        // ( slow fast pointer)
        int slow = n;
        int fast = n;
        do{
            slow = helper(slow); //move one step
            fast = helper(helper(fast)); // move two steps
        }while(slow != fast);   // continue until both meet


    // if both meet at 1 -> happy number        
    return slow == 1;
    }
};

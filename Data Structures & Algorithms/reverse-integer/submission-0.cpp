class Solution {
public:
    long long solve(int x){
       long long rev =0;
       while(x > 0){
        int r = x%10 ; 
        rev  = rev*10 + r;
        x /= 10;
       }
       return rev;
    }

    int reverse(int x) {

        bool neg = false;
        if(x < 0){
          x = -(x);
          neg = true;
        }
       
         long long ans = solve(x);

         if(neg){
            ans = -ans;
         }

         if(ans > INT_MAX || ans <INT_MIN){
            return 0;
         }
      

       return (int)ans;
    }
};

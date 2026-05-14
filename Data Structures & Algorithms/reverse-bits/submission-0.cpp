class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
         
        for(int i=0; i<32;i++){
            // Find rightmost bit
            int right = n & 1;
            // Left shift ans and add bit
            ans = (ans << 1) | right;
            //right shift n
            n = n >> 1;
        }
        return ans;
    }
};

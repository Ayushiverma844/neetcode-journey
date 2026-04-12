class Solution {
public:
    int findMin(vector<int> &nums) {
        int st = 0;
        int end = nums.size()-1;
        int ans = INT_MAX;
        while(st <= end){
            if(nums[st] < nums[end]){
                ans = min(ans,nums[st]);
                break;
            }
          int mid = st+(end-st)/2;
           ans = min(ans,nums[mid]);
           if(nums[mid] >= nums[st]){
            // left half is shorted , we alredy clulate minimum from here now 
            // look in right half
            st = mid+1;
           }
           else{
            end = mid-1;
           }

        }
        return ans;
    }
};

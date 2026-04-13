class Solution {
public:
bool is_possible(vector<int>& piles,int h,int k){
    long long time =0;
    for(int i=0;i<piles.size();i++){
        time += (piles[i]+k-1)/k;
    }
    return time<=h ;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r= *max_element(piles.begin(),piles.end());
        int ans =0;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(is_possible(piles,h,mid)){
                ans = mid;
                r = mid-1; 
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
};

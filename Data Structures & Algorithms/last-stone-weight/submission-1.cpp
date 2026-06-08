class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       
       
       while(stones.size() > 1){
        //sort
        sort(stones.begin(),stones.end()); 
         int i = stones.size()-1;
        
        if(stones[i] > stones[i-1]){
            stones[i-1] = (stones[i] - stones[i-1]);
            stones.pop_back();
        }
        else if(stones[i] == stones[i-1]){
            stones.pop_back();
            stones.pop_back();
        }
      }
      if(stones.empty())
            return 0;
      
    return stones[0];
     
    }
};

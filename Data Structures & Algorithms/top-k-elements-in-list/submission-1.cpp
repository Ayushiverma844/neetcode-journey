class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        // count freq
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++ ;
        }
        // convert in pair
        vector<pair<int,int>> v;
        for(auto& i : m){
            v.push_back({i.first,i.second});
        }

        //sort based on freq;
        sort(v.begin(),v.end() ,[](pair<int,int>& a , pair<int,int>& b){
            return a.second > b.second;
        });

        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
       
        return ans;
    }
};

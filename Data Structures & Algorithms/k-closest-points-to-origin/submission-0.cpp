class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> m;
        vector<vector<int>> ans;

        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            double dis = sqrt((x*x)+(y*y)) ;

            m.push({dis,points[i]});

            if(m.size() > k){
                m.pop();
            }
        }
        while (!m.empty()) {
            ans.push_back(m.top().second);
            m.pop();
        }
    return ans;
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        sort(intervals.begin(), intervals.end());

        // Store {query, original_index}
        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        // {interval_length, right_end}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > minHeap;

        vector<int> ans(queries.size(), -1);

        int i = 0;

        for (auto [query, index] : q) {

            // Add all intervals whose left <= query
            while (i < intervals.size() && intervals[i][0] <= query) {
                int l = intervals[i][0];
                int r = intervals[i][1];

                minHeap.push({r - l + 1, r});
                i++;
            }

            // Remove intervals that cannot contain query
            while (!minHeap.empty() && minHeap.top()[1] < query) {
                minHeap.pop();
            }

            // Minimum interval
            if (!minHeap.empty()) {
                ans[index] = minHeap.top()[0];
            }
        }

        return ans;
    }
};
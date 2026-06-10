class TimeMap {
public:

    // key -> list of {value, timestamp}
    unordered_map<string, vector<pair<string, int>>> mp;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {

        // Store the value and timestamp for the given key
        mp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {

        // If key does not exist, return empty string
        if (mp.find(key) == mp.end()) {
            return "";
        }

        // Get all values associated with the key
        auto &values = mp[key];

        string ans = "";

        // Binary Search
        int l = 0;
        int r = values.size() - 1;

        while (l <= r) {

            int m = l + (r - l) / 2;

            // If current timestamp is valid
            // (less than or equal to required timestamp)
            if (values[m].second <= timestamp) {

                // Store current value as a possible answer
                ans = values[m].first;

                // Search on right side to find a larger valid timestamp
                l = m + 1;
            }
            else {

                // Current timestamp is too large
                // Search on left side
                r = m - 1;
            }
        }

        return ans;
    }
};
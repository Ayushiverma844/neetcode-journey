class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        // Pair position with speed
        vector<pair<int,int>> cars;
        for(int i = 0; i < n; i++){
            cars.push_back({position[i], speed[i]});
        }

        // Sort by position in descending order
        sort(cars.begin(), cars.end());
        reverse(cars.begin(), cars.end());

        int fleets = 0;
        double prevTime = 0.0;

        for(auto &car : cars){
            // Time to reach target
            double time = (double)(target - car.first) / car.second;

            // If this car cannot catch the fleet ahead
            if(time > prevTime){
                fleets++;
                prevTime = time;
            }
            // else: it merges into existing fleet
        }

        return fleets;
    }
};
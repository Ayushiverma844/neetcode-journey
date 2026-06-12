class Solution {
public:
    // Function to calculate the sum of all elements in a vector
   int sum(vector<int>& arr){
    int s =0;
    for(int i=0;i<arr.size();i++){
        s += arr[i];
    }
    return s;
   } 
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        // Calculate total gas available and total cost required
        int totalGas = sum(gas);
        int totalCost = sum(cost);
        // If total cost is greater than total gas available,
        // completing the circuit is impossible
        if(totalCost > totalGas){
            return -1;
        }
    
        int ans = 0;   // Stores the possible starting station index
        int currGas = 0; // Tracks the current gas balance while traveling


        for(int i=0;i<gas.size();i++){
             // Update current gas after visiting station i
            currGas  += (gas[i]-cost[i]);

            // If gas becomes negative, we cannot start
            // from the current answer station
            if(currGas < 0){
                ans = i+1;  // Next station becomes the new candidate
                currGas = 0;   // Reset current gas for the new start
            }
        }

        return ans;
    }
};

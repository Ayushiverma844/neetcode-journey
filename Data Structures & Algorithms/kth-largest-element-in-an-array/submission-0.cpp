class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Create a min heap
        // Smallest element will always be at the top
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < nums.size(); i++) {

            // Add current element to the heap
            minHeap.push(nums[i]);

            // Keep only k largest elements
            // If size becomes greater than k,
            // remove the smallest element from the top
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Now heap contains k largest elements
        // The smallest among them is the kth largest element
        // So, kth largest element will be at the top
        return minHeap.top();
    }
};
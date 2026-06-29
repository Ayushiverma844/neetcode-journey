class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) {
                pq.pop();  //min element will be popped
            }
        }
    }
    
    int add(int val) {
       pq.push(val);
         if (pq.size() > k) {
             pq.pop();  //min element will be popped
        }
    return pq.top();
    }
};

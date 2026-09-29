class MedianFinder {
public:
   priority_queue<int,vector<int>> left ; //maxheap [1,2,3]
   priority_queue<int,vector<int>,greater<int>> right ; //minHeap [6,5,4]      
    //dono k top ka avg median hoga even case m


    MedianFinder() {}
    
    void addNum(int num) {
        left.push(num);
        if(!right.empty() && left.top() > right.top()){
            right.push(left.top());
            left.pop();
        }

    // balance both
        if(left.size() > right.size() + 1){
          right.push(left.top());
          left.pop();
        }

        if(right.size() > left.size()+1){
            left.push(right.top());
            right.pop();
        }
        
    }
    
    double findMedian() {
        if(left.size() == right.size()){
            //even
            return (left.top()+right.top()) / 2.0 ;
        }

        else if(left.size() > right.size()){
            return left.top();
        }
        else{
            return right.top();
        }
    }
};

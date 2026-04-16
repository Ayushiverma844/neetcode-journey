class MinStack {
public:
   
   // Stack to stores pairs: {current value, minimum value up to that point}
   stack<pair<int,int>> st; 
    MinStack() {
        //constructor
    }
    
    void push(int val) {
        if(st.empty()){
         // If stack is empty, current value is also the minimum
            st.push({val,val});
        }
        else{
           // Compare current value with previous minimum
            // and store the new minimum along with the value
            int mini = min(val,st.top().second);
            st.push({val,mini});
        }
    }
    
    void pop() {
        // Remove the top element (both value and its stored minimum)
     if(!st.empty()){
        st.pop();
     }   
    }
    
    int top() {
        
        return st.empty() ? 0 : st.top().first ;
    }
    
    int getMin() {
        return st.empty() ? 0 : st.top().second ;
        
    }
};

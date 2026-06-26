class MinStack {
public:
//    stack<pair<int,int>>st;
  
//     MinStack() {
        
//     }
    
//     void push(int value) {
//       if(st.empty())
//     st.push({value, value});
// else
//     st.push({value, min(value, st.top().second)});
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//             }
    stack<long long> st;
    long long mini;

    MinStack() {

    }

    void push(int val) {

        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else if(val >= mini) {
            st.push(val);
        }
        else {
            st.push(2LL * val - mini);
            mini = val;
        }
    }

    void pop() {

        if(st.top() < mini) {
            mini = 2LL * mini - st.top();
        }

        st.pop();
    }

    int top() {

        if(st.top() < mini)
            return mini;

        return st.top();
    }

    int getMin() {

        return mini;
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// class MinStack {
// public:
//     stack<int> stk;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         stk.push(val);
//     }
    
//     void pop() {
//         stk.pop();
//     }
    
//     int top() {
//         return stk.top();
//     }
    
//     int getMin() {
//         stack<int>tmp;
//         int mini=stk.top();
//         while(stk.size()){
//             mini=min(mini,stk.top());
//             tmp.push(stk.top());
//             stk.pop();
//         }
//         while(tmp.size()){
//             stk.push(tmp.top());
//             tmp.pop();
//         }
//         return mini;
//     }
// };

class MinStack {
public:
    long min;
    stack<long> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()) {
            stk.push(0);
            min=val;
        }
        else {
            stk.push(val-min);
            if(val<min) min=val;
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        long pop=stk.top();
        stk.pop();
        if(pop<0) min=min-pop;
    }
    
    int top() {
        long top = stk.top();
        return (top>0) ? (top+min) : (int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};

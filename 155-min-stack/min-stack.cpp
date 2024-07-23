#define ll long long 
class MinStack {
    stack<ll> st;
    int mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(val>mini){
            st.push(val);
        }
        else{
            st.push(2*1ll*val-mini);
            mini = val;
        }
    }
    
    void pop() {
        if(st.empty()){
            return ;
        }
        if(st.top()>mini){
            st.pop();
        }
        else{
            mini = 2*1ll*mini-st.top();
            st.pop();
        }
    }
    
    int top() {
         
        if(st.top()>mini){
            return st.top();
        }
        else{
           return  mini;  //mini  = 2*mini-st.top();
           
        }
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
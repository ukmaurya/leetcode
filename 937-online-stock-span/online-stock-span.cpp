class StockSpanner {
    stack<pair<int,int >> st;
    int timer =1;
public:
    StockSpanner(){
        
    }
    
    int next(int price){
        // if we do by orevious smaller element vector implimentation , we have to call every time 
        int ans = 0;
        
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int prev =0;
        if(!st.empty()){
            prev = st.top().second;
        }
        ans = timer-prev;
        st.push({price , timer++});
       
        return ans  ;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n,-1);
        vector<int> pse(n,-1);
        stack<int> st;
        // nse
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                nse[i]=n;
                st.push(i); // we are pushing index instead of elements 
            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    nse[i] = n;
                    st.push(i);
                }
                else{
                    nse[i]= st.top();
                    st.push(i);
                }
            }
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        // pse
        for(int i=0;i<n;i++){
             if(st.empty()){
                pse[i]=-1;
            }
            else{
                while(!st.empty() && arr[st.top()]>= arr[i]){
                    st.pop();

                }
                if(st.empty())
                 pse[i]=-1;
                else{
                    pse[i] = st.top();
                } 
            }
            st.push(i);
        }
        
        int mod = 1e9+7;
        long long ans =0;
        for(int i=0;i<n;i++){
             long long ls = i-pse[i];
            long long rs = nse[i]-i;
            ans+=(arr[i]*(ls*rs)%mod)%mod;
        }
        return ans%mod;
    }
};
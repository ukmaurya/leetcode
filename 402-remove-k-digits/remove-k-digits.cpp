class Solution {
public:
    string removeKdigits(string num, int k) {
         int n = num.size();
         stack<char> st;
         for(int i=0;i<n;i++){
            char ch = num[i];
            while(!st.empty() && k>0 && st.top() > ch){
                st.pop();
                k--;
            }
            st.push(ch); // pushing when peek is smaller or equal to current element 
         }
         while(k>0){ // in this case stack can contain elements in increasing order 
           st.pop();
           k--;
         }
         string ans = "";
         while(!st.empty()){
            ans+=st.top();
            st.pop();
         }
         reverse(ans.begin() , ans.end());
         int i=0;
         while(ans[i]=='0')
          i++;
        
       string res =  ans.substr(i,ans.size());
       if(res.size()==0)
        return "0";
       return res; 
        
        
    }
};
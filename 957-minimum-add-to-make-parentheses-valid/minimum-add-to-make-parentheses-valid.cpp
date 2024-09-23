class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int n = s.size();
      /*  stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            }
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(')');
                }
                
            }
        }
        return st.size(); */
        
        // using constant space 
        int open = 0;
        int close = 0;
       // int ans =0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }
            else{
                if(s[i]==')'){
                    if(open>0){
                        open--;
                    }
                    else{
                        close++;
                    }
                }
            }
        }
        return open+close;
    }
};
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n = s.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i]==')' && st.size()==1){
                    st.pop();
                    continue;
                    
                }
                else if(s[i]==')' && st.size()!=1){
                    ans = ans+')';
                    st.pop();
                }
                else if(s[i]=='('){
                    ans = ans+'(';
                    st.push('(');
                }
               
                
            }
        }
        return ans;
    }
};
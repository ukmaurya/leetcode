class Solution {
public:
    bool checkValidString(string s) {
          // we will maintain 2 stack , operand and * stack 
          // and we will store the index instead of characters 
          int n = s.size();
          stack<int> st , star;
          for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]=='*'){
                star.push(i);
            }
            else{
                if(st.empty() && star.empty()){
                    return false;

                }
                else{
                    if(!st.empty())
                      st.pop();
                    else{
                        star.pop();
                    }  
                }
            }
          }
          while(!st.empty()){
              if(star.empty())
                return false;
              else if(st.top() > star.top()) // ( is present after start 
                return false;  
              else{
                star.pop();
                st.pop();
              }  
          }
        return true;
    }
};
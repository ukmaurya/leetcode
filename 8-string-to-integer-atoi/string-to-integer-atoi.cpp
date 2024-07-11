class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long  ans = 0;
        int i=0;
        int sign = 1;
        while(s[i]==' '){
            i++;
        }
        if(i<n &&( s[i]=='-'|| s[i]=='+')){
           sign = ( s[i]=='+')?1:-1;
            i++;
        }
        while(i<n && s[i]=='0'){
            i++;
        }
        while(i<n ){
            if( s[i]>='0'&& s[i]<='9'){
             
                if((ans*10+(s[i]-'0'))<=INT_MAX){    // if(ans*10<=(1LL<<31)-1) is also correct 
                    ans = ans*10+(s[i]-'0');
                }
                else{
                    if(sign==1){
                        return INT_MAX;
                    }
                    else{
                        return INT_MIN;
                    }
                }
            }
            else{
                break;
            }
            i++;
        }
        
        return ans*sign;
    }
};
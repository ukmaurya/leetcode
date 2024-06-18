class Solution {
    void caLLlps(string &pattern ,vector<int>&lps ){
        int prefix = 0;
        int suffix = 1;
        lps[0]=0 ;
        while(suffix< pattern.size()){
            if(pattern[suffix]==pattern[prefix]){
                lps[suffix]=prefix+1;
                prefix++;
                suffix++;
            }
            else{
                if(prefix==0){
                    lps[suffix] = 0;
                    suffix++;
                }
                else{
                    prefix = lps[prefix-1];
                }
            }
        }
    }
    bool check(string &text , string &pattern){
        // using kmp algorithm 
        vector<int>lps(pattern.size(),0);
        caLLlps(pattern ,lps);
        // apply kmp algorithm 
        int n = text.size();
        int m = pattern.size();
        int i=0;
        int j =0;
        while(i<n){
            
            if(text[i]==pattern[j]){
                i++;
                j++;
                if(j==m){
                    return true;
                }
            }
            else{ // on not matching we donot move pointer of text so it result in o(n) else time comp will increase
                if(j==0){
                    i++;
                }
                else{
                    j = lps[j-1];
                }
            }
        }
        return false;
        
    }
public:
    int repeatedStringMatch(string a, string b) {
        
        int n = b.size();
        string newa = a;
        int count=1; 
        while(newa.size()<b.size()){ // increase size till it become equal to b
            count++;
            newa = newa+a;
        }
        bool firstcheck  = check(newa , b); // to check weather it is present or not 
        if(firstcheck==true){
            return count;
        }
        newa = newa+a; // if still not matched then increase one more time 
        bool secCheck = check(newa,b);
        if(secCheck==true){
            return count+1;
        }
        // if still not matched then it can not match
        return -1;
    }
};
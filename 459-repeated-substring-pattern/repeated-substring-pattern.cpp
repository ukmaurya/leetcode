class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       // O(N)
        int n=s.size();
        vector<int>lps(n, 0);  // Longest Prefix that is also Suffix 
        int len=0;  // Length of the previous longest prefix suffix
        int i=1;
        while (i<n) {
            if (s[i]==s[len]) {
                len++;
                lps[i]=len;
                i++;
            } else {
                if (len!=0) len=lps[len - 1];
                else lps[i]=0,i++;
            }
        }
        
        int patternLen=lps[n-1];  // Length of the repeated pattern
        if(patternLen>0 && n%(n-patternLen)==0)
            return true;
        return false;
        
       
    }
};
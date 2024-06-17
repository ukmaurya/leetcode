class Solution {
    void calLPS(string s, vector<int>&lps){
        int n = s.size();
        int pre =0;
        int suff = 1;
        while(suff<n){
            if(s[pre]==s[suff]){
                lps[suff] = pre+1;
                suff++;
                pre++;
            }
            else{
               if(pre==0){
                   lps[suff]=0;
                   suff++;
               }
               else{
                   pre = lps[pre-1];
               }
            }
        }
    }
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n,0);
        calLPS(s,lps);
        int len = lps[n-1];
        return s.substr(0,len);
    }
};
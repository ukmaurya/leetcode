class Solution {
   int solve(string s){
    int n = s.size();
    vector<int> lps(n,0);
    int pre =0;
    int suff = 1;
    while(suff<n){
        if(s[pre]==s[suff]){
            lps[suff] = pre+1;
            pre++;
            suff++;
        }
        else{
           
            if(pre==0){
               lps[suff] = 0;
               suff++;
            }
            else{
               pre = lps[pre-1];
            }
            
        }
    }

     return lps[n-1];

   }
public:
    string longestPrefix(string s) {
        int  lps = solve(s);
        string temp = s.substr(0,lps);
        return temp;
    }
};
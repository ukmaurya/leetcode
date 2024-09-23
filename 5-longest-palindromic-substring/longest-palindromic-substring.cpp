class Solution {
 private:
   string preprocess(const string &s) {
    string t = "$";
    for (auto c : s) {
        t += string("#") + c;
    }
    t += "#^";
    return t;
}
    string longest(string s , string t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
       
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0;
                }
                
            }
        }
        int maxi=0;              // Now finding the max element
         for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
              {
                 cout<<dp[i][j]<<" ";
                 maxi=max(maxi,dp[i][j]);
              }
              cout<<endl;
        }
        string temp = "";
        int sptr = -1;
        int tptr = -1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(dp[i][j]==maxi){
                    while(i>=1 && j>=1 && dp[i][j]!=0){
                        temp+=t[j-1];
                        i--;
                        j--;
                     }
                    return temp;
                
                }
            }
        }
        return temp;
    }
    
public:
    string longestPalindrome(string str) {
        
        // applying manchers algorithm --- o(n) time
         string newstr = preprocess(str);
         int n = newstr.size();
         vector<int> p(n, 0);
         int l = 1, r = 1;
    
    for (int i = 1; i < n - 1; i++) {
        int mirr = l+r-i;
        if(i<r){
             p[i] = max(0, min(r - i, p[mirr]));
        }
        while (newstr[i + p[i]] == newstr[i - p[i]]) {
            p[i]++;
        }
        
        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }

    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    int startIndex = centerIndex - maxLen + 1;
    int lastIndex = centerIndex + maxLen - 1;

    string ans = "";
    for (int i = startIndex; i <= lastIndex; i++) {
        if (newstr[i] != '#') {
            ans += newstr[i];
        }
    }
    
    return ans;
        
        
        
        // using longest common substring method it is failing 
        // reversal of string  works in case to find palindromic subsequence not palindromic substring 
      /*  string revs = s;
        reverse(revs.begin() , revs.end());
        return longest(s,revs); */
        
    }
};
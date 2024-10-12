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
    string longest(string s ){
          int n = s.size();
          int index =0;
          int maxi = 0;
          
          vector<vector<bool>>dp(n+1,vector<bool>(n+1,false)); // store the boolean , we can find len and inddex from i and j 
          for(int k=0;k<n;k++){ // we want diagonal wise filling 
            for(int i=0,j =k;j<n;i++,j++){
                   if(i>j)
                     continue;
                   else if(i==j){ // every one len char is palindrome 
                      dp[i][j]=1; 
                   }  
                   else if(j==i+1){ // 2 len palindrome
                        if(s[i]==s[j]){
                            dp[i][j]=true;
                           
                        }
                   }
                   else{
                     if(dp[i+1][j-1] == true && s[i]==s[j]){
                        dp[i][j] = true;
                        

                     }
                   }
                   if(dp[i][j]==true){
                    if(maxi < j-i+1 ){
                            maxi = j-i+1;
                            index = i;
                        }
                   }
                }

          }

        return s.substr(index , maxi);
          
          
          
          
 }
    
public:
    string longestPalindrome(string str) {

         // approach 1: using dp  not optimised 
          string ans = longest(str );
          return ans;
          







        /*  z function code 

int l = 0;
             int r = 0;
             string s = txt;
             //same as manchers algorithm 
             for(int i=1;i<n;i++){
                 int mirr = i-l;  // in manchers algo mirr = l+r-i since it has to be in palindromic range 
                 if(i<r){
                    z[i] = min(z[mirr] , r-i);
                 }
                    while(i+z[i]<n && s[z[i]]==s[i+z[i]]){ // in manchers we check s[i-z[i]]==s[i+z[i]]
                        z[i]++;
                    }
                    if(i+z[i]>r){
                        r = i+z[i];
                        l = i;  // in manchers algo we do l = i-z[i];
                    }
                      
                 
                 
             }
*/ 
    // approach 1 : most optimised 
        
        // applying manchers algorithm --- o(n) time
    //      string newstr = preprocess(str);
    //      int n = newstr.size();
    //      vector<int> p(n, 0);
    //      int l = 1, r = 1;
    
    // for (int i = 1; i < n - 1; i++) {
    //     int mirr = l+r-i;
    //     if(i<r){
    //          p[i] =  min(r - i, p[mirr]);
    //     }
    //     while (newstr[i + p[i]] == newstr[i - p[i]]) {
    //         p[i]++;
    //     }
        
    //     if (i + p[i] > r) {
    //         l = i - p[i];
    //         r = i + p[i];
    //     }
    // }

        
    // int maxLen = 0, centerIndex = 0;
    // for (int i = 1; i < n - 1; i++) {
    //     if (p[i] > maxLen) {
    //         maxLen = p[i];
    //         centerIndex = i;
    //     }
    // }

    // int startIndex = centerIndex - maxLen + 1;
    // int lastIndex = centerIndex + maxLen - 1;

    // string ans = "";
    // for (int i = startIndex; i <= lastIndex; i++) {
    //     if (newstr[i] != '#') {
    //         ans += newstr[i];
    //     }
    // }
    
    // return ans;
        
    // NOTE : approach 3 is alos theier where we find odd len palindrome and even len palindrome 
// sepearately  
        
       // trying new approach  // using longest common substring method it is failing 
        // reversal of string  works in case to find palindromic subsequence not palindromic substring 
      /*  string revs = s;
        reverse(revs.begin() , revs.end());
        return longest(s,revs); */
        
    }
};
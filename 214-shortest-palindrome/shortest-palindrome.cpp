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
    string shortestPalindrome(string str) {
        // we have to find longest prefix plaindrome 
         int n = str.size();
        string temp = str;
        reverse(temp.begin(), temp.end());
        string s = str + '$' + temp; // $ is added to break continuity , ex aaaa 
        
        // after adding the string in reverse , let lps=x will tell that x prefix part of string is equal to its reverse x part => x prefix part is palindrome
        vector<int> lps(s.size(), 0);
        calLPS(s, lps);
        int addLength = n - lps[s.size() - 1];
        string front = temp.substr(0, addLength);
        return front + str;
    }
};
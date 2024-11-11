class Solution {
    bool palindrome(string s){
         int n =s.size();
         int i=0;
         int j = n-1;
         while(i<j){
            if(s[i]!= s[j]){
                return false;
            }
            i++;
            j--;
         }
         return true;
    }
    void solve(int i , string &s,vector<string>&temp ,vector<vector<string>>&ans){
        int n = s.size();
        if(i>=n){
           ans.push_back(temp);
           return ;
        }
        
        for(int idx=i;idx<n;idx++){
            string str = s.substr(i,idx-i+1);
            if(palindrome(str)){
                temp.push_back(str);
                solve(idx+1 , s , temp , ans);
                temp.pop_back();
            }
        }


    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,s,temp, ans);
        return ans;
    }
};
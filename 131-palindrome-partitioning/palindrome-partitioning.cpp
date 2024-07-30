class Solution {
    private:
    bool isValid(int start , int end , string s){
        while(start<end){
            if(s[start]!=s[end]){
                return false ;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(int i, int n , string s, vector<string >&temp , vector<vector<string>> &ans){
        if(i==n){
            ans.push_back(temp);
           return;
        }
        for(int par = i;par<n;par++){
            if(isValid(i,par,s)){
                 temp.push_back(s.substr(i,par-i+1));
                 solve(par+1,n,s,temp,ans);
                 temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
       vector<vector<string>> ans;
       vector<string> temp;
       solve(0,s.size(),s,temp,ans);
       return ans; 
    }
};
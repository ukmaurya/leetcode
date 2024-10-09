class Solution {
    void solve(int idx , string& start,  vector<string>&vec , int n){
        if(idx==n){
            vec.push_back(start);
            return ;
        }
        
            start +='1';
            solve(idx+1 , start , vec, n);
            start.pop_back();
        if(idx>0 && start[idx-1]=='0'){
            return;
        }
            start +='0';
            solve(idx+1 , start , vec, n);
            start.pop_back();
        
       
        
    }
public:
    vector<string> validStrings(int n) {
         // no consecutive 0 
        string start = "";
      
         vector<string> vec;
        solve(0, start, vec , n);
        return vec;
        
        
    }
};
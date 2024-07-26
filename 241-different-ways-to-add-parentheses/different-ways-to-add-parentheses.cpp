
class Solution {
    private:
    vector<int> solve(string s){
        if(s.size() == 0){
           
            return { }; 
        }
        int n = s.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(s[i]=='+' || s[i]=='-'||s[i]=='*'){
                vector<int> left = solve(s.substr(0,i));
                vector<int> right = solve(s.substr(i+1 , n-i+1));
                for(int l=0;l<left.size();l++){
                    for(int r=0;r<right.size();r++){
                        if(s[i]=='+'){
                            ans.push_back(left[l]+right[r]);
                        }
                        else if(s[i]=='-'){
                            ans.push_back(left[l]-right[r]);
                        }
                        else{
                            ans.push_back(left[l]*right[r]);
                        }
                    }
                }
            }
        }
        if(ans.size() == 0){
            int temp = stoi(s);
             ans.push_back(temp); // edge case "11"
        }
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
          
          // accordint to given contrained and idea (to try all possibility )=> recurtion 
          return solve(expression);
    }
};
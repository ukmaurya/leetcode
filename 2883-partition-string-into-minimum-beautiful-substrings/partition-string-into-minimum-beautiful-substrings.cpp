class Solution {
    bool notleadZero(string &s , int start , int cur){
        if(s[start]=='0')
          return false;
        return true;
    }
    bool power5(string &s , int start , int cur){
        string temp = s.substr(start , cur-start+1);
        if(temp=="")
            return false;
        long long  num = stoll(temp, nullptr, 2);
        if(num == 0)
            return false;
        while(num%5 == 0) 
            num /= 5;
        return num == 1;
    }
    bool isValid(string &s , int start , int cur){
        return notleadZero(s , start, cur)&&power5(s, start, cur);
    }
    int solve(int idx , string&s ){
        int n = s.size();
        if(idx>=n){
            return 0;
        }
        int ans = INT_MAX;
        for(int i = idx ;i<n;i++){
            if(isValid(s,idx, i )){
                int temp = solve(i + 1, s);
                if (temp != INT_MAX) { // Only consider valid partitions
                    ans = min(ans, 1 + temp);
                }
            }
           
        }
        return ans;
    }
public:
    int minimumBeautifulSubstrings(string s) {
       int ans = solve(0,s);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
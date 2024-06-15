class Solution {
    string solveRLE(string s){
       
        string ans ="";
        for(int i=0;i<s.size();){
            int count=0;
            char cur = s[i];
            int index = i;
            while(index<s.size() && s[index]==cur){
                index++;
                count++;
            } 
            ans.push_back(count+'0');
            ans.push_back(cur);
            i = index;
        }

         return ans;
    }
public:
    string countAndSay(int n) {
       
        if(n==1){
          return "1";
        }
        string ans = countAndSay(n-1);
        string res = solveRLE(ans);
        return res;
   }
};
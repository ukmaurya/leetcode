class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        int j = n-1;
        while(j>=0 && s[j] == ' '){
            j--;
        }
        while(j>=0){
            if(s[j]==' '){
                j--;
                continue;
            }
            int len = 0;
            int i = j;
            while(i>=0 && s[i] !=' '){
                i--;
                len++;
            }
            string temp = s.substr(i+1 , len);
            ans  = ans+temp+" ";
            j=i;
        }
        ans.pop_back();
        return ans;
    }
};
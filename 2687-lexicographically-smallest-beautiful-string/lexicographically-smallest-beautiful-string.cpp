class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        string inp = s;
        bool bad = true;
        for(int i = n-1;i>=0;i--){
            bool isPossible = true;
            for(int j = i;j<n;j++){ /// will run 2-4 times at most
                char atLeast = 'a';
                if(j == i){
                    atLeast = s[i]+1;
                }
                bool found = false;
                for(int c = atLeast;c<=('a'+k-1);c++){ // will run 2-4 times at most
                    if((j == 0 || s[j-1]!=c) && (j<=1 || s[j-2]!=c)){
                        s[j] = c;
                        found = true;
                        break;
                    }
                }
                if(!found) {isPossible = false; break;}
            }
            if(isPossible) {bad = false; break;}
            else{
                for(int l = i;l<min(n,i+2);l++) s[i] = inp[i];
            }
        }
        if(bad) return "";
        return s;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char , int > mp;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        int startIndex = -1;
        int minLen = INT_MAX;
        int matched = t.size(); // number of char to be matched 
        int i = 0;
        int j = 0;
        while(j<n){
            if(mp.find(s[j])!= mp.end()){ // char is present in string
                mp[s[j]]--;
                if(mp[s[j]]>=0)
                   matched--;
                
            }
            if(matched>=1){ // more char to be matched 
                   j++;
            }
            else{ // all character are matched 
                  if(minLen > j-i+1){
                         minLen = min(minLen , j-i+1);
                         startIndex = i;
                      }
                  while(matched <= 0){
                     if(mp.find(s[i]) != mp.end()){
                       mp[s[i]]++;
                      if(mp[s[i]]>0)
                         matched++;
                      if(minLen > j-i+1){
                         minLen = min(minLen , j-i+1);
                         startIndex = i;
                      }
                     }
                     i++;
                  }
                  j++;
            }


        

        }
        if(startIndex==-1){
            return "";
        }
        string ans = "";
        ans = s.substr(startIndex , minLen);
        return ans;

  }
};
class Solution {
public:
    bool isIsomorphic(string s, string t) {
  
        //  since we have to preserve the order also , so need of sorting 
        // see "bbbaaaba" "aaabbbba" ans should be false if we do sorting 
     /*    int n1 = s.size();
         int n2 = t.size();
         if(n1 != n2){
             return false;
         }
         vector<int> freq1(256 ,0);
         vector<int> freq2(256 , 0);
         for(int i=0;i<n1;i++){
             freq1[s[i]]++;
         }
         for(int j=0;j<n2;j++){
             freq2[t[j]]++;
         }
        for(int i=0;i<n1;i++){
            if(freq1[s[i]]!=freq2[i]){
                return false;
            }
        }
        return true;  */
        // giving wrong ans on "egg" and "add"
        
        // since we have to preserve order and mapping 
         int n1 = s.size();
         int n2 = t.size();
         if(n1 != n2){
             return false;
         }
        unordered_map<char , char> mp1;
        unordered_map<char , char > mp2;
        for(int i =0;i<n1;i++){
            if(mp1.find(s[i])!=mp1.end()){
                if(t[i] != mp1[s[i]] ){ // mapped to differnet char 
                    return false;
                }
            }
            else{
                mp1[s[i]] = t[i];
            }
        }
        
        for(int i =0;i<n2;i++){
            if(mp2.find(t[i])!=mp2.end()){
                if(s[i] != mp2[t[i]] ){ // mapped to differnet char 
                    return false;
                }
            }
            else{
                mp2[t[i]] = s[i];
            }
        }
        
        return true;
        
        
    }
};
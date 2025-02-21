class Solution {
public:
    bool checkInclusion(string s1, string s2) {
          int n1 = s1.size();
          int n2 = s2.size();
          if(n2<n1)
           return false;
          vector<int > freq(26,0);
          for(int i=0;i<n1;i++){
            freq[s1[i]-'a']++;
          }
          vector<int> temp(26,0);
          int i=0;
          int j=0;
          while(j<n2){
                  // calculation on j 
                 temp[s2[j]-'a']++;
                 if(j-i+1 < n1)
                   j++;
                 else if(j-i+1 == n1){
                      if(temp == freq){
                         return 1;
                      }
                      // slide 
                       temp[s2[i]-'a']--;
                       i++;
                       j++;
                 }  
                
               
          }
          return false;
    }
};
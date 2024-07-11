class Solution {
 private:
    string preprocess(string &s) { // preporcessing is required so that we donot have to deal                                     // with even and odd len palindrome seperately 
        int n = s.size();
        string newstr="";
        for(int i=0;i<n;i++){
            newstr += '#';
            newstr+=s[i];
        }
        newstr+="#";
        return newstr;
}
public:
    string longestPalindrome(string s) {
         // using machers algorithm , o(n) time
         string newstr = preprocess(s);
         int n = newstr.size();
         vector<int> p(n, 0); // stores , at a perticular character , radius of palindrome 
         int l = 0, r = 0; // left and right boundary of the current rightmost palindrome
        
        for(int i=0;i<n;i++){
            int radius = 0;
            if(i>r){ // char is outside the rightmost palindrome boundry 
                radius = 0; 
            }
            else{
                int mirror = r-i+l;
                // mirror is inside the plaindrome boundry 
                if(mirror>l)
                  radius = min(p[mirror],r-i); 
                else
                  radius = r-i; 
             }
             // now there may be further matching 
              while(i-radius>=0 && i+radius<n && newstr[i-radius]==newstr[i+radius]){
                        radius++;
                  }
               radius--;  
               p[i] = radius;
              if(i+radius>r){ // new boundry is more than prev boundry 
                        l = i-radius;
                        r = i+radius;
                        
                    }
             
        }
    
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 0; i < n ; ++i) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }
    cout<<newstr<<endl;
    cout<<maxLen<<" "<<centerIndex<<endl;
    int startIndex = centerIndex-maxLen;
    int lastIndex = centerIndex+maxLen; //centerIndex+maxLen;    
    string ans ="";
        for(int i=startIndex;i<=lastIndex;i++){
            if(newstr[i]!='#'){
                ans +=newstr[i];
            }
        }
        return ans;
    }
};
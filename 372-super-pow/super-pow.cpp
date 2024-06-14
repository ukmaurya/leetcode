class Solution {
    
    int binaryExponential(int a , int b , int mod){
        // using iterative method
        a = a%mod;
        int ans = 1;
        while(b>0){
            if(b&1){ // 0th bit is set => it will contributes to answer
                
                ans = (ans*(1LL)*a)%mod; // since when ans*a done it may go to long long and after mod it comes again in int  
                
            }
            a = (a*(1LL)*a)%mod;
            b=b>>1;
        }
        return ans;
    }
  
public:
    int superPow(int a, vector<int>& b) {
        
        // b has very big size ,using eulers theorem  ( Numbers of number  relatively prime to n  )
        // 1337 is not a prime number 
        a = a%1337; // in case a may be large 
        int newMod  = 1140 ; // using euler theorem as 1337 = 7*191 now apply formula
        // n*(1-1/p1)*(1-1/p2)*....... for non prime number 
        // for prime numbers it is equql to n-1;
        
        // calculation to get b 
        
       // int B = solve(b,1140);
        int n = b.size();
        int B = 0;
        for (int i = 0; i < n; ++i) {
            B = (B*(1LL)* 10 + b[i]);
            if(B%1140)
             B=B%1140 ;  // EDGE CASE When power becoming zero 
        }
       // return B;
        return binaryExponential(a,B,1337); // 1337 not 1140 , see euler formula 
        
        
        
    }
};
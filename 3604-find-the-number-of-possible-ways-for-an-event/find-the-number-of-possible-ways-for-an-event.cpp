#define ll long long 
class Solution {
    ll N = 1001;
    int mod = 1e9+7;
vector<ll> fact;
vector<ll> invFact;
ll binaryExponentiation(ll a, ll b, int mod ){   
    if(b==0){
        return 1;
    }
    else if(b==1){
        return a;
    }
    ll ans = 1;
    while(b){
        if(b&1){
            ans =( ans*a)%mod;
        }
        a = (a*a)%mod;
        b = b>>1;
    }
    return ans%mod;
}
ll ncr(ll n , ll r){
    ll req=0;
    req = ((fact[n]*invFact[r])%mod*invFact[n-r])%mod;
    return req;
}
public:
    int numberOfWays(int n, int x, int y) {
        // calcultaion of factorial 
        fact.resize(1001);
        invFact.resize(1001);
      fact[0]=1;
      
      for(int i=1;i<N;i++){
        fact[i]=(1LL*fact[i-1]*i)%mod;
      }
      // calculation of inverse factorial  
     
      invFact[N-1] = binaryExponentiation(fact[N-1] , mod-2 , mod);
      for(int i=N-2 ;i>=0;i--){
        invFact[i] = (((i+1)*1LL)*(invFact[i+1]%mod))%mod;
      }

      // above was templates 

       vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= x; j++) {
                dp[i][j] = (j * dp[i - 1][j]%mod + dp[i - 1][j - 1]%mod) % mod;
            }
        }//O(n*x)

        ll ans = 0;
        for (int i = 1; i <= x; i++) {
            ans = (ans + ncr(x, i) * binaryExponentiation(y, i,mod) % mod * dp[n][i] % mod * fact[i] % mod) % mod;
        }//O(x*logn)
        return ans;


    }
};
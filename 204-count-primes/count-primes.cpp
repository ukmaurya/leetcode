class Solution {
public:
    int countPrimes(int n) {
        int N = n;
        vector<bool> sieve(N+1 , true);
	    sieve[0]=sieve[1]=false;
	    for(int i=2;i*i<=N;i++){
	        if(sieve[i]==true){
	            for(int j=2*i;j<=N; j+=i ){
	                sieve[j] = false;
	            }
	        }
	    }
	   int count=0;
	    for(int i=0;i<N;i++){
	        if(sieve[i]==true){
	           count++;
	        }
	    }
	    return count;
    }
};
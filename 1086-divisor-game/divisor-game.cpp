class Solution {
bool solve(vector<vector<int>>&dp, int n, bool Aliceturn)
{
	if (n == 0 || n == 1)
	{
		if (Aliceturn == true)
			return dp[n][Aliceturn] = 0;
		else
			return dp[n][Aliceturn] = 1;
	}
	if (dp[n][Aliceturn] != -1)
		return dp[n][Aliceturn];
    bool ans = (Aliceturn==true)?false:true;
	for (int i = 1; i * i < n; i++)
	{
		if (n % i != 0)
			continue;
        if(Aliceturn)
		  ans = ans||solve(dp, n - i, !Aliceturn);
        else
          ans = ans&&solve(dp, n - i, !Aliceturn);
		
	}
	return dp[n][Aliceturn] = ans;
}
public:
  bool divisorGame(int n) {
	 vector<vector<int>> dp(n + 1, vector<int>(2,-1));
	 return solve(dp, n, true);
}
};
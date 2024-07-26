class Solution {
    int catalanNumber(int n,vector<int> &catNum){
        if(n==0||n==1){
            return 1;
        }
        if(n==2)
         return 2;
        if(catNum[n]!= -1){
            return catNum[n];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += catalanNumber(i,catNum)*catalanNumber(n-1-i,catNum);
        }
        return catNum[n] = ans;
    }
public:
    int numTrees(int n) {
        // it can be solved using 1)  catalan number in o(n) time 
        // 2) dp o(n^2) time 
       vector<int> catNum(n+1,-1);
       int res = catalanNumber(n,catNum);
       return res;


    }
};
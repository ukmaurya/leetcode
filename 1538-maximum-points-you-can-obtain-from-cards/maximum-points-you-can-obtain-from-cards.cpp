class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int size = n-k;
        int i=0;
        int j=0;
        int tot = 0;
        for(int i=0;i<n;i++){
            tot+=cardPoints[i];
        }
       long long ans = 0;
       long long sum = 0;
        while(j<n){
            sum+=cardPoints[j];
            if(j-i+1 < size){
                j++;
            }
            else if((j-i+1) >= size){
                ans = max(ans , tot-sum);
                while((j-i+1)>=size){
                    sum = sum-cardPoints[i];
                    i++;
                }
                j++;
            }
        }
        return ans;
        
    }
};
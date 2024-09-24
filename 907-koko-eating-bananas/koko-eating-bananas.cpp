class Solution {
    bool ispossible(vector<int>&piles , int h , int mid){
        int n = piles.size();
        double count=0;
        for(int i=0;i<n;i++){
            count += ceil(piles[i]*1.0/mid);
        }
        if(count<=h){
            return true;
        }
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans =-1;
        int start = 0;
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi , piles[i]);
        }
        int end = maxi ;
        while(start<=end){
            int mid = start-(start-end)/2;
            if(ispossible(piles , h, mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};
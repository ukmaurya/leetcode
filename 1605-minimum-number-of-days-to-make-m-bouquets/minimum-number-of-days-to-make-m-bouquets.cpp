class Solution {
    bool isPossible(int mid , vector<int>& bloomDay,int m , int k){
        int count=0;
        int cnt =0;
        int n = bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                cnt++;
                if(cnt==k){
                    count++;
                    cnt=0;
                }
                
            }
            else{
                cnt=0;
            }
        }
        if(count>=m){
            return true;
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int start= INT_MAX;
        int end = INT_MIN;
        for(int i=0;i<n;i++){
            start = min(start , bloomDay[i]);
            end = max(end , bloomDay[i]);
        }
        int ans = -1;
        while(start<= end){
            int mid = start+(end-start)/2;
            if(isPossible(mid, bloomDay,m,k)){
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
#define ll long long 
class Solution {
    bool poss(int mid ,vector<int>& quantities , int n  ){
        ll count =0;
        int m = quantities.size();
        ll sum=0;
        for(int i=0;i<m;i++){
            count += ceil(quantities[i]*1.0/mid);
        }
        if(count<=n){
            return true;
        }
        return false;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        ll start =1;
        ll end = 0;
        ll sum = 0;
        for(int i=0;i<m;i++){
            sum += quantities[i];
        }
        end = sum;
        ll ans = -1;
        while(start <= end){
            ll mid = start+(end-start)/2;
            if(poss(mid , quantities , n)){
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
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int a,b,c;
        a = b=0;
        c = n-1;
        while(b <= c){
            if(nums[b]==0){
                swap(nums[a] , nums[b]);
                b++;
                a++;
            }
            else if(nums[b]==1){
                b++;
            }
            else{
                swap(nums[c] , nums[b]);
                c--;
            }
        }
        return ;
    }
};
class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        
          int ans = 0;
          int n = nums.size();
          sort(nums.begin() ,  nums.end()); // else it will not explore all permutations
          do{
              string str = "";
              for(int i=0;i<n;i++){
                  int ele = nums[i];
                  // find binary of this number 
                  string e = "";
                  while(ele){
                      int rem = ele%2;
                      if(rem){
                          e +='1';
                      }
                      else{
                          e += '0';
                      }
                      ele = ele>>1;
                  }
                  reverse(e.begin() , e.end());
                  str += e;
                }
              
              int new_permutaion = stoi(str ,0,2);
              ans = max(ans , new_permutaion);
              
          }while(next_permutation(nums.begin() , nums.end())) ;// if we use the while loop it not consider the orginal permutaion of nums array 
        return ans;
        
    }
};
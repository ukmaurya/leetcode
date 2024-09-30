class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        
        vector<vector<int>> ans;
        int n = intervals.size();
        ans.push_back(newInterval);
      
        for(int i=0;i<n;i++){
               vector<int> temp = ans.back();
               int start = temp[0];
               int end = temp[1];
               ans.pop_back();
              
              int curStart = intervals[i][0];
              int curEnd = intervals[i][1];
               
               if(curStart > end){ //no overlapping
                   ans.push_back({start , end});
                   ans.push_back({curStart , curEnd});
               }
               else if(curEnd < start){
                    ans.push_back({curStart , curEnd});
                    ans.push_back({start , end});
               }
            else{
                int s = min(curStart , start );
                int e = max(curEnd , end);
                ans.push_back({s,e});
            }
            
        
          }
        
        return ans;
        
    }
};
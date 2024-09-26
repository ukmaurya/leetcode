class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        
        vector<vector<int>> ans;
        int index=0;
        while(index<n){
            
            int start = intervals[index][0];
            int end = intervals[index][1];
            if(ans.empty()){
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                continue;
            }
            else{
                vector<int> temp = ans.back();
                ans.pop_back();
                int prevs = temp[0];
                int pree = temp[1];
                if(start>pree){ // no merging 
                    ans.push_back(temp);
                    ans.push_back({start , end});
                }
                else if(start>prevs && end<pree){ // complete overlapping
                    ans.push_back(temp);
                }
                else{
                    int newstart = min(prevs , start);
                    int newend = max(pree , end );
                    ans.push_back({newstart , newend});
                }
                
            }
            index++;
            
        }
        
        return ans;
    }
};
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
          int n = players.size();
           int m = trainers.size();
        sort(players.begin() , players.end());
        sort(trainers.begin() , trainers.end());
        int ans =0;
        int ind1 =0;
        int ind2 =0;
        while(ind1<n && ind2<m){
            if(players[ind1]<=trainers[ind2]){
                ans++;
                ind1++;
                ind2++;
            }
            else{
                ind2++;
            }
        }
        return ans;
    }
};
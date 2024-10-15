class Solution {
    public:
static bool comp(const vector<int>& p1, const vector<int>& p2) {
    return p1[1] < p2[1];
}

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end() , comp);
        int n = pairs.size();
        auto lastChain = pairs[0];
        int count = 1;
        for (int i = 1; i < pairs.size(); i++)
        {
            if (lastChain[1] < pairs[i][0])
            {
                lastChain = pairs[i];
                count++;
            }
        }
        return count;
    }
};
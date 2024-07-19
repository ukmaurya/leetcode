#define ll long long 
class Solution {
    private:
    void solveps(vector<int>&nums , vector<int>&preSmall){
        int n = nums.size();
        stack<int > st; // we will store indexes so that we donot require to make the pairs of element and thier indexes
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                preSmall[i] = -1;
                st.push(i);
            }
            else{
                preSmall[i] = st.top();
                st.push(i);
                }
        }

    }
    void solvens(vector<int>&nums , vector<int>&nextSmall){
        int n = nums.size();
        stack<int > st; // we will store indexes so that we donot require to make the pairs of element and thier indexes
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty()){
                nextSmall[i] = n;
                st.push(i);
            }
            else{
                nextSmall[i] = st.top();
                st.push(i);
                }
        }

    }
    void solvepl(vector<int>&nums , vector<int>&preLarge){
        int n = nums.size();
        stack<int > st; // we will store indexes so that we donot require to make the pairs of element and thier indexes
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                preLarge[i] = -1;
                st.push(i);
            }
            else{
                preLarge[i] = st.top();
                st.push(i);
                }
        }

    }
    void solvenl(vector<int>&nums , vector<int>&nextLarge){
        int n = nums.size();
        stack<int > st; // we will store indexes so that we donot require to make the pairs of element and thier indexes
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(st.empty()){
                nextLarge[i] = n;
                st.push(i);
            }
            else{
                nextLarge[i] = st.top();
                st.push(i);
                }
        }

    }
public:
    long long subArrayRanges(vector<int>& nums){
        int n = nums.size();
        // calculation of next and previous greater and next and previos smaller 
        vector<int> preSmall(n,-1);
        vector<int> nextSmall(n,-1);
        vector<int> preLarge(n,-1);
        vector<int> nextLarge(n,-1);
        solveps(nums,preSmall);
        solvens(nums,nextSmall);
        solvepl(nums,preLarge);
        solvenl(nums,nextLarge);

        long long  largest = 0;
        for(int i=0;i<n;i++){
            largest+= (ll)((ll)((ll)(nextLarge[i]-i)*(ll)(i-preLarge[i]))*nums[i]);
        }
        long long  smallest=0;
        for(int i=0;i<n;i++){
            smallest += (ll)((ll)((ll)(nextSmall[i]-i)*(ll)(i-preSmall[i]))*nums[i]);
        }

        return largest-smallest;
    }
};
class Solution {
    int MaxRecArea(vector<int>&arr){
        int n = arr.size();
        vector<int> psmall(n,-1);
        vector<int> nsmall(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                psmall[i] = -1;
            }
            else{
                psmall[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nsmall[i] = n;
            }
            else{
               nsmall[i] = st.top();
            }
            st.push(i);
        }
        int maxi = 0;
        for(int i=0;i<n;i++){
              int len = min((nsmall[i]-psmall[i])-1,arr[i]);
              int area = len*len;

            maxi = max(maxi , area );
        }
        return maxi;
        
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
         int n = matrix.size();
        int m = matrix[0].size();
        int maxi =0 ;
         vector<int> histogram(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(matrix[i][j]=='1'){
                   histogram[j]++;
               }
               else{
                   histogram[j]=0;
               }
               
            }
          int area = MaxRecArea(histogram);
          maxi = max(area , maxi);
        }
        return maxi;
    }
};

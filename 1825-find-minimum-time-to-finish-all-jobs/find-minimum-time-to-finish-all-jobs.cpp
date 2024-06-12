class Solution {
public:

bool solve(int ind,vector<int>&jobs,vector<int> &workers,int mid){
    
    // every jobs can be assigned to every workers => every jobs have choices aand choices are variable ie number of workers , and also it can be large => backtracking 
    
    
    // base case 
     if(ind >= jobs.size()){ // all jobs are assigned
         return true;
     }
      bool ans = false;
     for(int i=0;i<workers.size();i++){ // iterate through all choices for each job
         
         if(jobs[ind]+workers[i] <= mid){
             workers[i] = workers[i]+jobs[ind];
           /*  ans = ans || solve(ind+1 , jobs,workers, mid); // if solve return true the return ans as true or iterate through all possibilities  */
             // pruinning is not done => iterating through all possibilities => may give TLE 
             
             if(solve(ind+1 , jobs,workers, mid)==true)
                  return true;
             
               workers[i] = workers[i]-jobs[ind]; // revert the changes as we have passed by refernce , since backtracking not recursion 
         }
         if(workers[i]==0) break; // it ensures that if no job is assigned to current worker , then  no need to move to subsequent worker , so this step reduces lot of unneccesary calculation , thus prevent from TLE; 
     }
    return ans;
   
}
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int l=*max_element(jobs.begin(),jobs.end());
        int r=accumulate(jobs.begin(),jobs.end(),0);
         int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            vector<int> workers(k,0);
            if(solve(0,jobs,workers,mid)){ // wether all jobs can be assigned to k workers such that maxi wroking time is m
                ans= mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }


        }
        return ans;
    }
};
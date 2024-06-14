struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return (links[bit]!= NULL);
    
    }
    Node *get(int bit){
        return links[bit];
    }
    
    void put(int num , Node* node){
        links[num]=node;
    }
    
};
class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        
        Node * node = root;
        for(int i=31;i>=0;i--){
            int bit = num&(1<<i);
            if(bit != 0)
                bit = 1;
            else 
                bit = 0;
            if(!node->containsKey(bit)){
                node->put(bit , new Node());
            }
            node= node->get(bit);
        }
        
    }
    
   int getMax(int num){
        Node *node = root;
        int maxi=0;

        for(int i=31;i>=0;i--){
            //int bit = num&(1<<i);
            int bit = (num>>i)&1;
            int req = 1-bit;
            if(node->containsKey(req)){
                
                maxi = maxi|(1<<i);
                node = node->get(req);
              }
            else{
                 node = node->get(bit);
            }
        }
        
        return maxi;
    }
};



class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
         int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<pair<int,pair<int,int>>> q; // m,x,query_number
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i][1] ,{queries[i][0] ,i} });
        }
        // sort the queries on basis of m , so it will be easy to iterate on array
        sort(q.begin() , q.end());
        
        vector<int> ans(queries.size(),0); // offline query
        Trie trie;
         int i=0;
        for(auto it : q){
            int m = it.first;
            int x = it.second.first;
            int qno = it.second.second;
            while(i<n && nums[i]<=m){
               
                    trie.insert(nums[i]);
                    i++;
                
                
            }

            if(i==0)
              ans[qno]=-1;
            else 
              ans[qno]= trie.getMax(x);;
                    
            
        }
        return ans;
        
         
    }
};
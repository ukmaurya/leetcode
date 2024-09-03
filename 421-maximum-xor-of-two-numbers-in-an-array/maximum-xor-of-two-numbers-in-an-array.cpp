struct Node{
    Node* links[2];
    bool flag = false;
    bool containsKey(int key){
        if(links[key]){
            return true;
        }
        return false;
    }
    Node* getKey(int bit){
        return links[bit];
    }
    void put(int key , Node* node){
         links[key] = node;
    } 
      
};
class Trie{
    Node* root;
    public:
      Trie(){
          root = new Node();
      }
    void insert(int num){
       
        Node *node = root;
        for(int i=31;i>=0;i--){
            int bit = ( num>>i )&1;
            if(!node->containsKey(bit)){
                node->put(bit , new Node());
             }
            node = node->getKey(bit);
            
        }
    }
    int getMaxXor(int num){
         Node *node = root;
        int mask = 0;
        for(int t=31;t>=0;t--){
            int bit = (num>>t)&1;
            int req = 1-bit;
            if(node->containsKey(req) ){
                mask = mask|(1<<t);
                node = node->getKey(req);
             }
            else{
                node = node->getKey(bit);
            }
           
        }
        return mask;
    }
    
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums){
       int n = nums.size();
       Trie trie;
       for(int i=0;i<n;i++){
           // we need to insert the binary bits 
           trie.insert(nums[i]);
       }  
       int maxi = INT_MIN;   
        for(int i=0;i<n;i++){
             int temp = trie.getMaxXor(nums[i]); // class elements are accessed by . but structure elements are accessed by ->
             maxi = max(maxi , temp);
        }
        
    return maxi ;    
    }
};
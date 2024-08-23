/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    void preorder(TreeNode* root , vector<pair<int, pair<int,int>>>&pre, int r , int c){
        if(root==NULL){
            return ;
        }
        pre.push_back({c,{r,root->val}});
        preorder(root->left , pre, r+1, c-1);
        preorder(root->right , pre, r+1 , c+1);
        
    }
    bool static mycomp(pair<int, pair<int,int>>&p1  , pair<int, pair<int,int>>&p2){
        if(p1.first<p2.first){
            return true;
        }
        else if(p1.first == p2.first){
            if(p1.second.first < p2.second.first)
              return true;
            else if(p1.second.first == p2.second.first){
               return (p1.second.second < p2.second.second); 
            }
        }
        return false;

    }
   
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
            
        
           vector<pair<int, pair<int,int>>> pre; // col , row , ele
           preorder(root , pre,0,0);
           sort(pre.begin() , pre.end(),mycomp);
           map<int , vector<int>>mp;
           for(auto it : pre){
               mp[it.first].push_back(it.second.second);
           }
          vector<vector<int>>ans;
          for(auto it : mp){
              
             ans.push_back(it.second);
              
          }
        return ans;
   
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
   void preorder(TreeNode* root , unordered_map<TreeNode* , TreeNode* > &parent ){
        if(root==NULL){
            return ;
        }
         
        if(root->left){
            parent[root->left]=root;
        }
        if(root->right){
            parent[root->right]=root;
        }
        preorder(root->left , parent);
        preorder(root->right , parent);
    }
 public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       
          unordered_map<TreeNode* , TreeNode* > parent;
          parent[root]=NULL;
          preorder(root , parent); // making of parent pointer 
        
        // apply bfs 
        queue<pair<int,TreeNode*>> q;
        q.push({0,target});
        vector<int> ans;
        unordered_map<TreeNode* , bool > vis;
        vis[target] = true;
        while(!q.empty()){
            auto node= q.front().second;
            int dist = q.front().first;
            vis[node]=true;
            q.pop();
            if( dist>k){
                continue;
             }
            if( dist == k){
                ans.push_back(node->val);
             }
            if(node->left && !vis[node->left]){
                 //vis[node->left]=true;
                q.push({dist+1 , node->left});
            }
            if(node->right && !vis[node->right]){
                // vis[node->right]=true;
                q.push({dist+1 , node->right});
            }
            if(parent[node] && !vis[parent[node]]){
                // vis[node->right]=true;
                q.push({dist+1 , parent[node]});
            }
            
        }
         
       return ans;
    }
};
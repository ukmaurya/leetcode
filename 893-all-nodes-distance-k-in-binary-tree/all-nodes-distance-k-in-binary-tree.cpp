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
    unordered_map<TreeNode* , TreeNode*> parent;
   void makeParent(TreeNode* root , TreeNode* par){
        if(root==NULL)
          return;
       
        parent[root] = par;
        makeParent(root->left , root);
        makeParent(root->right,root);
                   
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeParent(root , NULL);
        // now apply bfs
        queue<pair<TreeNode* , int >> q;
        unordered_map<TreeNode* , bool> vis;
        vector<int> ans;
        q.push({target , 0});
        vis[target] = true;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(it.second==k)
              ans.push_back(it.first->val);
            else if(it.second>k)
              continue;  
            if(it.first->left && vis[it.first->left]==false){
                vis[it.first->left]=true;
                q.push({it.first->left , it.second+1});
            }  
            if(it.first->right&& vis[it.first->right]==false){
                vis[it.first->right]=true;
                q.push({it.first->right, it.second+1});
            } 
            if(parent[it.first] && vis[parent[it.first]]==false){
                  vis[parent[it.first]]= true;
                  q.push({parent[it.first], it.second+1});
            }


        }
        return ans;
    }
};
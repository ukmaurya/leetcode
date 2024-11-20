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
    private:
    unordered_map<TreeNode * , TreeNode *> parent;
    unordered_map<TreeNode * , bool> vis;
    void makeparent(TreeNode * root){ // fuction which will make parents pointers 
        if(root==NULL)
         return;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left){
                parent[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right]=temp;
                q.push(temp->right);
            }
        } 
    }
 TreeNode *getNode(TreeNode *root , int value){
        if(root == NULL)
          return NULL;
        if(root->val == value )
         return root;
        TreeNode *left = getNode(root->left , value);
         if(left)
          return left;
        TreeNode *right = getNode(root->right , value);
       
        return right;
  
}
public:
    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL) return 0;
        TreeNode *target = getNode(root, start);
        makeparent(root);
        queue<pair<TreeNode * , int >> q;
        q.push({target , 0});
        int ans = 0;
        while(!q.empty()){
            auto it = q.front();
            TreeNode * node = it.first;
            vis[node]= true;
            int time = it.second;
            q.pop();
            ans = max(ans,time );
            if(node->left && !vis[node->left]){
                q.push({node->left , time+1});
            }
            if(node->right && !vis[node->right]){
                q.push({node->right , time+1});
            }
            if( parent[node] && !vis[parent[node]]){
                q.push({parent[node] , time+1});
            }    
            

        }
        return ans;
        
    }
};
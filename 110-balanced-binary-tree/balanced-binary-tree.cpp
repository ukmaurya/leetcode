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
    bool isleaves(TreeNode *node){
        if(node->left || node->right){
            return false;
        }
        return true;
    }
    unordered_map<TreeNode * , int > height;
    void calHeight(TreeNode* root){
          if(root==NULL)
              return ;
          stack<pair<TreeNode* , int >> st; // node , state
          st.push({root , 1});
          while(!st.empty()){
              auto it = st.top();
              st.pop();
              if(it.second==1){
                  if(isleaves(it.first)){
                      height[it.first]=1;
                  }
                   st.push({it.first , 2});
                  if(it.first->right)
                   st.push({it.first->right,1});
                  if(it.first->left)
                    st.push({it.first->left , 1});
                 
              }
              else if(it.second==2){
                  height[it.first] = max(height[it.first->left] , height[it.first->right])+1;

              }
          }
          
    }
public:
    bool isBalanced(TreeNode* root) {
        // doing iterative 
        // steps 
        //  calculating height of each node iteratively , in postorder faision becoz lrroot
        //  check weather it is balanced or not 
         if(root==NULL)
            return true;
        calHeight(root);
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
             auto it = q.front();
             q.pop();
            int leftH = 0;
            int rightH = 0;
             if(it->left){
                q.push(it->left);
                leftH = height[it->left];
              }
              if(it->right){
                 q.push(it->right);
                 rightH = height[it->right];
              }
            if(abs(leftH-rightH) > 1)
                return false;
           }
        return true;
        
    }
};
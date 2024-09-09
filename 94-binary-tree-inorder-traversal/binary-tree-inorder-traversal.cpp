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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *cur = root;
        if(root==NULL)
         return{};
        while(cur){
            TreeNode *temp = cur->left;
            if(temp==NULL){
                ans.push_back(cur->val);
                cur = cur->right;
                
            }
            else{
                while(temp->right!=NULL && temp->right != cur){
                  temp = temp->right;
                }
              if(temp->right == NULL){
                temp->right = cur;
                cur = cur->left;
               }
             else{
                temp->right=NULL;
                   ans.push_back(cur->val);
                cur = cur->right;
              }
            }
        }
        return ans;
        
    }
};
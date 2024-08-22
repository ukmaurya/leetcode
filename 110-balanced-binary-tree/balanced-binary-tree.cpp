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
    int flag = true;
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=0;
        int right= 0;
        if(root->left){
            left = solve(root->left);
        }
        if(root->right){
            right = solve(root->right);
        }
        
        if(abs(right-left) >=2 ){
            flag = false;
        }
            
        return max(left,right)+1;    
        
    }
public:
    bool isBalanced(TreeNode* root) {
        int ans =  solve(root);
        if(flag==true)
            return true;
        return false;
    }
};
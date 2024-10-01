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
   /* int flag = true;
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
        
    } */
   int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        if(left==-1 || right==-1){ // subtree is not balanced
           return -1;
        }
        if(abs(left-right)>1){ // current node is not balanced
            return -1; 
        }
        return max(left,right)+1;//if balanced then return height
     
   }
public:
    bool isBalanced(TreeNode* root) {
        // int ans =  solve(root);
        // if(flag==true)
        //     return true;
        // return false;
        
        // without flag and pruning the recursive calls
        // we need a bool return type function but for height we need a int so , we conseder a integer value as false and true;
        int ans =  solve(root);
        if(ans==-1){
            return false;
        }
        return true;
        
    }
};
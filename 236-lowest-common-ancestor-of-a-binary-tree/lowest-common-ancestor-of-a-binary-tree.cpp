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
    TreeNode* solve(TreeNode* root , TreeNode* p , TreeNode* q){
        if(root==p || root==q || root==NULL){
            return root;
        }
        
        TreeNode *left = solve(root->left  ,p,q );
        TreeNode *right = solve(root->right , p, q);
        if(left!=NULL && right!=NULL){
            return root; 
        }
        else if(left){
            return left;
        }
        else if(right){
            return right;
        }
       return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     
         return solve(root , p , q);
    }
};
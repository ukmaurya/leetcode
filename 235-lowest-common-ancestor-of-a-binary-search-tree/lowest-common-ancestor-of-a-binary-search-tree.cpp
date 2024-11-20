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
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root == q)
           return root;
        if((root->val>p->val && root->val<q->val)||(root->val<p->val && root->val>q->val))
           return root;
        else if( root->val >  p->val)
           return solve(root->left , p , q);
        else return solve(root->right , p , q);         
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root , p , q);
    }
};
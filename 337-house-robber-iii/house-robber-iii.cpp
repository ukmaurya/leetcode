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
    vector<int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);
        int include = root->val+left[1]+right[1];
        int exclude = max(left[0],left[1] )+ max(right[1],right[0] );
        return { include,exclude};
        
        
    }
   
    
public:
    int rob(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        vector<int> ans = solve(root);
        return max(ans[0] , ans[1]); // include or exclude 
    }
};
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
    int maxi = 0;
    vector<int> solve(TreeNode *root){
        if(root==NULL){
            return {INT_MAX , INT_MIN , 0}; // min , max , sum;
        }
        vector<int>l = solve(root->left);
        vector<int>r = solve(root->right);
        vector<int> cur(3,0);
        if(root->val > l[1] && root->val < r[0]){
            cur[2] = l[2]+r[2]+root->val;
            maxi = max(maxi , cur[2]);
            cur[1] = max(r[1] , root->val);
            cur[0] = min(l[0] , root->val);
          
        }
        else{
            cur[2] = max(l[2],r[2]);
            cur[1] =INT_MAX ;
            cur[0] = INT_MIN ;
           
        }
        return cur;
    }
public:
    int maxSumBST(TreeNode* root) {
        vector<int> ans = solve(root);
        return maxi;
    }
};
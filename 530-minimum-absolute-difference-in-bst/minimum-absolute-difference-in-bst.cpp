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
    int mini = INT_MAX;
    void inorder(TreeNode* root , TreeNode*  &prev){
        if(root==NULL){
            return;
        }
        inorder(root->left , prev);
        if(prev != NULL){
            mini = min(mini , root->val-prev->val);
        }
        prev = root;
        inorder(root->right , prev);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode *prev = NULL;
       inorder(root , prev);
        
        return mini;
    }
};
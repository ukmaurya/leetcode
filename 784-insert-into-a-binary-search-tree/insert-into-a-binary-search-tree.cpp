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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
              TreeNode * temp = new TreeNode(val);
              return temp;
        }
        
        TreeNode* cur ;
        TreeNode * prev;
        cur = root;
        prev = NULL;
        while(cur){
            if(cur->val <= val){
                prev = cur;
                cur=cur->right;
            }
            else if(cur->val > val){
                prev = cur;
                cur = cur->left;
            }
        }
        TreeNode * temp = new TreeNode(val);
        if(val > prev->val){
            prev->right = temp;
        }
        else{
           
             prev->left = temp;
        }
        
        return root;
    }
};
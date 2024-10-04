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
    
    TreeNode* prev;
    TreeNode* first;
    TreeNode* mid ;
    TreeNode* last;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        if(prev != NULL){
            if(root->val < prev->val){
                if(first==NULL){
                    first = prev;
                    mid = root;
                  }
                else{
                     last = root;
                   }
             }
            
           
        }
        prev = root;
        inorder(root->right);
        
        
    }
    // prev is to track prev node visited 
    // first is to track first element of first pair
    // mid is track second element of first pair , it will be used when second pair not found which means misplaced elements are adjacent 
    //last  is used to track second pair of misplaced elements 
    
    // their will be 2 cases 
    // 1) misplaced elements are adjacent
    // 2) misplaced elements are not adjacent 
    
public:
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        first = mid = last = NULL;
        
        inorder(root);
        if(last == NULL){
            swap(first->val , mid->val);
        }
        else{
            swap(first->val , last->val);
        }
        
        return;
    }
};
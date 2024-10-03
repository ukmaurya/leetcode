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
    private:
    int findsucc(TreeNode* cur){
        if(cur==NULL)
         return -1;
        // inorder succ can have either one chile or no child 
        TreeNode *prev = cur;
        cur= cur->right;
        while(cur->left){
            prev= cur;
            cur= cur->left;
        }
        if(!cur->left && !cur->right){ // if(succ is leaf)
             if(cur==prev->left){
                prev->left=NULL;
                int value = cur->val;
                delete(cur);
                return value;
             }
             else{
                 prev->right=NULL;
                int value = cur->val;
                 delete(cur);
                return value;
             }
        }
        else{ // if succ have one child 
             if(cur==prev->left){
                if(cur->left){
                   prev->left = cur->left;
                }
                else{
                   prev->left = cur->right;
                }
                int value = cur->val;
                delete(cur);
                return value;
             }
             else{
                  if(cur->left){
                   prev->right = cur->left;
                  }
                else{
                   prev->right= cur->right;
                } 
                 
                int value = cur->val;
                 delete(cur);
                return value;
             }
        }

    }
    TreeNode *deleteRootNode(TreeNode *cur){
         if(cur == NULL)
          return cur;
          
         //case 1: cur have no child 
         if(!cur->left && !cur->right){
            delete(cur);
            return NULL;
         } 
         else if(cur->left && cur->right){ // case 2 :have both child
            
            int succ = findsucc(cur); // find succ key and delete succ 
            cur->val = succ;
            return cur;
         }
         else{ // case 3: only one child 
                TreeNode *temp = (cur->left)?cur->left :cur->right;
                delete(cur);
                return temp;
         }

    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        // iterative solution 
        //step 1 : find the target node 
        // if(root==NULL )
        //  return NULL;
        // TreeNode* prev = NULL;
        // TreeNode *cur = root;
        // while(cur && cur->val != key ){
        //     prev = cur;
        //     if(cur->val<key){
        //         cur = cur->right;
        //      }
        //     else{
        //         cur= cur->left;
        //     }
        // }
        // // now cur is pointing to key 
        // if(prev == NULL){
        //     return deleteRootNode(cur);
        // }
        // else if(prev->left ==cur){
        //     prev->left = deleteRootNode(cur);
        // }
        // else{
        //     prev->right = deleteRootNode(cur);
        // }
        // return root;
       
        // using recursion 
        
         if(root==NULL){
             return NULL;
         }
       return solve(root , key);
        
    }
    TreeNode* findmin(TreeNode* root,int key){
        while(root->left!=nullptr){
            root=root->left;
        }
        return root;
    }
    
    
    TreeNode* solve(TreeNode* root, int key) {
        if(root==nullptr){
            return root;
        }

        if(root->val<key){
            root->right=solve(root->right,key);
        }
        else if(root->val>key){
            root->left=solve(root->left,key);
        }
        else{
            if(root->left==NULL){
                struct TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                struct TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else{
                struct TreeNode* temp=findmin(root->right,key);
                root->val=temp->val;
                root->right=solve(root->right,temp->val);
            }
        }
        return root;
    }
    
};
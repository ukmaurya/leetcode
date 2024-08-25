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
     int findHeightLeft(TreeNode* node) {
        int height = 0;
        // Traverse left child until
        // reaching the leftmost leaf
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
     int findHeightRight(TreeNode* node) {
        int height = 0;
        // Traverse right child until
        // reaching the rightmost leaf
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
    
public:
  /*  int countNodes(TreeNode* root) {
        // Base case: If the root
        // is NULL, there are no nodes
        if (root == NULL) {
            return 0;
        }
        
        // Find the left height and
        // right height of the tree
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        
        // Check if the last level
        // is completely filled
        if (lh == rh) {
            // If so, use the formula for
            // total nodes in a perfect
            // binary tree ie. 2^h - 1
            return (1 << lh) - 1; 
        }
        
        // If the last level is not completely
        // filled, recursively count nodes in
        // left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    } */
    
    int countNodes(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int ans = 0;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            
              int size = q.size();
              ans += size;
              for(int i=0;i<size;i++){
                  auto it = q.front();
                  q.pop();
                  if(it->left)
                    q.push(it->left);
                  if(it->right)
                    q.push(it->right);
              }
            
        }
        return ans;
    }
};
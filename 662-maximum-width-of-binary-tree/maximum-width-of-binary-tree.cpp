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
    int widthOfBinaryTree(TreeNode* root) {
        // we need to check for each level => level order traversal 
        // we will index to each node 
        if(root==NULL)
         return 0;
        queue<pair<TreeNode * , int >> q; // node , index 
        q.push({root , 0});
        long long  maxi = 0;

        while(!q.empty()){
            int size = q.size();
            long long  first = 0;
            long long  last =0;
            long long min_index = q.front().second;
            for(int i=0;i<size;i++){
                
                if(i==0){
                  first = q.front().second-min_index;
                }
                else if(i==size-1){
                    last = q.front().second-min_index;
                }
                TreeNode *temp = q.front().first;
               long long index = q.front().second-min_index; // so that indexing at each level begins from 0;
                if(temp->left)
                  q.push({temp->left ,2*index });
                if(temp->right){
                    q.push({temp->right ,2*index+1});
                }  
                q.pop();
             }
            maxi = max(maxi , last-first+1 );

        } 
        return maxi;
    }
};
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
    TreeNode* solve(vector<int>&postorder,int pe , vector<int>&inorder,int ins ,int ine,unordered_map<int,int> &mp){
        if(pe<0 || ins>ine)
          return NULL;
        TreeNode* root= new TreeNode(postorder[pe]);
        int index = mp[postorder[pe]]; // getting index in constant time 
        int num = ine-index; // number of nodes in right subtree

        root->left = solve(postorder,pe-num-1,inorder,ins,index-1,mp);
        root->right = solve(postorder,pe-1,inorder,index+1,ine,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return solve(postorder ,postorder.size()-1, inorder,0,n-1,mp);
    }
};
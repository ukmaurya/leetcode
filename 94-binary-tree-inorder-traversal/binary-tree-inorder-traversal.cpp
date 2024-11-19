/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;
        while (cur) {
            TreeNode* temp = cur->left;
            if (temp) {
                while (temp->right != cur && temp->right) {
                    temp = temp->right;
                }
                if(temp->right== cur){ // visiting second time 
                    ans.push_back(cur->val);
                    temp->right= NULL;
                    cur = cur->right;
                }
                else{
                    temp->right=cur;
                    cur = cur->left;
                }
            } else {
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }

        return ans;
    }
};
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
class BSTIterator {
    int index = 0;
    vector<int> inorder;
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        solve(root->left);
        inorder.push_back(root->val);
        solve(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        int ele = inorder[index];
        index++;
        return ele;
    }
    
    bool hasNext() {
        if(index<inorder.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
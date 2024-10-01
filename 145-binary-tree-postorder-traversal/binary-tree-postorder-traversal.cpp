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
    vector<int> postorderTraversal(TreeNode* root) {
        
        // using one stack 
        stack<pair<TreeNode*,int>> st;
        if(root==NULL){
            return {};
        }
        st.push({root,0});
        vector<int> ans;
        while(!st.empty()){
            auto t = st.top();
            st.pop();
            if(t.second==1){ // 1 is representing that is left and right children is visited 
                ans.push_back(t.first->val);
            }
            else{
                st.push({t.first , 1});
                if(t.first->right){
                    st.push({t.first->right , 0});
                }
                if(t.first->left){
                    st.push({t.first->left , 0});
                }
                
            }
            
            
        }
        return ans;
        
    }
};
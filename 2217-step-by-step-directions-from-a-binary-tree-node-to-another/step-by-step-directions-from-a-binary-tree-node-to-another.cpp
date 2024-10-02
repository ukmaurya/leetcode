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
// class Solution {
//     void getParent(TreeNode* root , unordered_map<TreeNode* , TreeNode*>&parent){
//         if(root==NULL){
//             return;
//         }
//         if(root->left){
//             parent[root->left]= root;
//             getParent(root->left , parent);
//         }
//         if(root->right)
//         {
//             parent[root->right]=root;
//             getParent(root->right , parent);
//         } 
//         return ;
    
//     }
//     TreeNode* findTarget(TreeNode* root , int target){
//         if(root==NULL){
//             return NULL;
//         }
//         if(root->val==target){
//             return root;
//         }
//         TreeNode* left = findTarget(root->left , target);
//         TreeNode* right = findTarget(root->right , target);
//         if(left!= NULL){
//             return left;
//         }
//         else if(right!=NULL){
//             return right;
//         }
//         return NULL;
//     }
// public:
//    // string getDirections(TreeNode* root, int startValue, int destValue) {
//         // unordered_map<TreeNode* , TreeNode*> parent;
//         // parent[root]=NULL;
//         // getParent(root , parent);
//         // unordered_map<TreeNode* , bool> vis;
//         // TreeNode* start = findTarget(root , startValue);
//         // TreeNode* end = findTarget(root , destValue);
//         // queue<pair<TreeNode* , string>> q;
//         // q.push({start , ""});
//         // vis[start]=true;
//         // string ans ="";
//         // while(!q.empty()){
//         //     auto it = q.front();
//         //     if(it.first == end){
//         //         return it.second;
//         //     }
//         //     q.pop();
//         //     if(it.first->left && vis[it.first->left ]==false){
//         //         vis[it.first->left ]=true;
//         //         q.push({it.first->left , it.second+'L'});
//         //     }
//         //     if(it.first->right&& vis[it.first->right]==false){
//         //         vis[it.first->right ]==true;
//         //          q.push({it.first->right , it.second+'R'});
//         //     }
//         //     if(parent[it.first]!=NULL&&vis[parent[it.first]]==false ){
//         //         vis[parent[it.first]]=true;
//         //         q.push({parent[it.first] , it.second+'U'});
//         //     }
//         // }
        
//         // return ans;


//         // above approach was using bfs after making parent pointers but it is giving TLE on some test cases

//             TreeNode* start = findTarget(root , startValue);
//             TreeNode* end = findTarget(root , destValue);
//             TreeNode *lca = findLCA(root , start , end);
//             string l ="";
//             lcaToStart(lca , start, l);
//             string r = "";
//             lcaToEnd(lca , end,"", r);
//             return l+r;

//     }
//     TreeNode* findLCA(TreeNode* root , TreeNode* start , TreeNode* end){
//                if(root==start || root==end || root==NULL){
//                 return root;
//                }
//                TreeNode *left = findLCA(root->left ,start , end);
//                TreeNode* right = findLCA(root->right , start , end);
//                if(left && right){
//                 return root;
//                }
//                if(left){
//                 return left;
//                }
//                if(right){
//                 return right;
//                }
//                return NULL;
//     }
//     void  lcaToStart(TreeNode* root , TreeNode* target , string &s , string &temp){
//         if(root==NULL){
//             return ;
//         }
//         if(root==target){
//             temp = s;
//             return ;
//         }
//          lcaToStart(root->left , target , s+'U' , temp);
//         lcaToStart(root->right , target , s+'U' , temp);
//         return ;

//     }
//     void  lcaToEnd(TreeNode* root , TreeNode* target , string s , string &temp){
//         if(root==NULL){
//             return ;
//         }
//         if(root==target){
//             temp = s;
//             return ;
//         }
//         lcaToEnd(root->left , target , s+'L' , temp);
//         lcaToEnd(root->right , target , s+'R' , temp);
//         return ;

//     }
// };


class Solution {
public:
    bool findPath(TreeNode*& root, int target, string& path){
       if(root==nullptr) return false;

       if(root->val==target){
          return true;
       } 
       
       path.push_back('L');
       if(findPath(root->left, target, path)==true) return true;

       path.pop_back();

       path.push_back('R');
       if(findPath(root->right, target, path)==true) return true;

       path.pop_back();

       return false;
    }
    
 

    string getDirections(TreeNode* root, int startValue, int destValue) {

        string LCAToStart = "";
        string LCAToDest = "";

        findPath(root, startValue, LCAToStart);
        findPath(root, destValue, LCAToDest);

        int i =0; int j=0;  string ans = "";
        while(i<LCAToStart.length() && j<LCAToDest.length() && LCAToStart[i]==LCAToDest[j]){
            i++; j++;
        }

        while(i<LCAToStart.length()){
            ans+='U'; i++;
        }

        while(j<LCAToDest.length()){
            ans+=LCAToDest[j]; j++;
        }

        return ans;


       
    }
};
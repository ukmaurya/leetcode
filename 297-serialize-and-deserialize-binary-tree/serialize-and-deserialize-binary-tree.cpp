/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    // Helper function for preorder serialization
    void preorder(TreeNode* root, string& temp) {
        if (root == nullptr) {
            temp += "#,"; // Add null marker with a delimiter
            return;
        }
        temp += to_string(root->val) + ","; // Add value with a delimiter
        preorder(root->left, temp);
        preorder(root->right, temp);
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string temp = "";
        preorder(root, temp);
        return temp;
    }

    // Helper function for deserialization
    TreeNode* solve(int& idx, vector<string>& nodes) {
        if (idx >= nodes.size() || nodes[idx] == "#") {
            idx++; // Move past null marker
            return nullptr;
        }
        // Create node with the integer value
        TreeNode* node = new TreeNode(stoi(nodes[idx]));
        idx++; // Move to the next value
        node->left = solve(idx, nodes); // Build left subtree
        node->right = solve(idx, nodes); // Build right subtree
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp = "";
        // Split the string by ',' to extract individual values
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) nodes.push_back(temp); // Add the last value

        int idx = 0;
        return solve(idx, nodes);
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
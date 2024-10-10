#include <vector>
#include <string>
#include <unordered_set>

class Node {
    vector<Node*> links; // Store pointers to Nodes
    bool flag;

public:
    Node() : links(26, nullptr), flag(false) {} // Initialize with 26 null pointers
    
    bool iskey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    Node* getkey(char ch) {
        return links[ch - 'a'];
    }

    void addkey(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    Node* root;
    
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->iskey(ch)) {
                node->addkey(ch, new Node());
            }
            node = node->getkey(ch);
        }
        node->setEnd();
    }

    Node* getRoot() {
        return root;
    }
};

class Solution {
    unordered_set<string> uniqueResults; // Use a set to store unique results
    int n, m;

    void dfs(int row, int col, vector<vector<char>>& board, Node* node, string path, vector<vector<bool>>& visited) {
        // Base case: if we reach a node that is an end of a word
        if (node->isEnd()) {
            uniqueResults.insert(path); // Insert into the set
        }

        // Directions for moving in the board: right, down, left, up
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int k = 0; k < 4; k++) {
            int newRow = row + dx[k];
            int newCol = col + dy[k];

            // Check bounds and if cell is already visited
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol]) {
                char nextChar = board[newRow][newCol];
                if (node->iskey(nextChar)) {
                    visited[newRow][newCol] = true;
                    dfs(newRow, newCol, board, node->getkey(nextChar), path + nextChar, visited);
                    visited[newRow][newCol] = false; // backtrack
                }
            }
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();

        Trie tri;
        for (string& word : words) {
            tri.insert(word);
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // Search each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char startChar = board[i][j];
                if (tri.getRoot()->iskey(startChar)) {
                    visited[i][j] = true;
                    dfs(i, j, board, tri.getRoot()->getkey(startChar), string(1, startChar), visited);
                    visited[i][j] = false; // backtrack
                }
            }
        }

        // Convert the set to a vector and return
        return vector<string>(uniqueResults.begin(), uniqueResults.end());
    }
};

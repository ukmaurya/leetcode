class Solution {
public:
    string smallestBeautifulString(string s, int k) {
      int n = s.size();
    string original = s;
    bool isImpossible = true;

    // Start from the end of the string, moving backward
    for (int i = n - 1; i >= 0; i--) {
        bool canConstruct = true;
        
        // Attempt to build a valid beautiful string from position `i` onward
        for (int j = i; j < n; j++) {
            char minChar = 'a';
            if (j == i) {
                minChar = s[i] + 1; // Increment character for the current position
            }
            bool charFound = false;
            
            // Find the smallest character that avoids repetition conflicts
            for (char c = minChar; c <= ('a' + k - 1); c++) {
                if ((j == 0 || s[j - 1] != c) && (j <= 1 || s[j - 2] != c)) {
                    s[j] = c;
                    charFound = true;
                    break;
                }
            }
            
            // If no suitable character was found, move to the next position
            if (!charFound) {
                canConstruct = false;
                break;
            }
        }

        // If successful in constructing a beautiful string, break
        if (canConstruct) {
            isImpossible = false;
            break;
        } else {
            // Restore original characters in the current segment if construction failed
            for (int l = i; l < min(n, i + 2); l++) {
                s[l] = original[l];
            }
        }
    }

    // Return empty string if no valid construction was found
    if (isImpossible) return "";
    return s;
    }
};
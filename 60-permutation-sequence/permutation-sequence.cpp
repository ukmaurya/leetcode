class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) {
        return "1";
    }
    
    vector<int> vec;
    vec.push_back(-1); // dummy to make one-based indexing
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
        fact *= i;
    }

    // Adjust k to be zero-based index
    k--;

    string ans = "";
    fact /= n;  // Now fact is (n-1)!

    while (ans.size() != n) {
        int index = k / fact;  // Find the position in vec
        ans += to_string(vec[index + 1]);  // Add the selected number
        vec.erase(vec.begin() + index + 1);  // Remove the selected number

        if (vec.size() == 2) {  // If only one element left, append it
            ans += to_string(vec[1]);
            break;
        }

        k %= fact;  // Update k for next round
        fact /= (n - ans.size());  // Decrease factorial for next iteration
    }

    return ans;
    }
};
class Solution {
#define ll long long
    multiset<ll> low, high;
    int k;
    void insertion(int val) {
        if (low.empty()) {
            low.insert(val);
            return;
        }
        int curMedian = *low.rbegin();
        if (val > curMedian) { // it will go to second multiset as it is greater
                               // than CURRENT median
            high.insert(val);
            if (high.size() > k / 2) {
                low.insert(*high.begin());
                high.erase(high.begin());
            }
        } else {
            low.insert(val);
            if (low.size() > (k + 1) / 2) {
                high.insert(*low.rbegin());
                low.erase(low.find(*low.rbegin()));
            }
        }
    }
    void deletion(int val) {
        if (low.find(val) != low.end()) {
            low.erase(low.find(val));
        } else {
            high.erase(high.find(val));
        }
        if (low.size() < k / 2) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }

public:
    vector<double> medianSlidingWindow(vector<int>& arr, int windowSize) {

        vector<double> ans;
        int n = arr.size();
        k = windowSize;
        for (int i = 0; i < k; i++) {
            insertion(arr[i]); // insertion into multisets
        }
        // cout<<*low.rbegin()<<" ";
        if (k & 1) {
            ans.push_back(*low.rbegin());
        } else {
            double temp = (*low.rbegin() + *high.begin()) / 2.0;
            ans.push_back(temp);
        }

        for (int i = k; i < n; i++) { // for each window
            deletion(arr[i - k]);
            insertion(arr[i]);
            if (k & 1) {
                ans.push_back(*low.rbegin());
            } else {
                double temp = (*low.rbegin() + *high.begin()) / 2.0;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
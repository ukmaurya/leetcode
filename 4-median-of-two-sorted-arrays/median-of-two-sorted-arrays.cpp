class Solution {
    int countnum(const vector<int>& nums, int mid) {
        // Count how many elements are less than or equal to mid
        return upper_bound(nums.begin(), nums.end(), mid) - nums.begin();
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int start = min(nums1.empty() ? INT_MAX : nums1[0], nums2.empty() ? INT_MAX : nums2[0]);
        int end = max(nums1.empty() ? INT_MIN : nums1.back(), nums2.empty() ? INT_MIN : nums2.back());
        int total = n + m;

        // Find the first middle element (for odd and even cases)
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int count1 = countnum(nums1, mid);
            int count2 = countnum(nums2, mid);

            if (count1 + count2 < (total + 1) / 2) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        int left = start;

        // If total is odd, the median is the middle element
        if (total % 2 == 1) {
            return left;
        }

        // Find the next middle element for the even case
        start = min(nums1.empty() ? INT_MAX : nums1[0], nums2.empty() ? INT_MAX : nums2[0]);
        end = max(nums1.empty() ? INT_MIN : nums1.back(), nums2.empty() ? INT_MIN : nums2.back());

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int count1 = countnum(nums1, mid);
            int count2 = countnum(nums2, mid);

            if (count1 + count2 <= total / 2) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        int right = start;

        // Return the average of the two middle elements for even total elements
        return (left + right) / 2.0;
    }
};

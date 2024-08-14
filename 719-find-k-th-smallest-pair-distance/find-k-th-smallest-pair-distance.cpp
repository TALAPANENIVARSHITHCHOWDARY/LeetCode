#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // Sort the array
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int left = 0; // Minimum possible distance
        int right = nums[n - 1] - nums[0]; // Maximum possible distance

        // Binary search on the distance
        while (left < right) {
            int mid = left + (right - left) / 2;

            // Count how many pairs have distance <= mid
            int count = 0, j = 0;
            for (int i = 0; i < n; i++) {
                while (j < n && nums[j] - nums[i] <= mid) {
                    j++;
                }
                count += j - i - 1;
            }

            // If the count is >= k, it means the k-th smallest distance is <= mid
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // The smallest distance that has at least k pairs is `left`
        return left;
    }
};

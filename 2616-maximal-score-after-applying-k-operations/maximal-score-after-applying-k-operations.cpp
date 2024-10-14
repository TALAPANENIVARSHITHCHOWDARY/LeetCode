#include <queue>
#include <vector>
#include <cmath>

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        // Create a max-heap (priority queue) using a min-heap with negative values
        std::priority_queue<int> pq(nums.begin(), nums.end());
        long long sum = 0;

        for (int i = 0; i < k; ++i) {
            int top = pq.top();  // Get the largest element
            pq.pop();
            sum += top;  // Add it to the score
            pq.push(ceil(top / 3.0));  // Replace it with ceil(top / 3)
        }

        return sum;
    }
};

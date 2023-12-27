class Solution {
public:
    int minimumRightShifts(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());
        for (int shifts = 0; shifts < n; ++shifts) {
            bool sorted = true;
            for (int i = 0; i < n; ++i) {
                if (nums[i] != sorted_nums[i]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) {
                return shifts;
            }
            int last = nums[n - 1];
            for (int i = n - 1; i > 0; --i) {
                nums[i] = nums[(i - 1 + n) % n];
            }
            nums[0] = last;
        }
        return -1;
    }
};

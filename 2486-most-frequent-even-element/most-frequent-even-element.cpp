class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        nums.erase(remove_if(nums.begin(), nums.end(), [](int num) { return num % 2 != 0; }), nums.end());
        if (nums.empty())
            return -1;
        int mode = 1, modele = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            int count = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[i] == nums[j])
                    count++;
            }
            if (mode < count) {
                mode = count;
                modele = nums[i];
            } else if (mode == count) {
                modele = std::min(modele, nums[i]);
            }
        }
        return modele;
    }
};

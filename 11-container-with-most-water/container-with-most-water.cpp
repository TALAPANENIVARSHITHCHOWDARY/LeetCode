class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int h = height[left] < height[right] ? height[left] : height[right];
            int w = right - left;
            int currentArea = h * w;
            maxArea = maxArea < currentArea ? currentArea : maxArea;
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};

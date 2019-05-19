#include <algorithm>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, currArea;
        int left = 0, right = height.size() - 1, temp;
        while (left < right) {
            currArea = (right - left) * min(height[left], height[right]);
            maxArea = max(maxArea, currArea);
            if (height[left] < height[right]) {
                temp = left;
                while (temp < right && height[temp] <= height[left]) {
                    ++temp;
                }
                left = temp;
            } else {
                temp = right;
                while (left < temp && height[temp] <= height[right]) {
                    --temp;
                }
                right = temp;
            }
        }
        return maxArea;
    }
};
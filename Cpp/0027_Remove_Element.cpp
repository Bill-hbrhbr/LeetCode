class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto length = nums.size();
        decltype(length) index = 0;
        while (index != length) {
            if (nums[index] ==  val) {
                nums.erase(nums.begin() + index);
                --length;
            } else {
                ++index;
            }
        }
        return length;
    }
};
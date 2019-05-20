/* O(nlog(k)) Algorithm
 * O(n) extra space
 * Runtime: 56ms beats 97.34% of C++ submissions
 * Memory Usage: beats 59.09% of C++ submissions (didn't use deque)
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return {};
        }
        int index, stackBegin = 0, stackEnd = -1;
        vector<int> indices(nums.size());
        vector<int> result;
        for (index = 0; index < nums.size(); ++index) {
            binaryInsert(nums, indices, stackBegin, stackEnd, index, nums[index]);
            if (indices[stackBegin] + k <= index) {
                ++stackBegin;
            }
            if (index + 1 >= k) {
                result.push_back(nums[indices[stackBegin]]);
            }
        }
        return result;
    }
private:
    void binaryInsert(vector<int> &nums, vector<int> &indices, int &stackBegin,
                      int &stackEnd, int &curIndex, int &curVal) {
        int left = stackBegin, right = stackEnd, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[indices[mid]] == curVal) {
                stackEnd = mid;
                indices[mid] = curIndex;
                return;
            }
            if (nums[indices[mid]] > curVal) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left == right) {
            if (nums[indices[left]] <= curVal) {
                stackEnd = left; 
            } else {
                stackEnd = left + 1;
            }
        } else {
            stackEnd = left;
        }
        indices[stackEnd] = curIndex;
    }
};
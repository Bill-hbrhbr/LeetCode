/* O(log(m+n)) Solution
 * Uses binary search
 * not entirely correct, passed 2073/2084 tests
 */
#include <algorithm>
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int sum = nums1.size() + nums2.size();
        if (sum < 100) {
            vector<int> combine;
            int index1 = 0;
            int index2 = 0;
            while (index1 < nums1.size() && index2 < nums2.size()) {
                if (nums1[index1] < nums2[index2]) {
                    combine.push_back(nums1[index1]);
                    ++index1;
                } else {
                    combine.push_back(nums2[index2]);
                    ++index2;
                }
            }
            while (index1 < nums1.size()) {
                combine.push_back(nums1[index1]);
                ++index1;
            }
            while (index2 < nums2.size()) {
                combine.push_back(nums2[index2]);
                ++index2;
            }
            if (sum % 2 == 1) {
                return combine[sum / 2];
            } else {
                return 0.5 *(combine[sum / 2 - 1] + combine[sum / 2]);
            }
        }
        if (nums1.size() > nums2.size()) {
            return helper(nums1, nums2);
        } else {
            return helper(nums2, nums1);
        }
    }
    
    double helper(vector<int> &v1, vector<int> &v2) {
        int low1 = 0, low2 = 0, high1 = v1.size() - 1, high2 = v2.size() - 1;
        int sum1, sum2, left1, left2, right1, right2;
        while (high2 - low2 > 1) {
            sum1 = low1 + high1;
            sum2 = low2 + high2;
            if (sum1 % 2 == 0) {
                left1 = sum1 / 2 - 1;
                right1 = left1 + 2;
            } else {
                left1 = sum1 / 2 - 1;
                right1 = left1 + 3;
            }
            if (sum2 % 2 == 0) {
                left2 = sum2 / 2 - 1;
                right2 = left2 + 2;
            } else {
                left2 = sum2 / 2 - 1;
                right2 = left2 + 3;
            }
            if (v1[left1] <= v2[right2]) {
                int skip = high2 - right2 + 1;
                high2 -= skip;
                low1 += skip;
            }
            if (v1[right1] >= v2[left2]) {
                int skip = left2 - low2 + 1;
                low2 += skip;
                high1 -= skip;
            }
        }
        if (high2 - low2 == 0) {
            v2.push_back(v1[v1.size() - 1]);
            v1.pop_back();
            ++high2;
            --high1;
            if (v2[low2] > v2[high2]) {
                int temp = v2[low2];
                v2[low2] = v2[high2];
                v2[high2] = temp;
            }
        }
        int index1 = locate(v1, v2[low2], low1, high1);
        int index2 = locate(v1, v2[high2], low1, high1) + 1;
        int front = index1 - low1;
        int back = high1 + 2 - index2;
        int center = index2 - index1 - 1;
        int skip = (low1 + high1) / 2 + 1 - low1;
        if ((low1 + high1) % 2 == 0) {
            if (front > skip) {
                return v1[low1 + skip];
            } else if (front == skip) {
                return v2[low2];
            }
            skip -= front + 1;
            if (center > skip) {
                return v1[low1 + front + skip];
            } else if (center == skip) {
                return v2[high2];
            }
            skip -= center + 1;
            return v1[low1 + front + center + skip];
        } else {
            if (front > skip + 1) {
                return (v1[low1 + skip] + v1[low1 + skip + 1]) / 2.0;
            } else if (front == skip + 1) {
                return (v1[low1 + skip] + v2[low2]) / 2.0;
            } else if (front == skip) {
                if (center == 0) {
                    return (v2[low2] + v2[high2]) / 2.0;
                } else {
                    return (v2[low2] + v1[low1 + front]) / 2.0;
                }
            }
            skip -= front + 1;
            if (center > skip + 1) {
                return (v1[low1 + front + skip] + v1[low1 + front + skip + 1]) / 2.0;
            } else if (center == skip + 1) {
                return (v1[low1 + front + skip] + v2[high2]) / 2.0;
            } else if (center == skip) {
                return (v2[high2] + v1[low1 + front + center]) / 2.0;
            }
            skip -= center + 1;
            return (v1[low1 + front + center + skip] + v1[low1 + front + center + skip + 1]) / 2.0;
        }
    }
private:
    int locate(vector<int> &v, int value, int left, int right) {
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (v[mid] == value) {
                return mid;
            } else if (v[mid] > value) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left == right) {
            if (v[left] >= value) {
                return left;
            } else {
                return left + 1;
            }
        } else {
            return left;
        }
    }
};
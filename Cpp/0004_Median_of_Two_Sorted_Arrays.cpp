/* O(n) correct solution
 * No binary search
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int index1 = 0, index2 = 0, count = 0;
        int size1 = nums1.size(), size2 = nums2.size();
        int sum = size1 + size2, mid = (sum - 1) / 2;
        while (count < mid) {
            ++count;
            findNext(nums1, nums2, index1, index2, size1, size2);
        }
        int mid1 = findNext(nums1, nums2, index1, index2, size1, size2);
        if (sum % 2 == 1) {
            return mid1;
        }
        int mid2 = findNext(nums1, nums2, index1, index2, size1, size2);
        return (mid1 + mid2) / 2.0;
    }
private:
    int findNext(vector<int> &nums1, vector<int> &nums2, int &index1, 
                 int &index2, int &size1, int &size2) {
        if (index1 >= size1) {
            return nums2[index2++];
        } else if (index2 >= size2) {
            return nums1[index1++];
        } else {
            if (nums1[index1] < nums2[index2]) {
                return nums1[index1++];
            } else {
                return nums2[index2++];
            }
        }
    }
};
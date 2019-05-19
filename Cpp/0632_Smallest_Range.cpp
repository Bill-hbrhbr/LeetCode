/* O(n * log(k)) Solution
 * Beats 98.81% of C++ submissions
 */
class Solution {
public:
    #define EOL 100001 // End of list
    vector<int> smallestRange(vector<vector<int>> &nums) {
        int k = nums.size();
        for (auto &list: nums) {
            list.push_back(EOL);
        }
        vector<int> indices(k, 0);
        vector<int> listHeap(k + 1);
        for (int i = 0; i < k; ++i) {
            listHeap[k - i] = i;
            bubbleDown(listHeap, nums, indices, k - i, k);
        }
        int first = nums[listHeap[1]][0], second = first;
        for (int i = (k + 1) / 2; i <= k; ++i) {
            if (nums[listHeap[i]][0] > second) {
                second = nums[listHeap[i]][0];
            }
        }
        int minInterval = second - first, minFirst = first, minSecond = second;
        while (true) {
            ++indices[listHeap[1]];
            int newVal = nums[listHeap[1]][indices[listHeap[1]]];
            if (newVal == EOL) {
                return {minFirst, minSecond};
            } else if (newVal > second) {
                second = newVal;
            }
            bubbleDown(listHeap, nums, indices, 1, k);
            first = nums[listHeap[1]][indices[listHeap[1]]];
            if (second - first < minInterval) {
                minFirst = first;
                minSecond = second;
                minInterval = second - first;
            }
        }
        return {minFirst, minSecond};
    }

private:
    void bubbleDown(vector<int> &heap, vector<vector<int>> &nums,
                    vector<int> &indices, int i, int k) {
        if (i * 2 > k) {
            return;
        }
        int top, left, right;
        while (i * 2 < k) {
            top = nums[heap[i]][indices[heap[i]]];
            left = nums[heap[i * 2]][indices[heap[i * 2]]];
            right = nums[heap[i * 2 + 1]][indices[heap[i * 2 + 1]]];
            if (top <= left && top <= right) {
                return;
            } else if (left < right) {
                swap(heap, i, i * 2);
                i = i * 2;
            } else {
                swap(heap, i, i * 2 + 1);
                i = i * 2 + 1;
            }
        }
        if (i * 2 == k) {
            if (nums[heap[i]][indices[heap[i]]] > nums[heap[k]][indices[heap[k]]]) {
                swap(heap, i, k);
            }
        }
    }
    void swap(vector<int> &heap, int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
};
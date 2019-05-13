class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector <int> result;
        while (true) {
            while (left <= right && numbers[left] + numbers[right] < target)
                left++;
            while (right >= left && numbers[left] + numbers[right] > target)
                right--;
            if (numbers[left] + numbers[right] == target && left <= right) {
                result.push_back(left + 1);
                result.push_back(right + 1);
                return result;
            } else if (left > right) {
                return result;
            }
        }
    }
};
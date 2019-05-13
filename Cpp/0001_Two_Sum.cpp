class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        typedef vector<int> List;
        auto length = nums.size();
        List result;
        vector<List> hashTable(length);
        for (auto iter = nums.begin(); iter != nums.end(); iter++) {
            int comp = (target - *iter) % length;
            for (auto it = hashTable[comp].begin(); it != hashTable[comp].end(); it++) {
                if (nums[*it] + *iter == target) {
                    result.push_back(*it);
                    result.push_back(iter - nums.begin());
                    return result;
                }
            }
            hashTable[*iter % length].push_back(iter - nums.begin());
        }
        return result;
    }
};
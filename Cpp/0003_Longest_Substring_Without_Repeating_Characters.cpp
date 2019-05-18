class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256, 0);
        unsigned curCount = 0, curMax = 0, index = 0, firstIndex = 0;
        for (; index < s.size(); ++index) {
            unsigned ascii = static_cast<unsigned> (s[index]);
            ++count[ascii];
            ++curCount;
            while (count[ascii] > 1) {
                --count[static_cast<unsigned> (s[firstIndex])];
                ++firstIndex;
                --curCount;
            }
            curMax = curCount > curMax ? curCount : curMax;
        }
        return curMax;
    }
};
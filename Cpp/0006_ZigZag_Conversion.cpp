#include <cstdlib>
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        vector<string> stringRow(numRows);
        int x, index = 0, groupSize = (numRows - 1) * 2, length = s.size();
        while (index < length) {
            x = index % groupSize;
            x = abs(numRows - 1 - x);
            stringRow[numRows - 1 - x] += s[index];
            ++index;
        }
        string returnStr;
        for (auto iter = stringRow.cbegin(); iter != stringRow.cend(); ++iter) {
            returnStr += *iter;
        }
        return returnStr;
    }
};
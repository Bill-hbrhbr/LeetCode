/* Dynamic Programming O(n2) Solution
 * Runtime: 72ms, beats 82.63% C++ solutions
 * Memory Usage: 8.9MB, beats 95.63% C++ solutions
 */
#include <algorithm>
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int length = s.size();
        if (length == 0) {
            return 0;
        }
        vector<int> dp_1(length, 1); // substring length shorter by 1
        vector<int> dp_2(length, 0); // substring length shorter by 2
        vector<int> dp_new(length);
        int block, i , j;
        for (block = 2; block <= length; ++block) {
            for (i = 0; i + block <= length; ++i) {
                j = i + block - 1;
                dp_new[i] = max(dp_1[i], dp_1[i + 1]);
                if (s[i] == s[j]) {
                    dp_new[i] = max(dp_new[i], dp_2[i + 1] + 2);
                }    
            }
            dp_2.pop_back();    // Trim the dp array for larger blocks
            dp_1.pop_back();
            dp_new.pop_back();
            dp_2 = dp_1;
            dp_1 = dp_new;
        }
        return dp_1[0];
    }
};
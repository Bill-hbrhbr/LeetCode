#include <algorithm>
class Solution {
public:
    string intToRoman(int num) {
        vector<char> letter{'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int mark = 0, digit;
        string result;
        while (num > 0) {
            digit = num % 10;
            num /= 10;
            if (digit == 4) {
                result += letter[mark + 1];
                result += letter[mark];
            } else if (digit == 9) {
                result += letter[mark + 2];
                result += letter[mark];
            } else {
                switch (digit) {
                    case 3: case 8: result += letter[mark];
                    case 2: case 7: result += letter[mark];
                    case 1: case 6: result += letter[mark];
                    default:
                        break;
                }
                if (digit >= 5) {
                    result += letter[mark + 1];
                }
            }
            mark += 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
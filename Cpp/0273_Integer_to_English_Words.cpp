class Solution {
public:
    string under1000(int a, int b, int c) {
        string result;
        result += digits[a];
        a > 0 ? result += " Hundred" : dummy;
        if (b == 1) {
            a > 0 ? result += ' ' : dummy;
            result += under20[c];
        } else {
            a > 0 && b > 0 ? result += ' ': dummy;
            result += tens[b];
            (a > 0 || b > 0) && c > 0 ? result += ' ': dummy;
            result += digits[c];
        }
        return result;
    }
    
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string result;
        vector<int> digits;
        int count = 0;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
            ++count;
        }
        while (count % 3 != 0) {
            digits.push_back(0);
            ++count;
        }
        while (count > 0) {
            if (!(digits[count - 1] || digits[count - 2] || digits[count - 3])) {
                count -= 3;
                continue;
            } else if (count < digits.size()) {
                result += ' ';
            }
            result += under1000(digits[count - 1], digits[count - 2], digits[count - 3]);
            count -= 3;
            count > 0 ? result += ' ' : dummy;
            result += triple[count / 3];
        }
        return result;
    }
private:
    vector<string> digits{"", "One", "Two", "Three", "Four", 
                          "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> under20{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                           "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty",
                        "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> triple{"", "Thousand", "Million", "Billion"};
    string dummy;
};
class Solution {
public: 
    inline bool onVerge(int index, const string &s) {
        return index == 0 || index == s.size() - 1;
    }
    
    int findPalindrome(const string &s, int &index1, int &index2) {
        while (!onVerge(index1, s) && !onVerge(index2, s) && s[index1] == s[index2]) {
            --index1;
            ++index2;
        }
        if (s[index1] != s[index2]) {
            ++index1;
            --index2;
        }
        return index2 - index1 + 1;
    }
    
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }
        int index1, index2, center;
        int count, maxCount(0), maxIndex1, maxIndex2;
        for (center = 1; center < s.size(); ++center) {
            index1 = index2 = center;
            count = findPalindrome(s, index1, index2);
            if (count > maxCount) {
                maxCount = count;
                maxIndex1 = index1;
                maxIndex2 = index2;
            }
            
            index1 = center - 1;
            index2 = center;
            count = findPalindrome(s, index1, index2);
            if (count > maxCount) {
                maxCount = count;
                maxIndex1 = index1;
                maxIndex2 = index2;
            }
            
        }
        return s.substr(maxIndex1, maxCount);
    }
};
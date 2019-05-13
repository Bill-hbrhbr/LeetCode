class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        auto hIter = haystack.cbegin();
        for (; hIter != haystack.cend(); ++hIter) {
            auto it = hIter;
            auto nIter = needle.cbegin();
            while (nIter != needle.cend() && it != haystack.cend() && *nIter == *it) {
                nIter++;
                it++;
            }
            if (nIter == needle.cend())
                return hIter - haystack.cbegin();
            else if (it == haystack.cend())
                return -1;
        }
        return -1;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> result;
        int size = intervals.size();
        int start = newInterval[0], end = newInterval[1];
        int startIndex = binarySearch(intervals, size, start, 0);
        int endIndex = binarySearch(intervals, size, end, 1);
        //cout << "Start = " << startIndex << endl;
        //cout << "End = " << endIndex << endl;
        int i;
        for (i = 0; i < startIndex - 1; ++i) {
            result.push_back(intervals[i]);
        }
        vector<int> merge;
        if (startIndex == 0) {
            merge.push_back(start);
        } else if (start <= intervals[startIndex - 1][1]) {
            merge.push_back(intervals[startIndex - 1][0]);
        } else {
            merge.push_back(start);
            result.push_back(intervals[startIndex - 1]);
        }
        if (endIndex == size) {
            merge.push_back(end);
            result.push_back(merge);
            return result;
        } else if (end >= intervals[endIndex][0]) {
            merge.push_back(intervals[endIndex][1]);
            i = endIndex + 1;
        } else {
            merge.push_back(end);
            i = endIndex;
        }
        result.push_back(merge);
        for (; i < size; ++i) {
            result.push_back(intervals[i]);
        }
        return result;
        
        
    }
private:
    int binarySearch(vector<vector<int>> &vec, int &size, int &target, int pos){
        int left = 0, right = size - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (vec[mid][pos] == target) {
                return mid;
            }
            if (vec[mid][pos] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left == right) {
            if (target <= vec[left][pos]) {
                return left;
            } else {
                return left + 1;
            }
        } else {
            return left;
        }
    }
};
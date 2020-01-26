class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        row = matrix.size();
        col = matrix[0].size();
        maxCount = 0;
        
        vector<vector<int>> count;
        for (int i = 0; i < row; ++i) {
            count.push_back(vector<int>(col, 0));
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                dfs(matrix, count, i, j);
            }
        }
        return maxCount;
    }
private:
    int row, col, maxCount;
    bool outOfBounds(int i, int j) {
        return i < 0 || i >= row || j < 0 || j >= col;
    }
    int dfs(vector<vector<int>>& matrix,
            vector<vector<int>>& count,
            int i,
            int j)
    {
        if (count[i][j] > 0) {
            return count[i][j];
        }
        vector<int> choices{0};
        auto it = back_inserter(choices);
        if (!outOfBounds(i - 1, j) && matrix[i][j] > matrix[i - 1][j]) {
            *it = dfs(matrix, count, i - 1, j);
        }
        if (!outOfBounds(i + 1, j) && matrix[i][j] > matrix[i + 1][j]) {
            *it = dfs(matrix, count, i + 1, j);
        }
        if (!outOfBounds(i, j - 1) && matrix[i][j] > matrix[i][j - 1]) {
            *it = dfs(matrix, count, i, j - 1);
        }
        if (!outOfBounds(i, j + 1) && matrix[i][j] > matrix[i][j + 1]) {
            *it = dfs(matrix, count, i, j + 1);
        }
        
        count[i][j] = *max_element(choices.cbegin(), choices.cend()) + 1;
        if (count[i][j] > maxCount) {
            maxCount = count[i][j];
        }
        return count[i][j];
    }
};
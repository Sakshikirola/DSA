class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Check each row
        for (int i = 0; i < n; ++i) {
            vector<bool> seen(n + 1, false);
            for (int j = 0; j < n; ++j) {
                int val = matrix[i][j];
                if (val < 1 || val > n || seen[val])
                    return false;
                seen[val] = true;
            }
        }

        // Check each column
        for (int j = 0; j < n; ++j) {
            vector<bool> seen(n + 1, false);
            for (int i = 0; i < n; ++i) {
                int val = matrix[i][j];
                if (val < 1 || val > n || seen[val])
                    return false;
                seen[val] = true;
            }
        }

        return true;
    }
};

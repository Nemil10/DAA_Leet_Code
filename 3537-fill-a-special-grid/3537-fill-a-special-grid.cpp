class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        if (n == 0)
            return {{0}};

        vector<vector<int>> a = specialGrid(n - 1);
        int m = a.size();

        vector<vector<int>> ans(2 * m, vector<int>(2 * m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j + m] = a[i][j];
                ans[i + m][j + m] = a[i][j] + m * m;
                ans[i + m][j] = a[i][j] + 2 * m * m;
                ans[i][j] = a[i][j] + 3 * m * m;
            }
        }

        return ans;
    }
};
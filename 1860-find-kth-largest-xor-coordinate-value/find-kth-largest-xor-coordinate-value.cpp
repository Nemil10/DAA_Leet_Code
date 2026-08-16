class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> x(m + 1, vector<int>(n + 1, 0));
        vector<int> ans;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                x[i][j] = matrix[i - 1][j - 1] ^
                          x[i - 1][j] ^
                          x[i][j - 1] ^
                          x[i - 1][j - 1];

                ans.push_back(x[i][j]);
            }
        }

        nth_element(ans.begin(), ans.begin() + k - 1, ans.end(),
                    greater<int>());

        return ans[k - 1];
    }
};
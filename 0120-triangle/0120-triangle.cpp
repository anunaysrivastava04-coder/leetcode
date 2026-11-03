class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int i = 0;
        int j = 0;

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return solve(i, j, n, triangle, dp);
    }

    int solve(int i, int j, int n, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {
        if (i >= n) {
            return 0;
        }

        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }

        int left = triangle[i][j] + solve(i + 1, j + 1, n, triangle, dp);
        int right = triangle[i][j] + solve(i + 1, j, n, triangle, dp);

        dp[i][j] = min(left, right);
        return dp[i][j];
    }
};
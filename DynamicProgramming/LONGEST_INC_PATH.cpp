#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &grid, int n, int m, int i, int j, vector<vector<int>> &dp)
{
  // Boundary check
  if (i < 0 || j < 0 || i >= n || j >= m)
    return 0;
  int op1 = 0;
  int op2 = 0;
  int op3 = 0;
  int op4 = 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  // up

  if (i > 0 && grid[i][j] < grid[i - 1][j])
    op1 = 1 + solve(grid, n, m, i - 1, j, dp);
  // left
  if (j > 0 && grid[i][j] < grid[i][j - 1])
    op2 = 1 + solve(grid, n, m, i, j - 1, dp);
  // down
  if (i < n - 1 && grid[i][j] < grid[i + 1][j])
    op3 = 1 + solve(grid, n, m, i + 1, j, dp);
  //  right
  if (j < m - 1 && grid[i][j] < grid[i][j + 1])
    op4 = 1 + solve(grid, n, m, i, j + 1, dp);
  return dp[i][j] = max({op1, op2, op3, op4});
}
int longestIncreasingPath(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  int maxval = 0;
  int i = 0;
  int j = 0;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      int ans = solve(grid, n, m, i, j, dp);
      maxval = max(maxval, ans);
    }
  }
  return maxval + 1;
}
int main()
{
  int row;
  cin >> row;
  int col;
  cin >> col;
  vector<vector<int>> grid(row, vector<int>(col));
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cin >> grid[i][j];
    }
  }
  cout << longestIncreasingPath(grid);
}
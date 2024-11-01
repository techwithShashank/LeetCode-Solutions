#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
  bool fn(std::vector<std::vector<char>> &board, std::string &word, int n, int m, int i, int j, int idx)
  {
    if (i >= n || i < 0 || j >= m || j < 0 || board[i][j] != word[idx] || board[i][j] == '*')
      return false;
    if (idx == word.size() - 1)
      return true;

    char ch = board[i][j];
    board[i][j] = '*';

    bool op1 = fn(board, word, n, m, i - 1, j, idx + 1);
    bool op2 = fn(board, word, n, m, i + 1, j, idx + 1);
    bool op3 = fn(board, word, n, m, i, j + 1, idx + 1);
    bool op4 = fn(board, word, n, m, i, j - 1, idx + 1);

    board[i][j] = ch;
    return op1 || op2 || op3 || op4;
  }

public:
  bool exist(std::vector<std::vector<char>> &board, std::string word)
  {
    int n = board.size();
    int m = board[0].size();
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (fn(board, word, n, m, i, j, idx))
          return true;
      }
    }
    return false;
  }
};

int main()
{
  Solution solution;

  vector<std::vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}};

  string word = "ABCCED";

  if (solution.exist(board, word))
  {
    cout << "Word found!" << std::endl;
  }
  else
  {
    cout << "Word not found!" << std::endl;
  }

  word = "SEE";

  if (solution.exist(board, word))
  {
    cout << "Word found!" << std::endl;
  }
  else
  {
    cout << "Word not found!" << std::endl;
  }

  word = "ABCB";

  if (solution.exist(board, word))
  {
    cout << "Word found!" << std::endl;
  }
  else
  {
    cout << "Word not found!" << std::endl;
  }

  return 0;
}

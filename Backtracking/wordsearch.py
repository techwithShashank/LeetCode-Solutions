from typing import List

class Solution:
    def fn(self, board: List[List[str]], word: str, n: int, m: int, i: int, j: int, idx: int) -> bool:
        if i >= n or i < 0 or j >= m or j < 0 or board[i][j] != word[idx] or board[i][j] == '*':
            return False
        if idx == len(word) - 1:
            return True

        ch = board[i][j]
        board[i][j] = '*'

        found = (self.fn(board, word, n, m, i - 1, j, idx + 1) or
                 self.fn(board, word, n, m, i + 1, j, idx + 1) or
                 self.fn(board, word, n, m, i, j + 1, idx + 1) or
                 self.fn(board, word, n, m, i, j - 1, idx + 1))

        board[i][j] = ch
        return found

    def exist(self, board: List[List[str]], word: str) -> bool:
        n, m = len(board), len(board[0])
        for i in range(n):
            for j in range(m):
                if self.fn(board, word, n, m, i, j, 0):
                    return True
        return False

solution = Solution()
board = [
    ['A', 'B', 'C', 'E'],
    ['S', 'F', 'C', 'S'],
    ['A', 'D', 'E', 'E']
]
words = ["ABCCED", "SEE", "ABCB"]
for word in words:
    print(f"Word '{word}' found!" if solution.exist(board, word) else f"Word '{word}' not found!")

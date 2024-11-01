class Solution {
  fn(board, word, n, m, i, j, idx) {
    if (
      i >= n ||
      i < 0 ||
      j >= m ||
      j < 0 ||
      board[i][j] !== word[idx] ||
      board[i][j] === "*"
    )
      return false;
    if (idx === word.length - 1) return true;

    let ch = board[i][j];
    board[i][j] = "*";

    let found =
      this.fn(board, word, n, m, i - 1, j, idx + 1) ||
      this.fn(board, word, n, m, i + 1, j, idx + 1) ||
      this.fn(board, word, n, m, i, j + 1, idx + 1) ||
      this.fn(board, word, n, m, i, j - 1, idx + 1);

    board[i][j] = ch;
    return found;
  }

  exist(board, word) {
    let n = board.length,
      m = board[0].length;
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < m; j++) {
        if (this.fn(board, word, n, m, i, j, 0)) return true;
      }
    }
    return false;
  }
}

let solution = new Solution();
let board = [
  ["A", "B", "C", "E"],
  ["S", "F", "C", "S"],
  ["A", "D", "E", "E"],
];
let words = ["ABCCED", "SEE", "ABCB"];

words.forEach((word) => {
  console.log(
    solution.exist(board, word)
      ? `Word '${word}' found!`
      : `Word '${word}' not found!`
  );
});

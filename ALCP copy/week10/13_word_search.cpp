#include<iostream>
#include<vector>
#include<string>
using namespace std;

int R, C;
bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int k) {
    if (k == (int)word.size()) return true;
    if (r < 0 || c < 0 || r >= R || c >= C || board[r][c] != word[k]) return false;
    char saved = board[r][c];
    board[r][c] = '#';
    bool ok = dfs(board, word, r+1, c, k+1) || dfs(board, word, r-1, c, k+1) ||
              dfs(board, word, r, c+1, k+1) || dfs(board, word, r, c-1, k+1);
    board[r][c] = saved;
    return ok;
}
int main() {
    cin >> R >> C;
    vector<vector<char>> board(R, vector<char>(C));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) cin >> board[i][j];
    string word; cin >> word;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (dfs(board, word, i, j, 0)) { cout << "Found\n"; return 0; }
    cout << "Not found\n";
    return 0;
}

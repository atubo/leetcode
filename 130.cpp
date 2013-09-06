#include <vector>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            if (isValid(0, i, board, visited)) {
                bfs(0, i, board, visited);
            }
            if (isValid(m-1, i, board, visited)) {
                bfs(m-1, i, board, visited);
            }
        }
        for (int i = 0; i < m; i++) {
            if (isValid(i, 0, board, visited)) {
                bfs(i, 0, board, visited);
            }
            if (isValid(i, n-1, board, visited)) {
                bfs(i, n-1, board, visited);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) board[i][j] = 'X';
            }
        }
    }
private:
    bool isValid(int i, int j, const vector<vector<char> >& board,
                 const vector<vector<bool> >& visited) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (visited[i][j] || board[i][j] == 'X') return false;
        return true;
    }
        
    void bfs(int i, int j, const vector<vector<char> >& board,
             vector<vector<bool> >& visited) {
        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        visited[i][j] = true;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            if (isValid(row+1, col, board, visited)) {
                q.push(make_pair(row+1, col));
                visited[row+1][col] = true;
            }
            if (isValid(row-1, col, board, visited)) {
                q.push(make_pair(row-1, col));
                visited[row-1][col] = true;
            }
            if (isValid(row, col+1, board, visited)) {
                q.push(make_pair(row, col+1));
                visited[row][col+1] = true;
            }
            if (isValid(row, col-1, board, visited)) {
                q.push(make_pair(row, col-1));
                visited[row][col-1] = true;
            }
        }
    }
};

#if 0
int main()
{
    int m;
    int n;
    cin >> m >> n;
    vector<vector<char> > board(m, vector<char>(n, 'X'));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    Solution s;
    s.solve(board);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}
#endif


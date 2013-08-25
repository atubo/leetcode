#include <string>
#include <vector>
#include <exception>
#include <iostream>
using namespace std;

struct Cell {
    int i;
    int j;
    Cell(int i_, int j_): i(i_), j(j_) {}
};

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if ((int)word.length() == 0) return true;
        if (board.size() == 0 || board[0].size() == 0) return false;
        m = board.size();
        n = board[0].size();
        visited.resize(m, vector<bool>(n, false));
        try {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == word[0]) {
                        visit(Cell(i,j), 0, board, word);
                    }
                }
            }
        }
        catch (int e) {
            return true;
        }
        return false;
    }
private:
    void visit(const Cell& v, int depth,
               const vector<vector<char> >& board,
               const string& word) {
        visited[v.i][v.j] = true;

        if (depth == (int)word.length() - 1) throw 1;
        vector<Cell> neighbors = getNeighbors(v);
        for (int i = 0; i < (int)neighbors.size(); i++) {
            Cell u = neighbors[i];
            if (!visited[u.i][u.j] && board[u.i][u.j] == word[depth+1]) {
                visit(u, depth+1, board, word);
            }
        }

        visited[v.i][v.j] = false;
    }
    vector<Cell> getNeighbors(const Cell& v) {
        vector<Cell> result;
        int i = v.i;
        int j = v.j;
        if (0 <= i-1 && i-1 < m) {
            result.push_back(Cell(i-1, j));
        }
        if (0 <= i+1 && i+1 < m) {
            result.push_back(Cell(i+1, j));
        }
        if (0 <= j-1 && j-1 < n) {
            result.push_back(Cell(i, j-1));
        }
        if (0 <= j+1 && j+1 < n) {
            result.push_back(Cell(i, j+1));
        }
        return result;
    }
    int m;
    int n;
    vector<vector<bool> > visited;
};

#if 1
int main()
{
    int m;
    int n;
    cin >> m >> n;
    vector<vector<char> > board(m, vector<char>(n, '\0'));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    string word;
    cin >> word;
    Solution s;
    cout << s.exist(board, word) << endl;

    return 0;
}
#endif


import java.util.*;

public class SurroundedRegions {
    private static class Pair {
        private int i;
        private int j;
        public Pair(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
    public void solve(char[][] board) {
        int N = board.length;
        if (N == 0) return;
        int M = board[0].length;
        if (M == 0) return;
        boolean[][] visited = new boolean[N][M];
        for (int i = 0; i < M; i++) {
            if (board[0][i] == 'O' && !visited[0][i]) {
                bfs(0, i, visited, board);
            }
            if (board[N-1][i] == 'O' && !visited[N-1][i]) {
                bfs(N-1, i, visited, board);
            }
        }
        for (int i = 0; i < N; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                bfs(i, 0, visited, board);
            }
            if (board[i][M-1] == 'O' && !visited[i][M-1]) {
                bfs(i, M-1, visited, board);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    private void bfs(int i, int j, boolean[][] visited, char[][] board) {
        int N = visited.length;
        int M = visited[0].length;
        LinkedList<Pair> queue = new LinkedList<>();
        queue.offerLast(new Pair(i, j));
        visited[i][j] = true;
        while (!queue.isEmpty()) {
            Pair p = queue.pollFirst();
            for (Pair nb: neighbors(p, board, N, M)) {
                if (!visited[nb.i][nb.j]) {
                    queue.offerLast(nb);
                    visited[nb.i][nb.j] = true;
                }
            }
        }
    }
    private List<Pair> neighbors(Pair p, char[][] board, int N, int M) {
        ArrayList<Pair> result = new ArrayList<>();
        int i = p.i;
        int j = p.j;
        if (i > 0 && board[i-1][j] == 'O') {
            result.add(new Pair(i-1, j));
        }
        if (i < N-1 && board[i+1][j] == 'O') {
            result.add(new Pair(i+1, j));
        }
        if (j > 0 && board[i][j-1] == 'O') {
            result.add(new Pair(i, j-1));
        }
        if (j < M-1 && board[i][j+1] == 'O') {
            result.add(new Pair(i, j+1));
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        char[][] board = new char[N][M];
        for (int i = 0; i < N; i++) {
            String s = sc.next();
            for (int j = 0; j < M; j++) {
                board[i][j] = s.charAt(j);
            }
        }
        SurroundedRegions solution = new SurroundedRegions();
        solution.solve(board);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                System.out.printf("%c ", board[i][j]);
            }
            System.out.printf("\n");
        }
    }
}
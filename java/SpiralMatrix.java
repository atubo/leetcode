import java.util.*;

public class SpiralMatrix {
    public ArrayList<Integer> spiralOrder(int[][] matrix) {
        ArrayList<Integer> result = new ArrayList<>();
        int M = matrix.length;
        if (M == 0) return result;
        int N = matrix[0].length;
        if (N == 0) return result;
        
        visit(matrix, 0, 0, M-1, N-1, result);
        return result;
    }
    
    private void visit(int[][] matrix, int r1, int c1, int r2, int c2, ArrayList<Integer> result) {
        if (r1 == r2) {
            for (int i = c1; i <= c2; i++) {
                result.add(matrix[r1][i]);
            }
            return;
        }
        if (c1 == c2) {
            for (int i = r1; i <= r2; i++) {
                result.add(matrix[i][c1]);
            }
            return;
        }
        
        for (int i = c1; i <= c2; i++) {
            result.add(matrix[r1][i]);
        }
        for (int i = r1+1; i <= r2; i++) {
            result.add(matrix[i][c2]);
        }
        for (int i = c2-1; i >= c1; i--) {
            result.add(matrix[r2][i]);
        }
        for (int i = r2-1; i >= r1+1; i--) {
            result.add(matrix[i][c1]);
        }
        
        if (c1 == c2-1 || r1 == r2-1) return;
        visit(matrix, r1+1, c1+1, r2-1, c2-1, result);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int M = sc.nextInt();
        int N = sc.nextInt();
        int[][] a = new int[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        SpiralMatrix solution = new SpiralMatrix();
        ArrayList<Integer> result = solution.spiralOrder(a);
        System.out.println(result);
    }
}
        
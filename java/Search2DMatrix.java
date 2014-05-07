import LeetcodeUtil.*;
import java.util.*;

public class Search2DMatrix {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        if (m == 0) return false;
        int n = matrix[0].length;
        if (n == 0) return false;
        
        int row = findRow(matrix, target);
        if (row >= 0 && row < m) {
            return isInRow(matrix[row], target);
        } else {
            return false;
        }
    }
    private int findRow(int[][] matrix, int target) {
        int m = matrix.length;
        if (target < matrix[0][0]) return -1;
        if (target >= matrix[m-1][0]) return m-1;
        int i = 0;
        int j = m-1;
        while (j > i+1) {
            int mid = (i+j)/2;
            if (target >= matrix[mid][0]) {
                i = mid;
            } else {
                j = mid;
            }
        }
        return i;
    }
    private boolean isInRow(int[] row, int target) {
        int n = row.length;
        if (row[n-1] == target) return true;
        if (row[n-1] < target) return false;
        int i = 0;
        int j = n-1;
        while (j > i+1) {
            int mid = (i+j)/2;
            if (row[mid] <= target) {
                i = mid;
            } else {
                j = mid;
            }
        }
        return row[i] == target;
    }
    
    public static void main(String[] args) {
        int[][] matrix = { {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
        };
        Search2DMatrix solution = new Search2DMatrix();
        System.out.println(solution.searchMatrix(matrix, 64));
    }
}
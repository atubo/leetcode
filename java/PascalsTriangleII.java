import java.util.*;

public class PascalsTriangleII {
    public ArrayList<Integer> getRow(int rowIndex) {
        int[] dpPrev = new int[rowIndex+1];
        int[] dpCurr = new int[rowIndex+1];
        dpPrev[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            dpCurr[0] = 1;
            for (int j = 1; j <= i; j++) {
                dpCurr[j] = dpPrev[j-1] + dpPrev[j];
            }
            int[] tmp = dpCurr;
            dpCurr = dpPrev;
            dpPrev = tmp;
        }
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < rowIndex+1; i++) {
            result.add(dpPrev[i]);
        }
        return result;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        PascalsTriangleII solution = new PascalsTriangleII();
        ArrayList<Integer> result = solution.getRow(n);
        for (Integer x: result) {
            System.out.printf("%d ", x);
        }
    }
}
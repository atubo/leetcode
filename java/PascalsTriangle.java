import java.util.*;

public class PascalsTriangle {
    public ArrayList<ArrayList<Integer>> generate(int numRows) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        if (numRows == 0) return result;
        result.add(new ArrayList<Integer>());
        result.get(0).add(1);
        for (int i = 1; i < numRows; i++) {
            result.add(new ArrayList<Integer>());
            result.get(i).add(1);
            for (int j = 1; j < i; j++) {
                result.get(i).add(result.get(i-1).get(j-1) + result.get(i-1).get(j));
            }
            result.get(i).add(1);
        }
        return result;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        PascalsTriangle solution = new PascalsTriangle();
        ArrayList<ArrayList<Integer>> result = solution.generate(n);
        for (ArrayList<Integer> row: result) {
            for (Integer x: row) {
                System.out.printf("%d ", x);
            }
            System.out.println();
        }
    }
}
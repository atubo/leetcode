import LeetcodeUtil.*;
import java.util.*;

public class Triangle {
    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        int n = triangle.size();
        int[] dpPrev = new int[n];
        int[] dpCurr = new int[n];
        
        for (int i = 0; i < n; i++) {
            dpPrev[i] = triangle.get(n-1).get(i);
        }
        
        for (int row = n-2; row >= 0; row--) {
            for (int i = 0; i <= row; i++) {
                dpCurr[i] = triangle.get(row).get(i) + Math.min(dpPrev[i], dpPrev[i+1]);
            }
            int[] tmp = dpCurr;
            dpCurr = dpPrev;
            dpPrev = tmp;
        }
        return dpPrev[0];
    }
    
    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> triangle = new ArrayList<>();
        triangle.add(new ArrayList<Integer>(Arrays.asList(2)));
        triangle.add(new ArrayList<Integer>(Arrays.asList(3,4)));
        triangle.add(new ArrayList<Integer>(Arrays.asList(6,5,7)));
        triangle.add(new ArrayList<Integer>(Arrays.asList(4,1,8,3)));

        Triangle solution = new Triangle();
        System.out.println(solution.minimumTotal(triangle));
    }
}
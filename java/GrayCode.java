import java.util.*;

public class GrayCode {
    public ArrayList<Integer> grayCode(int n) {
        if (n == 0) {
            return new ArrayList<Integer>(Arrays.asList(0));
        }
        
        ArrayList<Integer> result = grayCode(n-1);
        int size = result.size();
        for (int i = size-1; i >= 0; i--) {
            result.add((1<<(n-1)) | result.get(i));
        }
        return result;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        GrayCode solution = new GrayCode();
        ArrayList<Integer> result = solution.grayCode(n);
        for (Integer x: result) {
            System.out.printf("%d ", x);
        }
    }
}
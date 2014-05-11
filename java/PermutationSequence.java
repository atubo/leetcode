import java.util.*;

public class PermutationSequence {
    public String getPermutation(int n, int k) {
        if (n == 0) return "";
        
        int[] digits = new int[n];
        for (int i = 0; i < n; i++) {
            digits[i] = i+1;
        }
        build(digits, 0, k-1);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append((char)('0'+digits[i]));
        }
        return sb.toString();
    }
    
    private void build(int[] digits, int pos, int k) {
        int n = digits.length;
        if (k == 0 || pos == n-1) return;
        
        int fact = factorial(n-1-pos);
        int offset = k/fact;
        swap(digits, pos, pos+offset);
        rotate(digits, pos+1, pos+offset);
        build(digits, pos+1, k%fact);
    }
    
    private void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    
    private void rotate(int[] a, int start, int pivot) {
        if (pivot < start) return;
        int tmp = a[pivot];
        for (int i = pivot; i > start; i--) {
            a[i] = a[i-1];
        }
        a[start] = tmp;
    }
    
    private int factorial(int k) {
        int result = 1;
        for (int i = 2; i <= k; i++) {
            result *= i;
        }
        return result;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        PermutationSequence solution = new PermutationSequence();
        System.out.println(solution.getPermutation(n, k));
    }
}
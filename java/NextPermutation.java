import LeetcodeUtil.*;
import java.util.*;

public class NextPermutation {
    public void nextPermutation(int[] a) {
        int N = a.length;
        int pos = N-1;
        while (pos > 0 && a[pos] <= a[pos-1]) pos--;
        
        if (pos > 0) {
            int k = N-1;
            while (a[k] <= a[pos-1]) k--;
            swap(a, pos-1, k);
        }
        reverse(a, pos);
    }
    
    private void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    
    private void reverse(int[] a, int pos) {
        int N = a.length;
        int i = pos;
        int j = N-1;
        while (j > i) {
            swap(a, i++, j--);
        }
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        NextPermutation solution = new NextPermutation();
        solution.nextPermutation(a);
        for (int i = 0; i < a.length; i++) {
            System.out.printf("%d ", a[i]);
        }
    }
}
            
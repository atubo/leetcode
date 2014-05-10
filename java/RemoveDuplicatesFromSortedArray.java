import LeetcodeUtil.*;
import java.util.*;

public class RemoveDuplicatesFromSortedArray {
    public int removeDuplicates(int[] a) {
        int N = a.length;
        if (N == 0) return 0;
        
        int i = 0;
        int j = 1;
        while (true) {
            while (j < N && a[j] == a[i]) j++;
            if (j == N) break;
            a[++i] = a[j++];
        }
        return i+1;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        RemoveDuplicatesFromSortedArray solution = new RemoveDuplicatesFromSortedArray();
        int n = solution.removeDuplicates(a);
        System.out.println(n);
        for (int i = 0; i < n; i++) {
            System.out.printf("%d ", a[i]);
        }
    }
}
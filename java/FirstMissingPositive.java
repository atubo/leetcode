import LeetcodeUtil.*;
import java.util.*;

public class FirstMissingPositive {
    public int firstMissingPositive(int[] a) {
        for (int i = 0; i < a.length; i++) {
            while (a[i] <= a.length && a[i] > 0 && a[a[i]-1] != a[i]) {
                swap(a, i, a[i]-1);
            }
        }
        int pos = 0;
        for (; pos < a.length; pos++) {
            if (a[pos] != pos+1) break;
        }
        return pos+1;
    }
    private void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        FirstMissingPositive solution = new FirstMissingPositive();
        System.out.println(solution.firstMissingPositive(a));
    }
}
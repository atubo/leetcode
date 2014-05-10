import LeetcodeUtil.*;
import java.util.*;

public class RemoveElement {
    public int removeElement(int[] a, int target) {
        int N = a.length;
        if (N == 0) return 0;
        
        int i = 0;
        int j = 0;
        while (true) {
            while (j < N && a[j] == target) j++;
            if (j == N) break;
            a[i++] = a[j++];
        }
        return i;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int target = reader.readInt();
        int[] a = reader.readArray();
        RemoveElement solution = new RemoveElement();
        int n = solution.removeElement(a, target);
        System.out.println(n);
        for (int i = 0; i < n; i++) {
            System.out.printf("%d ", a[i]);
        }
    }
}
            
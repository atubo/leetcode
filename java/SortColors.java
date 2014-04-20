import LeetcodeUtil.*;
import java.util.*;

public class SortColors {
    public void sortColors(int[] a) {
        int N = a.length;
        int lt = 0;
        int i = 0;
        int gt = N-1;
        while (i <= gt) {
            if (a[i] == 1) i++;
            else if (a[i] < 1) swap(a, i++, lt++);
            else swap(a, i, gt--);
        }
    }
    private void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        SortColors solution = new SortColors();
        solution.sortColors(a);
        for (int i = 0; i < a.length; i++) {
            System.out.printf("%d ", a[i]);
        }
        System.out.println();
    }
}
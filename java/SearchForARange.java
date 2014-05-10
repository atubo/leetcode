import LeetcodeUtil.*;
import java.util.*;

public class SearchForARange {
    public int[] searchRange(int[] a, int target) {
        int[] result = {-1, -1};
        if (a.length == 0) return result;
        
        int left  = searchLeft(a, target);
        int right = searchRight(a, target);
        if (left >= 0 && a[left] == target) {
            result[0] = left;
            result[1] = right;
        }
        return result;
    }
    
    private int searchLeft(int[] a, int target) {
        int N = a.length;
        if (a[0] > target || a[N-1] < target) return -1;
        if (a[0] == target) return 0;
        int i = 0;
        int j = N-1;
        while (j > i+1) {
            int mid = (i+j)/2;
            if (a[mid] < target) i = mid;
            else j = mid;
        }
        return j;
    }
    
    private int searchRight(int[] a, int target) {
        int N = a.length;
        if (a[0] > target || a[N-1] < target) return -1;
        if (a[N-1] == target) return N-1;
        int i = 0;
        int j = N-1;
        while (j > i+1) {
            int mid = (i+j)/2;
            if (a[mid] <= target) i = mid;
            else j = mid;
        }
        return i;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int target = reader.readInt();
        int[] a = reader.readArray();
        SearchForARange solution = new SearchForARange();
        int[] result = solution.searchRange(a, target);
        System.out.printf("%d %d\n", result[0], result[1]);
    }
}
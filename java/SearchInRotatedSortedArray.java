import LeetcodeUtil.*;
import java.util.*;

public class SearchInRotatedSortedArray {
    public int search(int[] a, int target) {
        int N = a.length;
        if (N == 0) return -1;
        
        int pmax = searchMax(a);
        if (target >= a[0]) {
            return searchRange(a, target, 0, pmax);
        } else {
            return searchRange(a, target, pmax+1, N-1);
        }
    }
    
    private int searchMax(int[] a) {
        int N = a.length;
        if (a[N-1] > a[0]) return N-1;
        int i = 0;
        int j = N-1;
        while (j > i+1) {
            int mid = (i+j)/2;
            if (a[mid] > a[0]) i = mid;
            else j = mid;
        }
        return i;
    }
    
    private int searchRange(int[] a, int target, int start, int end) {
        if (start > end) return -1;
        if (a[start] > target || a[end] < target) return -1;
        if (a[end] == target) return end;
        
        int i = start;
        int j = end;
        while (j > i+1) {
            int mid = (i+j)/2;
            if (a[mid] <= target) i = mid;
            else j = mid;
        }
        return (a[i] == target ? i : -1);
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int target = reader.readInt();
        int[] a = reader.readArray();
        SearchInRotatedSortedArray solution = new SearchInRotatedSortedArray();
        System.out.println(solution.search(a, target));
    }
}
        
        
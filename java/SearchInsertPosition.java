import LeetcodeUtil.*;
import java.util.*;

public class SearchInsertPosition {
    public int searchInsert(int[] a, int target) {
        int N = a.length;
        if (N == 0) return 0;
        
        if (a[0] >= target) return 0;
        if (a[N-1] < target) return N;
        
        int i = 0;
        int j = N-1;
        while (j > i+1) {
            int mid = (i+j)/2;
            if (a[mid] < target) i = mid;
            else j = mid;
        }
        return j;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int target = reader.readInt();
        int[] a = reader.readArray();
        SearchInsertPosition solution = new SearchInsertPosition();
        System.out.println(solution.searchInsert(a, target));
    }
}
import LeetcodeUtil.*;
import java.util.*;

public class Candy {
    public int candy(int[] ratings) {
        int N = ratings.length;
        if (N == 0) return 0;
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = 1;
        }
        process(ratings, a);
        for (int i = 0; i < N/2; i++) {
            int tmp = ratings[i];
            ratings[i] = ratings[N-1-i];
            ratings[N-1-i] = tmp;
            tmp = a[i];
            a[i] = a[N-1-i];
            a[N-1-i] = tmp;
        }
        process(ratings, a);
        int result = 0;
        for (int i = 0; i < N; i++) {
            result += a[i];
        }
        return result;
    }
    private void process(int[] r, int[] a) {
        int N = r.length;
        int p = 0;
        while (true) {
            while (p < N-1 && r[p] >= r[p+1]) {
                p++;
            }
            if (p == N-1) {
                break;
            }
            p++;
            while (p < N && r[p] > r[p-1]) {
                a[p] = Math.max(a[p], a[p-1] + 1);
                p++;
            }
            if (p == N) {
                break;
            }
        }
    }
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] ratings = reader.readArray();
        Candy solution = new Candy();
        System.out.printf("%d\n", solution.candy(ratings));
    }
}
        
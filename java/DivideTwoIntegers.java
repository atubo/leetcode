import java.util.*;

public class DivideTwoIntegers {
    public int divide(int a, int b) {
        if (a == 0) return 0;
        int sign = 1;
        if (a > 0 && b < 0 || a < 0 && b > 0) sign = -1;
        int result = divideRecur(Math.abs(a), Math.abs(b));
        return (sign == 1 ? result : -result);
    }
    
    private int divideRecur(long a, long b) {
        if (a < b) return 0;
        int shift = 0;
        while (b << shift <= a) shift++;
        return (1 << (shift-1)) + divideRecur(a - (b << (shift-1)), b);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        DivideTwoIntegers solution = new DivideTwoIntegers();
        System.out.println(solution.divide(a, b));
    }
}
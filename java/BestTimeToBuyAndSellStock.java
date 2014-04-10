import LeetcodeUtil.*;
import java.util.*;

public class BestTimeToBuyAndSellStock {
    public int maxProfit(int[] prices) {
        final int N = prices.length;
        if (N <= 1) return 0;
        int lowest = prices[0];
        int result = 0;
        for (int i = 1; i < N; i++) {
            if (prices[i] >= lowest) {
                result = Math.max(prices[i] - lowest, result);
            } else {
                lowest = prices[i];
            }
        }
        return result;
    }
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        BestTimeToBuyAndSellStock solution = new BestTimeToBuyAndSellStock();
        System.out.println(solution.maxProfit(a));
    }
}
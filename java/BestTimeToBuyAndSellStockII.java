import LeetcodeUtil.*;
import java.util.*;

public class BestTimeToBuyAndSellStockII {
    public int maxProfit(int[] prices) {
        int profit = 0;
        for (int i = 1; i < prices.length; i++) {
            profit += Math.max(0, prices[i]-prices[i-1]);
        }
        return profit;
    }
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        BestTimeToBuyAndSellStockII solution = new BestTimeToBuyAndSellStockII();
        System.out.println(solution.maxProfit(a));
    }
}
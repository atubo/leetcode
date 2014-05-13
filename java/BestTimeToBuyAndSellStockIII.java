import LeetcodeUtil.*;
import java.util.*;

public class BestTimeToBuyAndSellStockIII {
    public int maxProfit(int[] prices) {
        int dp1 = 0;
        int dp1max = 0;
        int dp2 = 0;
        int dp2max = 0;
        for (int i = 1; i < prices.length; i++) {
            int d = prices[i] - prices[i-1];
            dp1 = Math.max(0, dp1 + d);
            dp1max = Math.max(dp1max, dp1);
            dp2 = Math.max(dp1max, dp2 + d);
            dp2max = Math.max(dp2max, dp2);
        }
        return dp2max;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        BestTimeToBuyAndSellStockIII solution = new BestTimeToBuyAndSellStockIII();
        System.out.println(solution.maxProfit(a));
    }
}
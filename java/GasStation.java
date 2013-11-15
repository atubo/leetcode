import java.util.*;

public class GasStation {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int[] d = new int[n];
        d[0] = gas[0] - cost[0];
        int min_d = d[0];
        int min_dIndex = 0;
        for (int i = 1; i < n; i++) {
            d[i] = d[i-1] + gas[i] - cost[i];
            if (min_d > d[i]) {
                min_d = d[i];
                min_dIndex = i;
            }
        }
        if (d[n-1] < 0) return -1;
        return (min_dIndex + 1) % n;
    }
}
        
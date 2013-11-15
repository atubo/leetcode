import java.util.*;

public class SingleNumber {
    public int singleNumber(int[] A) {
        int result = 0;
        for (int a: A) {
            result = result ^ a;
        }
        
        return result;
    }
}

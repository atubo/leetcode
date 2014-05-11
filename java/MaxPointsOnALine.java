import LeetcodeUtil.*;
import java.util.*;

public class MaxPointsOnALine {
    public static class Slope {
        private int x;
        private int y;
        
        public Slope(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        @Override
        public boolean equals(Object o) {
            if (!(o instanceof Slope)) {
                return false;
            }
            Slope otherSlope = (Slope)o;
            return (x == otherSlope.x && y == otherSlope.y);
        }
        
        @Override
        public int hashCode() {
            return 37*x + y;
        }
    }
    
    public int maxPoints(Point[] points) {
        int N = points.length;
        if (N <= 1) return N;
        
        int result = 0;
        for (int i = 0; i < N-1; i++) {
            Point p1 = points[i];
            HashMap<Slope, Integer> table = new HashMap<>();
            int coincident = 0;
            for (int j = i+1; j < N; j++) {
                Point p2 = points[j];
                if (pointEq(p1, p2)) {
                    coincident++;
                    continue;
                }
                
                Slope slope = getSlope(p1, p2);
                if (!table.containsKey(slope)) {
                    table.put(slope, 1);
                }
                table.put(slope, table.get(slope)+1);
            }
            for (Integer count: table.values()) {
                result = Math.max(result, count + coincident);
            }
        }
        return result;
    }
    
    private boolean pointEq(Point p1, Point p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }
    
    private int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }
    
    private Slope getSlope(Point p1, Point p2) {
        int dx = p2.x - p1.x;
        int dy = p2.y - p1.y;
        if (dx == 0) return new Slope(0, 1);
        if (dy == 0) return new Slope(1, 0);
        int g = gcd(Math.abs(dx), Math.abs(dy));
        return new Slope(dx/g, dy/g);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Point[] points = new Point[n];
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            points[i] = new Point(x, y);
        }
        
        MaxPointsOnALine solution = new MaxPointsOnALine();
        System.out.println(solution.maxPoints(points));
    }
}
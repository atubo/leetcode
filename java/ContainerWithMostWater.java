import LeetcodeUtil.InputReader;

public class ContainerWithMostWater {
    public int maxArea(int[] height) {
        int l = 0;
        int r = height.length - 1;
        int area = calcArea(height, l, r);
        while (true) {
            if (height[l] <= height[r]) {
                int h0 = height[l];
                while (l < r && height[l] <= h0) {
                    l++;
                }
                if (l >= r) break;
                area = Math.max(calcArea(height, l, r), area);
            }
            if (height[l] > height[r]) {
                int h0 = height[r];
                while (l < r && height[r] <= h0) {
                    r--;
                }
                if (l >= r) break;
                area = Math.max(calcArea(height, l, r), area);
            }
        }
        
        return area;
    }
    
    private static int calcArea(int[] h, int l, int r) {
        return (r - l) * Math.min(h[l], h[r]);
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        ContainerWithMostWater solution = new ContainerWithMostWater();
        System.out.printf("%d\n", solution.maxArea(a));
    }
}
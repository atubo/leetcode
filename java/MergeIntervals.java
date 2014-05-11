import LeetcodeUtil.*;
import java.util.*;

public class MergeIntervals {
    public ArrayList<Interval> merge(ArrayList<Interval> intervals) {        
        Collections.sort(intervals, new Comparator<Interval>() {
            @Override
            public int compare(Interval i1, Interval i2) {
                if (Integer.compare(i1.start, i2.start) != 0) {
                    return Integer.compare(i1.start, i2.start);
                } else {
                    return Integer.compare(i1.end, i2.end);
                }
            }
        });
        
        ArrayList<Interval> result = new ArrayList<>();
        for (int i = 0; i < intervals.size(); i++) {
            int s = intervals.get(i).start;
            int e = intervals.get(i).end;
            if (result.isEmpty()) {
                result.add(new Interval(s, e));
                continue;
            }
            Interval last = result.get(result.size()-1);
            if (s > last.end) {
                result.add(new Interval(s, e));
            } else {
                last.end = Math.max(last.end, e);
            }
        }
        return result;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Interval> intervals = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int s = sc.nextInt();
            int e = sc.nextInt();
            intervals.add(new Interval(s, e));
        }
        MergeIntervals solution = new MergeIntervals();
        ArrayList<Interval> result = solution.merge(intervals);
        for (Interval interval: result) {
            System.out.printf("%d %d\n", interval.start, interval.end);
        }
    }
}
        
import LeetcodeUtil.*;
import java.util.*;

public class InsertInterval {
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
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
        
        int N = intervals.size();
        int index = 0;
        ArrayList<Interval> result = new ArrayList<>();
        while (index < N && intervals.get(index).start < newInterval.start) {
            result.add(intervals.get(index++));
        }
        
        addInterval(result, newInterval);
        for (int i = index; i < N; i++) {
            addInterval(result, intervals.get(i));
        }
        
        return result;
    }
    
    private void addInterval(ArrayList<Interval> list, Interval interval) {
        int s = interval.start;
        int e = interval.end;
        if (list.isEmpty()) {
            list.add(new Interval(s, e));
            return;
        }
        
        Interval last = list.get(list.size()-1);
        if (s > last.end) {
            list.add(new Interval(s, e));
        } else {
            last.end = Math.max(last.end, e);
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        int e = sc.nextInt();
        Interval newInterval = new Interval(s, e);
        int n = sc.nextInt();
        ArrayList<Interval> intervals = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            s = sc.nextInt();
            e = sc.nextInt();
            intervals.add(new Interval(s, e));
        }
        
        InsertInterval solution = new InsertInterval();
        ArrayList<Interval> result = solution.insert(intervals, newInterval);
        for (Interval interval: result) {
            System.out.printf("%d %d\n", interval.start, interval.end);
        }
    }
}
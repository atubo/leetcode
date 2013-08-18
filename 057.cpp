#include <vector>
#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "Interval.h"
#endif

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals,
                            Interval newInterval) {
        int n = intervals.size();
        vector<Interval> result;
        int i = -1; // last interval to the left
        int j = n;  // first interval to the right
        while (i < n-1 && intervals[i+1].end < newInterval.start) {
            i++;
        }
        while (j > 0 && intervals[j-1].start > newInterval.end) {
            j--;
        }
        for (int k = 0; k <= i; k++) {
            result.push_back(intervals[k]);
        }
        int left = newInterval.start;
        if (i < n-1) {
            left = min(left, intervals[i+1].start);
        }
        int right = newInterval.end;
        if (j > 0) {
            right = max(right, intervals[j-1].end);
        }
        result.push_back(Interval(left, right));
        for (int k = j; k < n; k++) {
            result.push_back(intervals[k]);
        }
        return result;
    }
};

#if DEBUG
int main()
{
    vector<Interval> intervals = readIntervals();
    int x1;
    int x2;
    cin >> x1 >> x2;
    Interval newInterval(x1, x2);
    Solution s;
    vector<Interval> result = s.insert(intervals, newInterval);
    printIntervals(result);

    return 0;
}
#endif


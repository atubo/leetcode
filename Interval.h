#ifndef INTERVAL_H
#define INTERVAL_H

#include <vector>
#include <iostream>

struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

inline std::vector<Interval> readIntervals()
{
    using std::cin;
    using std::vector;

    vector<Interval> result;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1;
        int x2;
        cin >> x1 >> x2;
        result.push_back(Interval(x1, x2));
    }
    return result;
}

void printIntervals(const std::vector<Interval>& intervals)
{
    for (int i = 0; i < (int)intervals.size(); i++) {
        printf("[%d %d] ", intervals[i].start, intervals[i].end);
    }
    printf("\n");
}

#endif

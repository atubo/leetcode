#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "Interval.h"
#endif

struct EndPoint {
    enum PointType {
        LEFT  = 0,
        RIGHT = 1
    };
    int pos1;
    int pos2;
    PointType type;
    EndPoint(int pos1_, int pos2_, PointType type_):
        pos1(pos1_), pos2(pos2_), type(type_) {}
    bool operator < (const EndPoint& other) const {
        if      (pos1 < other.pos1) return true;
        else if (pos1 > other.pos1) return false;
        else if (type < other.type) return true;
        else if (type > other.type) return false;
        else return pos2 < other.pos2;
    }
    bool operator == (const EndPoint& other) const {
        return (pos1 == other.pos1 &&
                pos2 == other.pos2 &&
                type == other.type);
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<EndPoint> points;
        for (int i = 0; i < (int)intervals.size(); i++) {
            const Interval x = intervals[i];
            points.push_back(EndPoint(x.start, x.end, EndPoint::LEFT));
            points.push_back(EndPoint(x.end, x.start, EndPoint::RIGHT));
        }
        sort(points.begin(), points.end());
        vector<EndPoint>::iterator it = unique(points.begin(),
                                               points.end());
        points.erase(it, points.end());

        vector<Interval> result;
        int n = points.size();
        int i = 0;
        while (i < n) {
            int startPos = points[i].pos1;
            int endPos = points[i].pos2;
            int j = i + 1;
            while (j < n && points[j].pos1 <= endPos) {
                if (points[j].type == EndPoint::LEFT) {
                    endPos = max(points[j].pos2, endPos);
                }
                j++;
            }
            i = j;
            result.push_back(Interval(startPos, endPos));
        }
        return result;
    }
};

#if DEBUG
int main()
{
    vector<Interval> intervals = readIntervals();
    Solution s;
    vector<Interval> result = s.merge(intervals);
    printIntervals(result);

    return 0;
}
#endif


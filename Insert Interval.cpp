class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        bool inserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (!inserted && intervals[i].end >= newInterval.start) {
                if (intervals[i].start <= newInterval.end) {
                    int start = min(newInterval.start, intervals[i].start);
                    int end = max(newInterval.end, intervals[i].end);
                    result.push_back(Interval(start, end));
                } else {
                    result.push_back(newInterval);
                    result.push_back(intervals[i]);
                }
                inserted = true;
            } else if (i > 0 && result.back().end >= intervals[i].start) {
                result.back().end = max(result.back().end, intervals[i].end);
            } else {
                result.push_back(intervals[i]);
            }
        }
        if (!inserted) {
            result.push_back(newInterval);
        }
        return result;
    }
};

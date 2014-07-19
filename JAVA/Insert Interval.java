public class Solution {
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
        ArrayList<Interval> ans = new ArrayList<Interval>();
        int i = 0;
        int n = intervals.size();
        while (i < n && intervals.get(i).end < newInterval.start)
        {
            ans.add(intervals.get(i));
            i++;
        }
        // intervals[i].end >= newInterval.start
        while (i < n && intervals.get(i).start <= newInterval.end)
        {
            newInterval.start = Math.min(newInterval.start, intervals.get(i).start);
            newInterval.end = Math.max(newInterval.end, intervals.get(i).end);
            i++;
        }
        ans.add(newInterval);
        while (i < n)
        {
            ans.add(intervals.get(i));
            i++;
        }
        return ans;
    }
}
public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int start = 0;
        int end = 0;
        int len = gas.length;
        int total = 0;
        boolean valid = false;        
        while (true)
        {
            if (total + gas[end] - cost[end] >= 0)
            {
                total += (gas[end] - cost[end]);
                end = (end + 1) % len;
                valid = true;
                if (start == end) break;
            }
            else
            {
                start = (start + len - 1) % len;
                valid = false;
                if (start == end) break;
                total += (gas[start] - cost[start]);
            }
        }
        if (valid) return start;
        else return -1;
    }
}
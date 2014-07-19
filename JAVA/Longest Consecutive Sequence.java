public class Solution {
    public int longestConsecutive(int[] num) {
        HashMap<Integer, Boolean> map = new HashMap<Integer, Boolean>();
        int max = 0;
        for (int n : num)
        {
            map.put(n, false);
        }
        for (int n: num)
        {
            if (!map.get(n))
            {
                int len1 = getLength(map, n-1, -1);
                int len2 = getLength(map, n+1, 1);
                int len = len1 + len2 + 1;
                if (len > max) max = len;
            }
        }
        return max;
    }
     
    private int getLength(HashMap<Integer, Boolean> map, int n, int step)
    {
        int len = 0;
        while (map.containsKey(n))
        {
            len++;
            map.put(n, true);
            n += step;
        }
        return len;
    }
}
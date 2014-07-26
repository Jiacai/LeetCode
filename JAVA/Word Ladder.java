public class Solution {
    public int ladderLength(String start, String end, HashSet<String> dict) {
        int dist = 1;
        if (start.equals(end)) return dist;
        HashSet<String> added = new HashSet<String>();
        Queue<String> queue = new LinkedList<String>();
        queue.offer(start);
        added.add(start);
        int thisLevel = 1;
        int nextLevel = 0;
        while (queue.size() != 0)
        {
            char[] curr=queue.poll().toCharArray();
            thisLevel--;
            for (int i = 0; i < start.length(); i++)
            {
                char tmp = curr[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (c == tmp) continue;
                    curr[i] = c;
                    String str = new String(curr);
                    if (str.equals(end)) return dist + 1;
                    if (dict.contains(str) && !added.contains(str))
                    {
                        queue.offer(str);
                        added.add(str);
                        nextLevel++;
                    }
                }
                curr[i] = tmp;
            }
            if (thisLevel == 0)
            {
                thisLevel = nextLevel;
                nextLevel = 0;
                dist++;
            }
        }
        return 0;
    }
}
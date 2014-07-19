import java.util.*;
public class Solution {
    private String start;
    private String end;
    private HashSet<String> dict;
    private ArrayList<ArrayList<String>> ans = new ArrayList<ArrayList<String>>();
    private ArrayList<String> words = new ArrayList<String>();
    public ArrayList<ArrayList<String>> findLadders(String start, String end, HashSet<String> dict) {
        ans.clear();
        words.clear();
        this.start = start;
        this.end = end;
        this.dict = dict;
        // wrong, start could be end
        dict.add(start);
        dict.add(end);
        for (String s : dict)
        {
            words.add(s);
        }
        // build adjacent list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
        HashMap<String, Integer> ids = new HashMap<String, Integer>(); // the map from word to its id in array words
        for (int i = 0; i < words.size(); i++)
        {
            ids.put(words.get(i), i);
            adj.add(new ArrayList<Integer>());
        }
        this.buildGraph(adj, ids);
        // find the start and end index
        int vs = 0;
        for (; !words.get(vs).equals(start); vs++);
        int ve = 0;
        for (; !words.get(ve).equals(end); ve++);
        // find the paths
        Queue<Integer> que = new LinkedList<Integer>();
        int[] dist = new int[dict.size()]; // distance, distance[vs] = 0;
        for (int i = 0; i < dist.length; i++)
        {
            dist[i] = -1;
        }
        dist[vs] = 0;
        ArrayList<ArrayList<Integer>> prev = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < dict.size(); i++)
        {
            prev.add(new ArrayList<Integer>());
        }
        for (int i : adj.get(vs))
        {
            que.offer(i);
            dist[i] = 1;
            prev.get(i).add(vs);
        }
        while (que.size() != 0)
        {
            int idx = que.poll();
            if (idx == ve) break; // the prev[ve] is already processed in previous iteration
            int d = dist[idx] + 1;
            for (int i : adj.get(idx))
            {
                if (prev.get(i).size() == 0 && i != vs) // not visited
                {
                    que.offer(i);
                    prev.get(i).add(idx);
                    dist[i] = d;
                }
                else if (dist[i] == d) // already visited, dist[i] should be <= d
                {
                    prev.get(i).add(idx);
                }
            }
        }
        // generate the paths
        ArrayList<Integer> path = new ArrayList<Integer>();
        genPath(prev, path, vs, ve);
        return ans;
    }
     
    private void genPath(ArrayList<ArrayList<Integer>> prev, ArrayList<Integer> path, int vs, int ve)
    {
        path.add(ve);
        if (ve == vs)
        {
            ArrayList<String> tmp = new ArrayList<String>();
            for (int i = path.size()-1; i >=0; i--)
            {
                tmp.add(words.get(path.get(i)));
            }
            ans.add(tmp);
        }
        else
        {
            for (int i : prev.get(ve))
            {
                genPath(prev, path, vs, i);
            }
        }
        path.remove(path.size()-1);
    }
     
    private void buildGraph(ArrayList<ArrayList<Integer>> adj, HashMap<String, Integer> ids)
    {
        for (int i = 0; i < words.size(); i++)
        {
            char[] ca = words.get(i).toCharArray();
            for (int j = 0; j < words.get(0).length(); j++)
            {
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (ca[j] == c) continue;
                    char tmp = ca[j];
                    ca[j] = c;
                    String s = new String(ca);
                    if (dict.contains(s))
                    {
                        adj.get(i).add(ids.get(s));
                    }
                    ca[j] = tmp;
                }
            }
        }
    }
}
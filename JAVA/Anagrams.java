public class Solution {
    public ArrayList<String> anagrams(String[] strs) {
        ArrayList<String> ans = new ArrayList<String>();
        HashMap<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();
        for (int i = 0; i < strs.length; i++)
        {
            char[] chars = strs[i].toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);
            if (map.containsKey(key))
            {
                map.get(key).add(strs[i]);
            }
            else
            {
                ArrayList<String> list = new ArrayList<String>();
                list.add(strs[i]);
                map.put(key, list);
            }
        }
        for (String s : map.keySet())
        {
            if (map.get(s).size() > 1)
            {
                ans.addAll(map.get(s));
            }
        }
        return ans;
    }
}
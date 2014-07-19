import java.util.*;
public class Solution {
    public String getPermutation(int n, int k) {
        k--; // start from index 0
        ArrayList<Integer> arr = new ArrayList<Integer>();
        ArrayList<Integer> pos = new ArrayList<Integer>();
        for (int i = 1; i <= n; i++)
        {
            arr.add(i);
        }
        int factor = 1;
        for (int i = 1; i < n; i++)
        {
            factor *= i;
        }
        for (int i = n-1; i >= 1; i--)
        {
            pos.add(k / factor);
            k = k % factor;
            factor /= i;
        }
        pos.add(0);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < pos.size(); i++)
        {
            int p = pos.get(i);
            sb.append(arr.get(p));
            arr.remove(p);
        }
        return sb.toString();
    }
}
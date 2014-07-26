public class Solution {
    public ArrayList<ArrayList<Integer>> generate(int numRows) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        if (numRows == 0) return ans;
        ArrayList<Integer> tmp = new ArrayList<Integer>();
        tmp.add(1);
        ans.add(tmp);
        if (numRows == 1) {
            return ans;
        }
        tmp = new ArrayList<Integer>();
        tmp.add(1);
        tmp.add(1);
        ans.add(tmp);
        if (numRows == 2) {
            return ans;
        }
        for (int i = 2; i < numRows; i++) {
            tmp = new ArrayList<Integer>();
            ArrayList<Integer> last = ans.get(i-1);
            tmp.add(1);
            int half = i / 2;
            for (int j = 1; j <= half; j++) {
                tmp.add(last.get(j-1) + last.get(j));
            }
            for (int j = half+1; j <= i; j++) {
                tmp.add(tmp.get(i-j));
            }
            ans.add(tmp);
        }
        return ans;        
    }
}
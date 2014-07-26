public class Solution {
    public ArrayList<Integer> spiralOrder(int[][] matrix) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        int m = matrix.length;
        if (m == 0) return ans;
        int n = matrix[0].length;
        if (n == 0) return ans;
        int m_low = 0;
        int m_high = m-1;
        int n_low = 0;
        int n_high = n-1;
        int count = m*n;
        while (count > 0) {
            for (int i = n_low; i <= n_high && count > 0; i++) {
                ans.add(matrix[m_low][i]);
                count--;
            }
            m_low++;
            for (int i = m_low; i <= m_high && count > 0; i++) {
                ans.add(matrix[i][n_high]);
                count--;
            }
            n_high--;
            for (int i = n_high; i >= n_low && count > 0; i--) {
                ans.add(matrix[m_high][i]);
                count--;
            }
            m_high--;
            for (int i = m_high; i >= m_low && count > 0; i--) {
                ans.add(matrix[i][n_low]);
                count--;
            }
            n_low++;
        }
        return ans;
    }
}
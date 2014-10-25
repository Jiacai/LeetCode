class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        int m = matrix.size();
        if (m == 0) return result;
        int n = matrix[0].size();
        if (n == 0) return result;
        m--;
        int step = n;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int k = 0;
        int x = 0;
        int y = -1;
        while (step != 0) {
            for (int i = 0; i < step; i++) {
                x += dx[k];
                y += dy[k];
                result.push_back(matrix[x][y]);
            }
            if (k % 2 == 0) {
                step = m;
                n--;
            } else {
                step = n;
                m--;
            }
            k = (k + 1) % 4;
        }
        return result;
    }
};

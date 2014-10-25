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
    
    vector<int> spiralOrder_1(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int imin = 0, imax = matrix.size()-1;
        int jmin = 0, jmax = matrix[0].size()-1;
        while (true)
        {
            for (int j = jmin; j <= jmax; ++j) res.push_back(matrix[imin][j]);
            if (++imin > imax) break;
            for (int i = imin; i <= imax; ++i) res.push_back(matrix[i][jmax]);
            if (jmin > --jmax) break;
            for (int j = jmax; j >= jmin; --j) res.push_back(matrix[imax][j]);
            if (imin > --imax) break;
            for (int i = imax; i >= imin; --i) res.push_back(matrix[i][jmin]);
            if (++jmin > jmax) break;
        }
        return res;
    }
};

enum Direction { LEFT, RIGHT, UP, DOWN };

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n));
        int m = n * n; int num = 1;
        int imin = 0; int imax = n - 1; int jmin = 0; int jmax = n - 1;
        Direction dir = RIGHT;
        while (num <= m) {
            switch (dir) {
            case RIGHT:
                for (int j = jmin; j <= jmax; j++)
                    result[imin][j] = num++;
                imin++; dir = DOWN;
                break;
            case DOWN:
                for (int i = imin; i <= imax; i++)
                    result[i][jmax] = num++;
                jmax--; dir = LEFT;
                break;
            case LEFT:
                for (int j = jmax; j >= jmin; j--)
                    result[imax][j] = num++;
                imax--; dir = UP;
                break;
            case UP:
                for (int i = imax; i >= imin; i--)
                    result[i][jmin] = num++;
                jmin++; dir = RIGHT;
                break;
            }
        }
        return result;
    }
};

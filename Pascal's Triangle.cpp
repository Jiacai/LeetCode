class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        for (int i = 0; i < numRows; i++) {
            vector<int> vec;
            vec.resize(i + 1);
            vec[0] = 1;
            vec[i] = 1;
            for (int j = 1; j < i; j++) {
                vec[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(vec);
        }
        return result;
    }
};

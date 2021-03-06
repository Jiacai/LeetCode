class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> current(rowIndex + 1, 1);
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = i - 1; j >= 1; j--) {
                current[j] += current[j - 1];
            }
        }
        return current;
    }
};

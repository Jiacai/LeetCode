class Solution {
public:
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> result;
        int prev = lower - 1;
        for (int i = 0; i < n; i++) {
            checkNum(A[i], prev, result);
        }
        // upper
        checkNum(upper + 1, prev, result);
        return result;
    }
    
    void checkNum(int num, int &prev, vector<string> &result) {
        if (num != prev && num != prev + 1) {
            string tmp;
            if (num == prev + 2) {
                tmp = to_string(num - 1);
            } else {
                tmp += to_string(prev + 1);
                tmp += "->";
                tmp += to_string(num - 1);
            }
            result.push_back(tmp);
        }
        prev = num;
    }
};

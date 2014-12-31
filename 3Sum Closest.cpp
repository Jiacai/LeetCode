class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int size = num.size();
        int diff = INT_MAX;
        int result = 0;
        for (int i = 0; i < size - 2; i++) {
            int j = i + 1;
            int k = size - 1;
            int sum = target - num[i];
            while (j < k) {
                int tmp = num[j] + num[k];
                if (tmp == sum) {
                    return target;
                } else {
                    int tmp_diff = abs(tmp - sum);
                    if (tmp_diff < diff) {
                        result = num[i] + tmp;
                        diff = tmp_diff;
                    }
                    if (tmp < sum) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }
        return result;
    }
};

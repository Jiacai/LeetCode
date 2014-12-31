class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int size = num.size();
        int diff = INT_MAX;
        int result = num[0] + num[1] + num[2];
        for (int i = 0; i < size - 2; i++) {
            int j = i + 1;
            int k = size - 1;
            while (j < k) {
                int threesum = num[i] + num[j] + num[k];
                if (threesum == target) {
                    return target;
                } else if (threesum < target) {
                        j++;
                } else {
                    k--;
                }
                if (abs(threesum - target) < abs(result - target)) {
                    result = threesum;
                }
            }
        }
        return result;
    }
};

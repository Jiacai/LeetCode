class Solution {
public:
    vector<int> twoSum(vector<int> &num, int target) {
        vector<int> result;
        int l = 0;
        int r = num.size() - 1;
        while (l < r) {
            int sum = num[l] + num[r];
            if (sum == target) {
                result.push_back(l + 1);
                result.push_back(r + 1);
                return result;
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
    }
};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            if (i > 0 && num[i] == num[i-1]) continue;
            for (int j = i + 1; j < num.size(); j++) {
                if (j > i + 1 && num[j] == num[j-1]) continue;
                int twoSum = target - num[i] - num[j];
                int l = j + 1; int r = num.size() - 1;
                while (l < r) {
                    int sum = num[l] + num[r];
                    if (sum == twoSum) {
                        vector<int> quadruplet(4);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[l];
                        quadruplet[3] = num[r];
                        result.push_back(quadruplet);
                        while (l < r && num[l] == num[l+1]) l++;
                        while (l < r && num[r] == num[r-1]) r--;
                        l++; r--;
                    } else if (sum < twoSum) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return result;
    }
};

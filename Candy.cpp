class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        vector<int> candies(size);
        for (int i = 0; i < size; i++) {
            if (i == 0 || ratings[i] <= ratings[i-1]) {
                candies[i] = 1;
            } else {
                candies[i] = candies[i-1] + 1;
            }
        }
        int cur = 1;
        int result = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (i == size - 1 || ratings[i] <= ratings[i + 1]) {
                cur = 1;
            } else {
                cur = cur + 1;
            }
            candies[i] = max(candies[i], cur);
            result += candies[i];
        }
        return result;
    }
};

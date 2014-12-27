class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
        assert(size >= 2);
        int i = 0;
        int j = size - 1;
        int result = min(height[i], height[j]) * (j - i);
        while (i < j) {
            if (height[i] < height[j]) {
                i++;
                result = max(result, min(height[i], height[j]) * (j - i));
            } else {
                j--;
                result = max(result, min(height[i], height[j]) * (j - i));
            }
        }
        return result;
    }
};

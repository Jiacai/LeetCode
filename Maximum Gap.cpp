class Solution {
public:
    int maximumGap(vector<int> &num) {
        int size = num.size();
        if (size < 2) {
            return 0;
        }
        int maxVal = *max_element(num.begin(), num.end());
        int minVal = *min_element(num.begin(), num.end());
        int gap = (maxVal - minVal - 1) / (size - 1) + 1; // ceiling function
        int bucketSize = (maxVal - minVal) / gap;
        vector<int> minBucket(bucketSize, INT_MAX);
        vector<int> maxBucket(bucketSize, INT_MIN);
        for (int i = 0; i < size; i++) {
            if (num[i] == minVal || num[i] == maxVal) {
                continue;
            }
            int idx = (num[i] - minVal) / gap;
            minBucket[idx] = min(minBucket[idx], num[i]);
            maxBucket[idx] = max(maxBucket[idx], num[i]);
        }
        int maxGap = INT_MIN;
        int prev = minVal;
        for (int i = 0; i < bucketSize; i++) {
            if (minBucket[i] != INT_MAX) {
                maxGap = max(maxGap, minBucket[i] - prev);
                prev = maxBucket[i];
            }
        }
        maxGap = max(maxGap, maxVal - prev);
        return maxGap;
    }
};

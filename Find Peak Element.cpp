class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int size = num.size();
        int left = 0;
        int right = size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if ((mid == 0 || num[mid] > num[mid-1]) &&
                (mid == size - 1 || num[mid] > num[mid+1])) {
                return mid;
            }
            if (mid != 0 && num[mid] < num[mid-1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

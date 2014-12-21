class Solution {
public:
    int findMin(vector<int> &num) {
        int size = num.size();
        int minVal = num[size-1];
        findMinRe(num, 0, size - 1, minVal);
        return minVal;
    }
    
    void findMinRe(vector<int> &num, int left, int right, int &minVal) {
        if (right < left) return;
        int mid = (left + right) / 2;
        if (num[left] < num[right]) {
            minVal = min(minVal, num[left]);
            return;
        }
        if (num[left] > num[right]) {
            minVal = min(minVal, num[right]);
            if (num[mid] <= num[right]) {
                minVal = min(minVal, num[mid]);
                findMinRe(num, left, mid - 1, minVal);
            } else {
                findMinRe(num, mid + 1, right, minVal);
            }
        }
        if (num[left] == num[right]) {
            minVal = min(num[left], minVal);
            if (num[mid] < num[right]) {
                minVal = min(minVal, num[mid]);
                findMinRe(num, left, mid - 1, minVal);
            } else if (num[mid] > num[right]) {
                findMinRe(num, mid + 1, right, minVal);
            } else { // ==
                findMinRe(num, left, mid - 1, minVal);
                findMinRe(num, mid + 1, right, minVal);
            }
        }
    }
};

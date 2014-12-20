class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2);
        int left = findLeft(A, n, target);
        int right = findRight(A, n, target);
        if (left > right) {
            result[0] = result[1] = -1;
        } else {
            result[0] = left;
            result[1] = right;
        }
        return result;
    }
    
    int findRight(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
    
    int findLeft(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right + 1;
    }
};

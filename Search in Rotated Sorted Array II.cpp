class Solution {
public:
    bool search(int A[], int n, int target) {
        return searchRe(A, 0, n - 1, target);
    }
    
    bool searchRe(int A[], int left, int right, int target) {
        if (left > right) {
            return false;
        }
        int mid = (left + right) / 2;
        if (A[mid] == target) {
            return true;
        }
        if (A[mid] > A[left]) {
            if (A[mid] > target && A[left] <= target) {
                return searchRe(A, left, mid - 1, target);
            } else {
                return searchRe(A, mid + 1, right, target);
            }
        } else if (A[mid] < A[left]) {
            if (A[right] >= target && A[mid] < target) {
                return searchRe(A, mid + 1, right, target);
            } else {
                return searchRe(A, left, mid - 1, target);
            }
        } else { // A[mid] == A[left]
            if (A[mid] == A[right]) { // this is the only case that gap between left-mid possible
                return searchRe(A, left, mid - 1, target) || searchRe(A, mid + 1, right, target);
            } else {
                // the same value from left to mid
                return searchRe(A, mid + 1, right, target);
            }
        }
        return false;
    }
};

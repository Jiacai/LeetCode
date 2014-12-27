class Solution {
public:
    int search(int A[], int n, int target) {
        return searchRe(A, 0, n - 1, target);
    }
    
    int searchRe(int A[], int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        if (A[mid] == target) {
            return mid;
        }
        if (A[left] < A[right]) {
            if (A[mid] < target) {
                return searchRe(A, mid + 1, right, target);
            } else {
                return searchRe(A, left, mid - 1, target);
            }    
        } else {
            return max(searchRe(A, left, mid - 1, target), searchRe(A, mid + 1, right, target));
        }
    }
};

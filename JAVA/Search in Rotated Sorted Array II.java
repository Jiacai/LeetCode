public class Solution {
    public boolean search(int[] A, int target) {
        return search(A, target, 0, A.length-1);
    }
     
    private boolean search(int[] A, int target, int left, int right)
    {
        if( left > right) return false;
        if (left == right) return (A[left] == target);
        if (A[left] < A[right] && (target < A[left] || target > A[right])) return false;
        if (A[left] > A[right] && target > A[right] && target < A[left]) return false;
        int mid = left + (right - left) / 2;
        if (A[mid] == target) return true;
        else
        {
            return search(A, target, left, mid-1) || search(A, target, mid+1, right);
        }
    }
}
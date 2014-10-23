class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int i = m - 1;
		int j = n - 1;
		while (i >= 0 || j >= 0) {
			if (i >= 0 && j >= 0) {
				if (A[i] >= B[j]) {
					A[i + j + 1] = A[i];
					i--;
				} else {
					A[i + j + 1] = B[j];
					j--;
				}
			} else if (i < 0) {
				A[j] = B[j]; 
				j--;
			} else if (j < 0) {
				break;
			}
		}
	}
};

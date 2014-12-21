class Solution {
public:
    /*
    test: [1]
    test: [2, 1]
    test: [3, 1, 2]
    test: [2, 3, 1]
    test: [3, 4, 1, 2]
    test: [3, 4, 5, 1, 2]
    */
    int findMin(vector<int> &num) {
        int size = num.size();
        int min = num[size-1];
        int left = 0;
        int right = size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (((mid - 1 >= 0 && num[mid] < num[mid-1]) || (mid == 0)) &&
                ((mid + 1 < size && num[mid] < num[mid+1]) || (mid == size - 1))) {
                return num[mid];
            }
            if (num[mid] > min) { 
                left = mid + 1;
            } else {
                right = mid - 1;
                min = num[mid];
            }        
        }
    }
};

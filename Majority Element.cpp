class Solution {
public:
    int majorityElement(vector<int> &num) {
        int size = num.size();
        int major = 0;
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (count == 0) {
                major = num[i];
                count++;
            } else if (num[i] == major) {
                count++;
            } else {
                count--;
            }
        }
        return major;
    }
};

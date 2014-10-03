class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int N = num.size();
        for (int i = 0; i < N; i++)
        {
            if (i != 0 && num[i] == num[i - 1])
                continue;
            int left = i + 1;
            int right = N - 1;
            while (left < right)
            {
                if (num[left] + num[right] == -num[i])
                {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[left]);
                    tmp.push_back(num[right]);
                    result.push_back(tmp);
                    left++;
                    right--;
                    while (left < right && num[left] == num[left - 1]) left++;
                    while (left < right && num[right] == num[right + 1]) right--;
 
                }
                else if (num[left] + num[right] < -num[i])
                {
                    left++;
                    while (left < right && num[left] == num[left - 1]) left++;
                }
                else
                {
                    right--;
                    while (left < right && num[right] == num[right + 1]) right--;
                }
            }
        }
        return result;
    }
};

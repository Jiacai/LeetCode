class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        for (int i = 1; i <= n; i++)
        {
            factorial *= i;
        }
         
        string result;
        result.resize(n);
        for (int i = 0; i < n; i++)
        {
            result[i] = i + '1';
        }
         
        k--;
        for (int i = 0; i < n; i++)
        {
            factorial /= (n - i);
            int idx = k / factorial;
            for (int j = i + idx; j < n && j > i; j--)
            {
                swap(result[j], result[j-1]);
            }
            k %= factorial;
        }
        return result;
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<char> ans(num1.size() + num2.size());
        for (int i = 0; i < num1.size(); i++)
        {
            for (int j = 0; j < num2.size(); j++)
            {
                ans[i+j] += (num1[i] - '0') * (num2[j] - '0');
                ans[i+j+1] += ans[i+j] / 10;
                ans[i+j] = ans[i+j] % 10;
            }
        }
        string s;
        bool nonzero = false;
        for (int i = ans.size()-1; i >= 0; i--)
        {
            if (!nonzero && ans[i] == 0)
                continue;
            nonzero = true;
            s.push_back((char) (ans[i]+'0'));
        }
        if (s == "") return "0";
        return s;
    }
};

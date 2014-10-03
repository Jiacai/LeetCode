class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if (!wordBreakPossible(s, dict)) return res;
         
        wordBreakRe(s, dict, 0, res, "");
        return res;
    }
 
    void wordBreakRe(string &s, unordered_set<string> &dict, int idx,
        vector<string> &result, string tmp)
    {
        if (idx == s.size())
        {
            result.push_back(tmp);
            return;
        }
        if (idx != 0) tmp.push_back(' ');
        for (int i = idx; i < s.size(); i++)
        {
            string sub = s.substr(idx, i - idx + 1);
            if (dict.find(sub) != dict.end())
            {
                wordBreakRe(s, dict, i + 1, result, tmp+sub);
            }
        }
    }
     
    bool wordBreakPossible(const string &s, const unordered_set<string> &dict) {
        int N = s.size();
        vector<bool> possible;
        possible.resize(N + 1);
         
        possible[0] = true; // s with len == 0
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                string sub = s.substr(j, i - j);
                if (possible[j] && dict.find(sub) != dict.end())
                {
                    possible[i] = true;
                }
            }
        }
        return possible[N];
    }
};

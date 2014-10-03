class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<int> > canBreak; // 0 for unvisited, 1 for true, -1 for false
        int N = s.size();
        canBreak.resize(N);
        for (int i = 0; i < N; i++)
        {
            canBreak[i].resize(N);
        }
        return wordBreakRe(s, dict, canBreak, 0, N - 1);
    }
     
    bool wordBreakRe(string &s, unordered_set<string> &dict, vector<vector<int> > &canBreak, int start, int end)
    {
        if (canBreak[start][end] != 0)
            return (canBreak[start][end] == 1 ? true : false);
        string sub = s.substr(start, end - start + 1);
        if (dict.find(sub) != dict.end())
        {
            canBreak[start][end] = 1;
            return true;
        }
        for (int i = start; i < end; i++)
        {
            if (wordBreakRe(s, dict, canBreak, start, i) && 
                wordBreakRe(s, dict, canBreak, i + 1, end))
            {
                canBreak[start][end] = 1;
                return true;
            }
        }
        canBreak[start][end] = -1;
        return false;
    }
};

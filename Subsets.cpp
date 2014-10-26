class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> result;
        vector<int> current;
        sort(S.begin(), S.end());
        subsetsRe(S, result, current, 0);
        return result;
    }
    
    void subsetsRe(vector<int> &S, vector<vector<int>> &result, vector<int> &current, int index) {
        result.push_back(current);
        if (index == S.size())
            return;
        for (int i = index; i < S.size(); i++) {
            current.push_back(S[i]);
            subsetsRe(S, result, current, i+1);
            current.pop_back();
        }
    }
};

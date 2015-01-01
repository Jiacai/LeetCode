class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> result;
        vector<bool> current;
        subsetsWithDupRe(result, current, S);
        return result;
    }
    
    void subsetsWithDupRe(vector<vector<int>> &result, vector<bool> &current, vector<int> &S) {
        int i = current.size();
        if (i == S.size()) {
            vector<int> tmp;
            for (int k = 0; k< current.size(); k++) {
                if (current[k]) {
                    tmp.push_back(S[k]);
                }
            }
            result.push_back(tmp);
            return;
        }
        if (i == 0 || S[i] != S[i-1] || current[i-1] == true) {
            current.push_back(true);
            subsetsWithDupRe(result, current, S);
            current.pop_back();
        }
        current.push_back(false);
        subsetsWithDupRe(result, current, S);
        current.pop_back();
    }
    
    vector<vector<int> > subsetsWithDup_1(vector<int> &S) {
        vector<vector<int>> res;
        sort(S.begin(), S.end());
        vector<int> path;
        dfs(S,res,path,0);
        return res;
    }
    void dfs(vector<int> &S, vector<vector<int>>& res, vector<int>&path, size_t step) {
        res.push_back(path);
        for (int i = step; i < S.size(); ++i) {
            if(i!=step&&S[i]==S[i-1]) continue;
            path.push_back(S[i]);
            dfs(S,res,path,i+1);
            path.pop_back();
        }
    }
};

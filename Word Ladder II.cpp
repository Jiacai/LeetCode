class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, unordered_set<string>> traces;
        vector<unordered_set<string>> level(2);
        int cur = 0;
        int prev = 1;
        level[cur].insert(start);
        
        while (true) {
            level[prev].clear();
            cur = !cur;
            prev = !prev;
            for (auto iter = level[prev].begin(); iter != level[prev].end(); iter++) {
                dict.erase(*iter);
            }
            for (auto iter = level[prev].begin(); iter != level[prev].end(); iter++) {
                string s = *iter;
                for (int i = 0; i < s.size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        s[i] = c;
                        if (dict.find(s) != dict.end()) {
                            traces[s].insert(*iter);
                            level[cur].insert(s);
                        }
                    }
                    s = *iter;
                }
            }
            if (level[cur].empty() || level[cur].find(end) != level[cur].end())
                break;
        }
        
        vector<vector<string>> result;
        vector<string> path;
        
        buildResult(result, traces, start, path, end);
        return result;
    }
    
    void buildResult(vector<vector<string>> &result, unordered_map<string, unordered_set<string>> &traces,
                    string& start, vector<string> &path, string word) {
        if (word == start) {
            vector<string> copy(path);
            copy.push_back(word);
            reverse(copy.begin(), copy.end());
            result.push_back(copy);
            return;
        }
        
        const unordered_set<string> &s = traces[word];
        path.push_back(word);
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            buildResult(result, traces, start, path, *iter);
        }
        path.pop_back();
    }
};

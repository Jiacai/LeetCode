class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<int>> map;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push_back(i);
        }
        vector<string> result;
        for (auto iter = map.begin(); iter != map.end(); iter++) {
            if (iter->second.size() > 1) {
                for (int i = 0; i < iter->second.size(); i++) {
                    result.push_back(strs[iter->second[i]]);
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        if (S.empty() || L.empty()) return result;
        unordered_map<string, int> need;
        for (int i = 0; i < L.size(); i++) {
            need[L[i]]++;
        }
        int len = L[0].size();
        int totalSize = len * L.size();
        for (int k = 0; k < len; k++) {
            unordered_map<string, int> found;
            int count = 0;
            int i = k;
            while (i + len <= S.size()) {
                if (i >= k + totalSize) {
                    string last = S.substr(i - totalSize, len);
                    if (found.find(last) != found.end()) {
                        found[last]--;
                        if (found[last] < need[last]) {
                            count--;
                        }
                    }
                }
                string s = S.substr(i, len);
                if (need.find(s) != need.end()) {
                    found[s]++;
                    if (found[s] <= need[s]) {
                        count++;
                    }
                }
                if (count == L.size()) {
                    result.push_back(i - len * (L.size() - 1));
                }
                i += len;
            }
        }
        return result;
    }
};

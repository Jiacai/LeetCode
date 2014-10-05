class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s;
        int result = 0;
        for (int i = 0; i < num.size(); i++) {
            s.insert(num[i]);
        }
            
        for (int i = 0; i < num.size() && !s.empty(); i++) {
            if (s.find(num[i]) == s.end())
                continue;
            int lower = num[i];
            int upper = num[i];
            while (s.find(--lower) != s.end()) {
                s.erase(lower);    
            }
            while (s.find(++upper) != s.end()) {
                s.erase(upper);
            };
            result = max(upper - lower - 1, result);
        }
        return result;
    }
};

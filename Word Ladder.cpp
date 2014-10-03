class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end)
            return 1;
        unordered_set<string> used;
        queue<string> q;
        q.push(start);
        used.insert(start);
        int thisLevel = 1;
        int nextLevel = 0;
        int level = 1;
        while(not q.empty()) {
            while (thisLevel--) {
                string s = q.front();
                q.pop();
                string original = s;
                for (int i = 0; i < s.size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original[i]) {
                            continue;
                        }
                        s[i] = c;
                        if (s == end) {
                            return (level + 1);
                        } else if (dict.find(s) != dict.end() 
                                && used.find(s) == used.end()) {
                            q.push(s);
                            used.insert(s);
                            nextLevel++;
                        }
                    }
                    s = original;
                }
            }
            thisLevel = nextLevel;
            nextLevel = 0;
            level++;
        }
        return 0;
    }
};

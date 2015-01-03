/*
Solution _1: two pointers
*/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int result = 0;
        unordered_map<char, int> map;
        int i = 0;
        int start = 0;
        while (i < s.size()) {
            if (map.find(s[i]) != map.end()) {
                map[s[i]] = i;
                result = max(result, i - start + 1);
                i++;
            } else if (map.size() <= 1) {
                map[s[i]] = i;
            } else {
                char c;
                int tmp = s.size();
                for (auto it = map.begin(); it != map.end(); it++) {
                    if (it->second < tmp) {
                        c = it->first;
                        tmp = it->second;
                    }
                }
                map.erase(c);
                map[s[i]] = i;
                start = tmp + 1;
            }
        }
        return result;
    }
    
    int lengthOfLongestSubstringTwoDistinct_1(string s) {
        int start = 0, cnt = 0;
        int char_set[256] = {0};
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (char_set[s[i]]++ == 0) cnt++;
            while (cnt > 2) {
                char_set[s[start]]--;
                if (char_set[s[start++]] == 0) cnt--;
            }
            ans = max(i - start + 1, ans);
        }
    }
};

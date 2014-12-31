class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        int len = 0;
        int start = 0;
        for (int i = 0; i <= words.size(); i++) {
            string str;
            int cnt = i - start;
            if (i == words.size()) {
                for (int i = 0; i < cnt - 1; i++) {
                    str += words[start + i];
                    str += string(1, ' ');
                }
                str += words[start+cnt-1];
                int remain = L - len - cnt + 1;
                if (remain > 0) {
                    str += string(remain, ' ');
                }
                result.push_back(str);
            } else if (len + words[i].size() + i - start > L) {
                if (cnt == 1) { // one word
                    str += words[start];
                    if (L - len > 0) {
                        str += string(L - len, ' ');
                    }
                } else {
                    int n = (L - len) / (cnt - 1);
                    int r = (L - len) % (cnt - 1);
                    for (int i = 0; i < cnt - 1; i++) {
                        str += words[start + i];
                        if (i < r) {
                            str += string(n + 1, ' ');
                        } else {
                            str += string(n, ' ');
                        }
                    }
                    str += words[start+cnt-1];
                }
                result.push_back(str);
                len = 0;
                start = i;
            }
            
            if (i != words.size()) {
                len += (words[i].size());
            }
        }
        return result;
    }
};

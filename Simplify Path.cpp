class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        string tmp;
        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (tmp == "." || tmp == "") {
                    // do nothing
                } else if (tmp == "..") {
                    if (!vec.empty()) {
                        vec.pop_back();
                    }
                } else {
                    vec.push_back(tmp);
                }
                tmp.clear();
            } else {
                tmp += path[i];
            }
        }
        if (vec.size() == 0) {
            return "/";
        }
        string result;
        for (int i = 0; i < vec.size(); i++) {
            result += "/";
            result += vec[i];
        }
        return result;
    }
};

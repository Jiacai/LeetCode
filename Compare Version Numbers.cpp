class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = convert(version1);
        vector<int> v2 = convert(version2);
        int size = min(v1.size(), v2.size());
        for (int i = 0; i < size; i++) {
            if (v1[i] < v2[i]) {
                return -1;
            } else if (v1[i] > v2[i]) {
                return 1;
            }
        }
        if (v1.size() > size) return 1;
        if (v2.size() > size) return -1;
        return 0;
    }
    
    vector<int> convert(string &version) {
        vector<int> result;
        int len = version.size();
        int num = 0;
        for (int i = 0; i < len; i++) {
            if (version[i] == '.') {
                result.push_back(num);
                num = 0;
            } else {
                num = num * 10 + (version[i] - '0');
            }
        }
        result.push_back(num);
        while (result.back() == 0) {
            result.pop_back();
        }
        return result;
    }
};

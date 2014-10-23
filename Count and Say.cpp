#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            s = next(s);
        }
        return s;
    }
    
    string next(string s) {
        string result;
        stringstream ss;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                count++;
            } else if (i != 0 && s[i-1] == s[i]) {
                count++;
            } else {
                ss << count << s[i-1];
                count = 1;
            }
        }
        ss << count << s[s.size()-1];
        ss >> result;
        return result;
    }
};

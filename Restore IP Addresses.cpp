class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    vector<string> current;
    restoreIpAddressesRe(s, result, current, 0);
    return result;
  }

  void restoreIpAddressesRe(string &s, vector<string> &result, vector<string> &current, int start) {
    if (start == s.size() && current.size() == 4) {
      string ip;
      for (int i = 0; i < current.size(); i++) {
        ip += current[i];
        ip += ".";
      }
      ip.pop_back();
      result.push_back(ip);
      return;
    } else if (current.size() == 4) {
      return;
    }
    for (int len = 1; len <= 3; len++) {
      if (start + len > s.size()) {
        continue;
      }
      string tmp = s.substr(start, len);
      if ((len >= 2 && tmp[0] == '0') || (len == 3 && tmp > "255")) {
          continue;
      } else {
        current.push_back(tmp);
        restoreIpAddressesRe(s, result, current, start + len);
        current.pop_back();
      }
    }
  }
};

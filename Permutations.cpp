class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        int size = num.size();
        vector<bool> visited(size);
        vector<int> current;
        vector<vector<int>> result;
        permuteRe(num, visited, current, result);
        return result;
    }
    
    void permuteRe(vector<int> &num, vector<bool> & visited, vector<int> &current, vector<vector<int>> &result) {
        if (current.size() == num.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                current.push_back(num[i]);
                permuteRe(num, visited, current, result);
                current.pop_back();
                visited[i] = false;
            }
        }
    }
};

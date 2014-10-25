class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        combinationSum2Re(candidates, target, 0, result, current, 0);
        return result;
    }
    
    void combinationSum2Re(vector<int> &candidates, int target, int index, vector<vector<int>> &result, vector<int> &current, int currentSum) {
        if (currentSum == target) {
            result.push_back(current);
            return;
        }
        if (currentSum > target) {
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i != index && candidates[i] == candidates[i - 1])
                continue;
            current.push_back(candidates[i]);
            combinationSum2Re(candidates, target, i + 1, result, current, currentSum + candidates[i]);
            current.pop_back();
        }
    }
};

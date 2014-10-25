class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        combinationSumRe(candidates, target, 0, result, current, 0);
        return result;
    }
    
    void combinationSumRe(vector<int> &candidates, int target, int index, vector<vector<int>> &result, vector<int> &current, int currentSum) {
        if (currentSum == target) {
            result.push_back(current);
            return;
        }
        if (currentSum > target) {
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            combinationSumRe(candidates, target, i, result, current, currentSum + candidates[i]);
            current.pop_back();
        }
    }
};

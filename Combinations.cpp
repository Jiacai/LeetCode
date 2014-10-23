class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
        vector<int> oneCombination;
		vector<int> num;
		for (int i = 1; i <= n; i++) {
			num.push_back(i);
		}
		combineRe(result, num, oneCombination, 0, 0, k);
		return result;
    }
    
    void combineRe(vector<vector<int> > &result, vector<int> &num, vector<int> &oneCombination, int depth, int start, int k) {
        if (depth == k) {
			result.push_back(oneCombination);
			return;
		}
		for (int i = start; i < num.size(); i++) {
			if (num[i] > 0) {
				oneCombination.push_back(num[i]);
				num[i] = -num[i];
				combineRe(result, num, oneCombination, depth + 1, i + 1, k);
				num[i] = -num[i];
				oneCombination.pop_back();
			}
		}
    }
};
